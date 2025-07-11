

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"



/* MCAL includes. */
#include "uart0.h"
#include "gpio.h"
#include "GPTM.h"
#include "ADC/ADC.h"


/* Interrupts */
#include "ISR/isr.h"

/* The HW setup function */
static void prvSetupHardware( void );

/* Task Handles */
TaskHandle_t xHeaterOnOffHandle     = NULL;
TaskHandle_t xTempSetterHandle      = NULL;
TaskHandle_t xTempReaderHandle      = NULL;
TaskHandle_t xHeatControlHandle     = NULL;
TaskHandle_t xDisplayHandle         = NULL;
TaskHandle_t xDiagnosticHandle      = NULL;


/* FreeRTOS tasks */
void vHeaterOnOff(void *pvParameters);
void vTempSetterTask(void *pvParameters);
void vTempReaderTask(void *pvParameters);
void vHeatControlTask(void *pvParameters);
void vDisplayTask(void *pvParameters);
void vDiagnosticTask(void *pvParameters);

/* Definitions for the event bits in the event group. */
#define LowTempBit ( 1UL << 0UL )  /* Event bit 0 */
#define MedTempBit   ( 1UL << 1UL )  /* Event bit 1 */
#define HighTempBit   ( 1UL << 2UL )  /* Event bit 2 */

/* Resource Management */
SemaphoreHandle_t xButtonSemaphore;
xSemaphoreHandle xMutexCount;
EventGroupHandle_t xTempSetEventGroup; // 35, 30, 25 degrees, Event group for desired temperature setting
QueueHandle_t xCurrentTempQueue; //Sends current temperature to temperature controller task
QueueHandle_t xInvalidTempQueue; //Sends current invalid temperature to temperature controller task


/* Shared Resources */
int count = 0;

/* Unshared Resources */
uint8 desiredTempDisplay = 0;
uint8 currentTempDisplay = 0;
typedef enum {
    NONE,
    MODE_LOW,
    MODE_MEDIUM,
    MODE_HIGH
} Mode;
Mode currentMode = NONE;
sint64 on_off = 0;

int main()
{
    /* Setup the hardware for use with the Tiva C board. */
    prvSetupHardware();


    /* Create Queues Here */
    xButtonSemaphore = xSemaphoreCreateBinary(); // To check the button clicks & change modes
    xMutexCount = xSemaphoreCreateMutex();
    xTempSetEventGroup = xEventGroupCreate(); // To determine intensity required (Low = 25, Med = 30, High = 35)
    xCurrentTempQueue = xQueueCreate(5, sizeof(uint32)); // Sends valid current temperature
    xInvalidTempQueue = xQueueCreate(3, sizeof(uint32)); // Sends invalid current temperature




    /* Create Tasks here */
    xTaskCreate(vHeaterOnOff, "Heater Turn ON/OFF Task", 128, NULL, 4, &xHeaterOnOffHandle);
    xTaskCreate(vTempSetterTask, "TempSetter", 128, NULL, 3, &xTempSetterHandle);
    xTaskCreate(vTempReaderTask, "TempReader", 128, NULL, 3, &xTempReaderHandle); //prio = 3
    xTaskCreate(vHeatControlTask, "HeatControl", 128, NULL, 2, &xHeatControlHandle); //prio = 2
//    xTaskCreate(vDisplayTask, "Display", 256, NULL, 1, &xDisplayHandle); //prio = 1
//    xTaskCreate(vDiagnosticTask, "Diagnostic", 128, NULL, 1, &xDiagnosticHandle); //prio = 3
    vTaskStartScheduler();

    /* Should never reach here!  If you do then there was not enough heap
    available for the idle task to be created. */
    for (;;);

}


static void prvSetupHardware( void )
{
    /* Place here any needed HW initialization such as GPIO, UART, etc.  */
    UART0_Init();
    GPIO_BuiltinButtonsLedsInit();
    ADC0_Init();
    GPTM_WTimer0Init();
    GPIO_SW1EdgeTriggeredInterruptInit();
    GPIO_SW2EdgeTriggeredInterruptInit();
}

void vHeaterOnOff(void *pvParameters)
{
//    int count = 0;
    // Create tasks
//    xTaskCreate(vTempSetterTask, "TempSetter", 128, NULL, 3, &xTempSetterHandle);
//    xTaskCreate(vTempReaderTask, "TempReader", 128, NULL, 3, &xTempReaderHandle); //prio = 3
//    xTaskCreate(vHeatControlTask, "HeatControl", 128, NULL, 2, &xHeatControlHandle); //prio = 2
////    xTaskCreate(vDisplayTask, "Display", 256, NULL, 4, &xDisplayHandle); //prio = 1
//    //xTaskCreate(vDiagnosticTask, "Diagnostic", 128, NULL, 1, &xDiagnosticHandle); //prio = 3

    vTaskSuspend(xTempSetterHandle);
    vTaskSuspend(xTempReaderHandle);
    vTaskSuspend(xHeatControlHandle);
//    vTaskSuspend(xDisplayHandle);
//    vTaskSuspend(xDiagnosticHandle);

    for(;;){
        if (xSemaphoreTake(xButtonSemaphore, portMAX_DELAY) == pdTRUE) {
            if (xSemaphoreTake(xMutexCount, portMAX_DELAY) == pdTRUE) {
                // Debounce delay: ignore any further bounces for 50 ms
                vTaskDelay(pdMS_TO_TICKS(200));

                // Drain any extra bounces that happened during the 50 ms
                while (xSemaphoreTake(xButtonSemaphore, 0) == pdTRUE) { /* nothing */ }
                count++;
                if(count==1 ){
                    UART0_SendString("Turning Heater ON\r\n");
                    // Resume tasks
                    Delay_MS(100);  // Debounce delay
                    vTaskResume(xTempSetterHandle);
                    vTaskResume(xTempReaderHandle); //prio = 3
                    vTaskResume(xHeatControlHandle); //prio = 2
//                    vTaskResume(xDisplayHandle); //prio = 1
//                    vTaskResume(xDiagnosticHandle); //prio = 3
                    xSemaphoreGive(xMutexCount);
                    Delay_MS(100);  // Debounce delay
                    on_off = 1;
//                    UART0_SendInteger(on_off);
                    vTaskSuspend(NULL);  // Suspend self
                }

                else if (count == 5){  // Task only runs if count == 5 OR 1 anyways, no need to check for count value twice
                    UART0_SendString("Turning Heater OFF\n");
                    count =0;
                    // Suspend all other tasks
                    vTaskSuspend(xTempSetterHandle);
                    vTaskSuspend(xTempReaderHandle);
                    vTaskSuspend(xHeatControlHandle);
//                    vTaskSuspend(xDisplayHandle);
//                    vTaskSuspend(xDiagnosticHandle);
                    GPIO_RedLedOff();
                    GPIO_BlueLedOff();
                    GPIO_GreenLedOff();
                    on_off = 0;
                }
                xSemaphoreGive(xMutexCount);
            }
        }
    }
}



void vTempSetterTask(void *pvParameters) {
    for(;;){
        if (count == 4){
            vTaskResume(xHeaterOnOffHandle);
            vTaskSuspend(NULL);
        }
        if ((xSemaphoreTake(xButtonSemaphore, portMAX_DELAY) == pdTRUE)) { // Button event
            if (xSemaphoreTake(xMutexCount, portMAX_DELAY) == pdTRUE) { // Resource protection of count variable
                // Debounce delay: ignore any further bounces for 120 ms
                vTaskDelay(pdMS_TO_TICKS(200));

                // Drain any extra bounces that happened during the 120 ms
                while (xSemaphoreTake(xButtonSemaphore, 0) == pdTRUE) { /* nothing */ }
                count++;
                switch (count){
                    case 2: xEventGroupSetBits(xTempSetEventGroup, LowTempBit);
                    UART0_SendString("25");
                            break;
                    case 3: xEventGroupSetBits(xTempSetEventGroup, MedTempBit);
                    UART0_SendString("30");
                            break;
                    case 4: xEventGroupSetBits(xTempSetEventGroup, HighTempBit);
                    UART0_SendString("35");
                        break;
                    default: break;
                }
                xSemaphoreGive(xMutexCount);
            }
        }
    }
}

void vTempReaderTask(void *pvParameters) {

    TickType_t xLastWakeTime = xTaskGetTickCount();

    for(;;){
//        uint16_t currentTemp = ADC0_Read();
        uint16_t currentTemp = 21;
        if (currentTemp< 40 && currentTemp> 5){
            xQueueSend(xCurrentTempQueue, &currentTemp, portMAX_DELAY);
        }
        else{
            xQueueSend(xInvalidTempQueue, &currentTemp, portMAX_DELAY);
        }
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(100)); // Works periodically every 100ms
    }
}


void vHeatControlTask(void *pvParameters) {
    EventBits_t xEventGroupValue;
    const EventBits_t xBitsToWaitFor = ( LowTempBit | MedTempBit | HighTempBit);
    uint16_t currentTemp = 0;
    uint16_t desiredTemp = 0;
    int16_t tempGap;

    for(;;){
        /* Block to wait for event bits to become set within the event group. */
        xEventGroupValue = xEventGroupWaitBits( xTempSetEventGroup,     /* The event group to read. */
                                                xBitsToWaitFor,  /* Bits to test. */
                                                pdTRUE,          /* Clear bits on exit if the unblock condition is met. */
                                                pdFALSE,         /* Don't Wait for all bits. */
                                                pdMS_TO_TICKS(15000));  /* timeout of 15sec. */


        if (xQueueReceive(xCurrentTempQueue, &currentTemp, portMAX_DELAY) == pdTRUE) {
            currentTempDisplay = currentTemp;
            /* Check which events are set and take an action based on it. */
            if (xEventGroupValue & LowTempBit) // Enable green, and low intensity mode
            {
                desiredTemp = 25;
            }
            else if (xEventGroupValue & MedTempBit)
            {
                desiredTemp = 30;
            }
            else if (xEventGroupValue & HighTempBit)
            {
                desiredTemp = 35;
            }
            else{
                // Code to handle no event
            }

            if (desiredTemp){
                tempGap = desiredTemp - currentTemp;
                desiredTempDisplay = desiredTemp;
            }

            if (tempGap){
                if (tempGap >= 10) { // High intensity heater
                    GPIO_RedLedOff();
                    GPIO_GreenLedOn();
                    GPIO_BlueLedOn();
                    currentMode = MODE_HIGH;
                }
                else if (tempGap > 5) { // Medium heater
                    GPIO_RedLedOff();
                    GPIO_GreenLedOff();
                    GPIO_BlueLedOn();
                    currentMode = MODE_MEDIUM;
                }
                else if (tempGap > 2) { // Low intensity heater
                    GPIO_RedLedOff();
                    GPIO_BlueLedOff();
                    GPIO_GreenLedOn();
                    currentMode = MODE_LOW;
                }
                else if (tempGap < 0) { // Disable heater
                    if (xSemaphoreTake(xMutexCount, portMAX_DELAY) == pdTRUE) { // Resource protection of count variable
                        count = 4;
                        GPIO_RedLedOff();
                        GPIO_BlueLedOff();
                        GPIO_GreenLedOff();
                        vTaskResume(xHeaterOnOffHandle);
                    }
                }
                tempGap = 0;
            }
        }

    }
}

void vDisplayTask(void *pvParameters) {

    TickType_t xLastWakeTime = xTaskGetTickCount();

    for(;;){
        if (on_off){ //on
            if (desiredTempDisplay && currentTempDisplay && currentMode!= NONE){
                UART0_SendString("Heater is ON. \r\n");
                UART0_SendString("Current temperature is: " );
                UART0_SendString(&currentTempDisplay);
                UART0_SendString(".\r\n" );
                UART0_SendString("Current mode is: " );
                switch (currentMode){
                case 1: UART0_SendString("Low Intensity Heating.\r\n" );
                break;
                case 2: UART0_SendString("Medium Intensity Heating.\r\n" );
                break;
                case 3: UART0_SendString("High Intensity Heating.\r\n" );
                break;
                }
                UART0_SendString("Desired temperature to be achieved is: " );
                UART0_SendString(&desiredTempDisplay);
                UART0_SendString(".\r\n" );
            }
        }
        else{
            UART0_SendString("Heater is currently turned OFF. \r\n");
        }
        vTaskDelay(pdMS_TO_TICKS(5000)); // Works periodically every 100ms
    }
}

//
void vDiagnosticTask(void *pvParameters) {
    for(;;){
        UART0_SendString("a7a");
    }
}









