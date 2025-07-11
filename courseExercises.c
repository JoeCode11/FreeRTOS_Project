///* Kernel includes. */
//#include "FreeRTOS.h"
//#include "task.h"
//
///* MCAL includes. */
//#include "gpio.h"
//
//
//#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND 369
//
//void Delay_MS(unsigned long long n)
//{
//    volatile unsigned long long count = 0;
//    while(count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n) );
//}
//
///* The HW setup function */
//static void prvSetupHardware( void );
//
///* FreeRTOS tasks */
//void vPeriodicTask1(void *pvParameters);
//void vPeriodicTask2(void *pvParameters);
//
//int main()
//{
//    /* Setup the hardware for use with the Tiva C board. */
//    prvSetupHardware();
//
//    /* Create Tasks here */
//	xTaskCreate(vPeriodicTask1, /* Pointer to the function that implements the task. */
//	            "Task 1",       /* Text name for the task.  This is to facilitate debugging only. */
//	            256,            /* Stack depth - most small microcontrollers will use much less stack than this. */
//	            NULL,           /* We are not passing a task parameter in this example. */
//	            1,              /* This task will run at priority 1. */
//	            NULL);          /* We are not using the task handle. */
//
//    xTaskCreate(vPeriodicTask2, "Task 2", 256, NULL, 1, NULL);
//
//	/* Now all the tasks have been started - start the scheduler.
//
//	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
//	The processor MUST be in supervisor mode when vTaskStartScheduler is
//	called.  The demo applications included in the FreeRTOS.org download switch
//	to supervisor mode prior to main being called.  If you are not using one of
//	these demo application projects then ensure Supervisor mode is used here. */
//	vTaskStartScheduler();
//
//	/* Should never reach here!  If you do then there was not enough heap
//	available for the idle task to be created. */
//	for (;;);
//
//}
//
//
//static void prvSetupHardware( void )
//{
//	/* Place here any needed HW initialization such as GPIO, UART, etc.  */
//    GPIO_BuiltinButtonsLedsInit();
//}
//
//void vPeriodicTask1(void *pvParameters)
//{
//    for (;;)
//    {
//        GPIO_GreenLedToggle();
//        Delay_MS(1000);
//    }
//}
//
//void vPeriodicTask2(void *pvParameters)
//{
//    for (;;)
//    {
//        Delay_MS(1000);
//        GPIO_RedLedToggle();
//    }
//}
/*-----------------------------------------------------------*/



//
//
///*              Task4               */
//
///* Kernel includes. */
//#include "FreeRTOS.h"
//#include "task.h"
//
///* MCAL includes. */
//#include "gpio.h"
//
//
//#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND 369
//
//void Delay_MS(unsigned long long n)
//{
//    volatile unsigned long long count = 0;
//    while(count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n) );
//}
//
///* The HW setup function */
//static void prvSetupHardware( void );
//
///* FreeRTOS tasks */
//void vPeriodicTask(void *pvParameters);
//
//int main()
//{
//    /* Setup the hardware for use with the Tiva C board. */
//    prvSetupHardware();
//
//    /* Create Tasks here */
//    xTaskCreate(vPeriodicTask, /* Pointer to the function that implements the task. */
//                "Task 1",       /* Text name for the task.  This is to facilitate debugging only. */
//                256,            /* Stack depth - most small microcontrollers will use much less stack than this. */
//                "Task 1 is running\r\n",           /* We are not passing a task parameter in this example. */
//                1,              /* This task will run at priority 1. */
//                NULL);          /* We are not using the task handle. */
//
//    xTaskCreate(vPeriodicTask, "Task 2", 256, "Task 2 is running\r\n", 1, NULL);
//
//    /* Now all the tasks have been started - start the scheduler.*/
//
//
//    vTaskStartScheduler();
//
//    /* Should never reach here!  If you do then there was not enough heap
//    available for the idle task to be created. */
//    for (;;);
//
//}
//
//
//static void prvSetupHardware( void )
//{
//    /* Place here any needed HW initialization such as GPIO, UART, etc.  */
//    UART0_Init();
//}
//
//void vPeriodicTask(void *pvParameters)
//{
//    const uint8_t *message = (const uint8_t *)pvParameters;
//    for (;;)
//    {
//        UART0_SendString(message);
//        //Delay_MS(1000);
//        //vTaskDelay(100);
//        vTaskDelay(pdMS_TO_TICKS(1000));
//    }
//}

/*-----------------------------------------------------------*/

//
//
///*        Task5           */
//
//
///* Kernel includes. */
//#include "FreeRTOS.h"
//#include "task.h"
//
///* MCAL includes. */
//#include "gpio.h"
//
//
//#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND 369
//
//void Delay_MS(unsigned long long n)
//{
//    volatile unsigned long long count = 0;
//    while(count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n) );
//}
//
///* The HW setup function */
//static void prvSetupHardware( void );
//
///* FreeRTOS tasks */
//void vPeriodicTask(void *pvParameters);
//
//int main()
//{
//    /* Setup the hardware for use with the Tiva C board. */
//    prvSetupHardware();
//
//    const char *arr1[] = {"Task1", "Red"};
//    const char *arr2[] = {"Task2", "Green"};
//    /*Few notes:
//     * This declares an array of pointers to const char.
//     * Each element in arr will be a pointer to a constant character array (i.e., a string).
//     * So arr is an array where each element points to a string.
//     * a character variable is one character, so a char having "Task1" produces an array of characters.
//     * Due to having an array of characters, thus arr[0] means Task1, and *arr[0] means "T"
//     * arr[0] is a pointer to the string "Task1". Specifically, arr[0] holds the address of the first character of the string "Task1".
//     * *arr[0] means dereferencing the pointer stored in arr[0].
//     * So *arr[0] gives you the first character of the string "Task1", which is 'T'.*/
//
//    void *pvParameters1 =  (void *)arr1;
//    void *Parameters2 =  (void *)arr2;
//    /* Create Tasks here */
//    xTaskCreate(vPeriodicTask, /* Pointer to the function that implements the task. */
//                "Task 1",       /* Text name for the task.  This is to facilitate debugging only. */
//                256,            /* Stack depth - most small microcontrollers will use much less stack than this. */
//                (void *)arr1,           /* We are not passing a task parameter in this example. */
//                1,              /* This task will run at priority 1. */
//                NULL);          /* We are not using the task handle. */
//
//    xTaskCreate(vPeriodicTask, "Task 2", 256, (void *)arr1, 1, NULL);
//
//    /* Now all the tasks have been started - start the scheduler.*/
//
//
//    vTaskStartScheduler();
//
//    /* Should never reach here!  If you do then there was not enough heap
//    available for the idle task to be created. */
//    for (;;);
//
//}
//
//
//static void prvSetupHardware( void )
//{
//    /* Place here any needed HW initialization such as GPIO, UART, etc.  */
//    UART0_Init();
//}
//
//void vPeriodicTask(void *pvParameters)
//{
//    const char **message = (const char **)pvParameters;
//    for (;;)
//    {
//        UART0_SendString(message[0]);
//        //Delay_MS(1000);
//        //vTaskDelay(100);
//        vTaskDelay(pdMS_TO_TICKS(1000));
//    }
//}
//






/* Exercise 17*/
//
///* Kernel includes. */
//#include "FreeRTOS.h"
//#include "task.h"
//
///* MCAL includes. */
//#include "gpio.h"
//#include "uart0.h"
//
///* The HW setup function */
//static void prvSetupHardware( void );
//
//
//TaskHandle_t xTaskRedHandle;
//TaskHandle_t xTaskGreenHandle;
///* FreeRTOS tasks */
//void vSyncTask(void *pvParameters);
//void vTaskRed(void *pvParameters);
//void vTaskGreen(void *pvParameters);
//
///* Used to hold the handle of Task2 */
//TaskHandle_t xTask2Handle;
//
//int main()
//{
//    /* Setup the hardware for use with the Tiva C board. */
//    prvSetupHardware();
//
//    /* Create Tasks here */
//
//    xTaskCreate(vSyncTask, "Sync", 256, NULL, 1,  NULL);
//
//    /* This time we want to obtain a handle to the task so pass in the address
//       of the xTask2Handle variable. */
//    xTaskCreate(vTaskRed, "Task 2", 256, NULL, 2,  &xTaskRedHandle);
//
//    xTaskCreate(vTaskGreen, "Task 3", 256, NULL, 2,  &xTaskGreenHandle);
//
//
//    /* Now all the tasks have been started - start the scheduler.
//
//    NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
//    The processor MUST be in supervisor mode when vTaskStartScheduler is
//    called.  The demo applications included in the FreeRTOS.org download switch
//    to supervisor mode prior to main being called.  If you are not using one of
//    these demo application projects then ensure Supervisor mode is used here. */
//    vTaskStartScheduler();
//
//    /* Should never reach here!  If you do then there was not enough heap
//    available for the idle task to be created. */
//    for (;;);
//
//}
//
//
//static void prvSetupHardware( void )
//{
//    /* Place here any needed HW initialization such as GPIO, UART, etc.  */
//    UART0_Init();
//    GPIO_BuiltinButtonsLedsInit();
//}
//
//void vSyncTask(void *pvParameters)
//{
//    for (;;)
//    {
//        vTaskResume(xTaskRedHandle); //red
//        vTaskDelay(pdMS_TO_TICKS(1000));
//        vTaskResume(xTaskGreenHandle); //yellow
//        vTaskDelay(pdMS_TO_TICKS(1000));
//        vTaskResume(xTaskRedHandle);  //green
//        vTaskDelay(pdMS_TO_TICKS(1000));
//        vTaskResume(xTaskGreenHandle);  //none
//        vTaskDelay(pdMS_TO_TICKS(1000));
//    }
//}
//
//
//void vTaskRed(void *pvParameters)
//{
//    vTaskSuspend(NULL);
//    for (;;)
//    {
//        GPIO_RedLedToggle();
//
//        vTaskSuspend(NULL);
//    }
//}
//
//void vTaskGreen(void *pvParameters)
//{
//    vTaskSuspend(NULL);
//    for (;;)
//    {
//        GPIO_GreenLedToggle();
//
//        vTaskSuspend(NULL);
//    }
//}

/*-----------------------------------------------------------*/
//
//
///********* Semaphores Exercise 3  ************/
//
///* Kernel includes. */
//#include "FreeRTOS.h"
//#include "task.h"
//#include "semphr.h"
//
///* MCAL includes. */
//#include "gpio.h"
//#include "uart0.h"
//
///* Other includes */
//#include <stdlib.h>
//
///* The HW setup function */
//static void prvSetupHardware( void );
//
///* Preprocessor Macros */
//
///* FreeRTOS tasks */
//void vProducerTask(void *pvParameters);
//void vConsumerTask(void *pvParameters);
//
///* FreeRTOS Binary Semaphores */
//xSemaphoreHandle xBinarySemaphore;
//
///* Synchronization Variable */
//uint8 uiLedToggle;
//uint8 prevClick = 0;
//
//int main()
//{
//    /* Setup the hardware for use with the Tiva C board. */
//    prvSetupHardware();
//
//    /* Create a binary semaphore */
//    xBinarySemaphore = xSemaphoreCreateBinary();
//
//    /* Create Tasks here */
//    xTaskCreate(vProducerTask, "Producer Task", 256, NULL, 1, NULL);
//    xTaskCreate(vConsumerTask, "Consumer Task", 256, NULL, 2, NULL);
//
//    vTaskStartScheduler();
//
//    /* Should never reach here!  If you do then there was not enough heap
//    available for the idle task to be created. */
//    for (;;);
//
//}
//
//
//static void prvSetupHardware( void )
//{
//    /* Place here any needed HW initialization such as GPIO, UART, etc.  */
//    GPIO_BuiltinButtonsLedsInit();
//    UART0_Init();
//}
//
//void vProducerTask(void *pvParameters)
//{
//    /* Establish the task's period. */
//    const TickType_t xDelay = pdMS_TO_TICKS(100);
//    GPIO_GreenLedToggle();
//    for (;;) {
//        if(uiLedToggle == PRESSED){
//            uiLedToggle == RELEASED;
//        }
////       1 uiLedToggle = RELEASED;
//        vTaskDelay(xDelay);
////        uiLedToggle = RELEASED;
//        uiLedToggle = GPIO_SW1GetState();
//
//        if(uiLedToggle == PRESSED && prevClick == 0){
//            /* LED to toggle is confirmed */
//              UART0_SendString("Pedestrian Passing: ");
////              prevClick =1;
//              xSemaphoreGive(xBinarySemaphore);
////              prevClick =0;
//        }
//
//
//    }
//}
//
//void vConsumerTask(void *pvParameters)
//{
//    for (;;) {
//        const TickType_t xDelayYlw = pdMS_TO_TICKS(2000);
//        const TickType_t xDelayRed = pdMS_TO_TICKS(6000);
//        const TickType_t xDelayOptn = pdMS_TO_TICKS(1000);
//        /* Tries to take the binary semaphore to check if a new data is available for processing. */
//        if (xSemaphoreTake(xBinarySemaphore, portMAX_DELAY) == pdTRUE) {
//            /* If new data is available in uiLedToToggle its processed and the targeted LED is toggled. */
//                    prevClick =1;
//                    GPIO_RedLedToggle(); //yellow
//                    vTaskDelay(xDelayYlw); //2sec
//                    GPIO_GreenLedToggle();
//                    vTaskDelay(xDelayRed); //6sec
//                    GPIO_GreenLedToggle(); //indefinitely green
//                    GPIO_RedLedToggle(); //close red
//                    prevClick =0;
////                    uiLedToggle = GPIO_SW1GetState();
////                    if(uiLedToggle == PRESSED){
////                         uiLedToggle == RELEASED;
////                    }
//        }
//     }
//}
//
///*-----------------------------------------------------------*/


/*                      Assignment                              */
//
//Binary Semaphores ex8
//
///* Kernel includes. */
//#include "FreeRTOS.h"
//#include "task.h"
//#include "semphr.h"
//
///* MCAL includes. */
//#include "gpio.h"
//#include "uart0.h"
//
///* Other includes */
//#include <stdlib.h>
//
///* The HW setup function */
//static void prvSetupHardware( void );
//
///* FreeRTOS tasks */
//void vTask1(void *pvParameters);
//void vTask2(void *pvParameters);
//void vTask3(void *pvParameters);
//
///* FreeRTOS Binary Semaphores */
//xSemaphoreHandle xSemaphore1;
//xSemaphoreHandle xSemaphore2;
//xSemaphoreHandle xSemaphore3;
//
//
///* Data to communicate */
//volatile uint32_t uiSharedDataTask1ToTask2 = 0;
//volatile uint32_t uiSharedDataTask2ToTask3 = 0;
//volatile uint32_t uiSharedDataTask3ToTask1 = 0;
//
//volatile uint8 count = 0;
//
//int main()
//{
//    /* Setup the hardware for use with the Tiva C board. */
//    prvSetupHardware();
//
//    /* Create three binary semaphores for the bi-synchronization. */
//    xSemaphore1 = xSemaphoreCreateBinary();
//    xSemaphore2 = xSemaphoreCreateBinary();
//    xSemaphore3 = xSemaphoreCreateBinary();
//
//    /* Create Tasks here */
//    xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
//    xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
//    xTaskCreate(vTask3, "Task 3", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
//
//    /* Task 1 is initially unblocked */
//    xSemaphoreGive(xSemaphore1);
//
//    vTaskStartScheduler();
//
//    /* Should never reach here!  If you do then there was not enough heap
//    available for the idle task to be created. */
//    for (;;);
//
//}
//
//
//static void prvSetupHardware( void )
//{
//    /* Place here any needed HW initialization such as GPIO, UART, etc.  */
//    GPIO_BuiltinButtonsLedsInit();
//    UART0_Init();
//}
//
//void vTask1(void *pvParameters) {
//    /* Establish the task's period. */
//    const TickType_t xDelay = pdMS_TO_TICKS(1000);
//
//    for (;;) {
//        vTaskDelay(xDelay);
//
//        /* Wait for xSemaphore1 to be given by task 2 */
//        xSemaphoreTake(xSemaphore1, portMAX_DELAY);
//
//        /* Processes the data produced by task 2 */
//        UART0_SendString("Task 1 received the data from task 3: ");
//        UART0_SendInteger(uiSharedDataTask3ToTask1);
//        UART0_SendString("\r\n");
//
//        /* Produce data to task 2 */
//        uiSharedDataTask1ToTask2++;
//
//        /* Signal task 2 that data is ready */
//        xSemaphoreGive(xSemaphore2);
//    }
//}
//
//void vTask2(void *pvParameters) {
//    /* Establish the task's period. */
//    const TickType_t xDelay = pdMS_TO_TICKS(1000);
//
//    for (;;) {
//        vTaskDelay(xDelay); /* LED on for 1sec */
//
//        /* Wait for xSemaphore2 to be given by task 1 */
//        xSemaphoreTake(xSemaphore2, portMAX_DELAY);
//
//        /* Processes the data produced by task 1 */
//        if (uiSharedDataTask1ToTask2 % 2 == 0) {
//            /* Toggle green led when the data is even */
//            GPIO_GreenLedToggle();
//        }
//        else {
//            /* Toggle red led when the data is odd */
//            GPIO_RedLedToggle();
//        }
//
//        /* Produce data to task 1 */
//        uiSharedDataTask2ToTask3 = rand() % 100;
//
//
//        /* Signal task 1 that data is ready */
//        xSemaphoreGive(xSemaphore3);
//    }
//}
//
//
//void vTask3(void *pvParameters) {
//    /* Establish the task's period. */
//    const TickType_t xDelay = pdMS_TO_TICKS(1000);
//
//    for (;;) {
//        vTaskDelay(xDelay); /* LED on for 1sec */
//
//        /* Wait for xSemaphore2 to be given by task 1 */
//        xSemaphoreTake(xSemaphore3, portMAX_DELAY);
//
//        /* Processes the data produced by task 1 */
//        if (uiSharedDataTask2ToTask3 % 2 == 0) {
//            /* Toggle green led when the data is even */
//            GPIO_BlueLedToggle();
//        }
//        else {
//            /* Toggle red led when the data is odd */
////            GPIO_RedLedToggle();
//            GPIO_RedLedOn();
//            GPIO_GreenLedOn();
//        }
//
//        /* Produce data to task 1 */
//        uiSharedDataTask3ToTask1 = rand() % 100;
//
//
//        /* Signal task 1 that data is ready */
//        xSemaphoreGive(xSemaphore1);
//    }
//}
///*-----------------------------------------------------------*/


//Mutex ex5
//
///* Kernel includes. */
//#include "FreeRTOS.h"
//#include "task.h"
//#include "semphr.h"
//
///* MCAL includes. */
//#include "gpio.h"
//
///* The HW setup function */
//static void prvSetupHardware( void );
//
///* FreeRTOS tasks */
//void vTask1(void *pvParameters); //deposit
//void vTask2(void *pvParameters); //deposit
//void vTask3(void *pvParameters); //withdrawl
//
///* FreeRTOS Mutexes */
//xSemaphoreHandle xMutex;
//
//
//volatile sint64 balance = 1000; //start with value 1000
//int main()
//{
//    /* Setup the hardware for use with the Tiva C board. */
//    prvSetupHardware();
//
//    /* Create a Mutex */
//    xMutex = xSemaphoreCreateMutex();
//
//    /* Create Tasks here */
//    xTaskCreate(vTask1, "Task 1", 256, NULL, 1, NULL);
//    xTaskCreate(vTask2, "Task 2", 256, NULL, 1, NULL);
//    xTaskCreate(vTask3, "Task 3", 256, NULL, 1, NULL);
//
//    vTaskStartScheduler();
//
//    /* Should never reach here!  If you do then there was not enough heap
//    available for the idle task to be created. */
//    for (;;);
//
//}
//
//
//static void prvSetupHardware( void )
//{
//    /* Place here any needed HW initialization such as GPIO, UART, etc.  */
//    GPIO_BuiltinButtonsLedsInit();
//}
//
//void vTask1(void *pvParameters)
//{
//    /* Establish the task's period. */
//    const TickType_t xDelay = pdMS_TO_TICKS(1000);
//    sint64 addRand;
//    for (;;) {
//        /* Block until the next release time. */
//        vTaskDelay(xDelay);
//        if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE) {
//            /* Access the shared peripheral (LEDs) */
//             addRand = rand() % 1000 + 1;
//             balance += addRand;
//             UART0_SendString("Amount Deposited:\r\n");
//             UART0_SendInteger(addRand);
//             UART0_SendString("Updated Balance:\r\n");
//             UART0_SendInteger(balance);
//
//             /* Release the mutex */
//             xSemaphoreGive(xMutex);
//        }
//    }
//}
//
//void vTask2(void *pvParameters)
//{
//    /* Establish the task's period. */
//    const TickType_t xDelay = pdMS_TO_TICKS(1000);
//    sint64 addRand;
//    for (;;) {
//        /* Block until the next release time. */
//        vTaskDelay(xDelay);
//        if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE) {
//           addRand = rand() % 1000 + 1;
//           balance += addRand;
//           UART0_SendString("Amount Deposited:\r\n");
//           UART0_SendInteger(addRand);
//           UART0_SendString("Updated Balance:\r\n");
//           UART0_SendInteger(balance);
//
//           /* Release the mutex */
//           xSemaphoreGive(xMutex);
//        }
//    }
//}
//
//void vTask3(void *pvParameters) //withdraw
//{
//    /* Establish the task's period. */
//    const TickType_t xDelay = pdMS_TO_TICKS(500);
//    sint64 addRand;
//    for (;;) {
//        /* Block until the next release time. */
//        vTaskDelay(xDelay);
//        if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE) {
//           addRand = rand() % 1000 + 1;
//           balance -= addRand;
//           UART0_SendString("Amount Withdrawn:\r\n");
//           UART0_SendInteger(addRand);
//           UART0_SendString("Updated Balance:\r\n");
//           UART0_SendInteger(balance);
//
//           /* Release the mutex */
//           xSemaphoreGive(xMutex);
//        }
//    }
//}
/*-----------------------------------------------------------*/

//Mutex ex4
//
///* Kernel includes. */
//#include "FreeRTOS.h"
//#include "task.h"
//#include "semphr.h"
//
///* MCAL includes. */
//#include "gpio.h"
//
///* The HW setup function */
//static void prvSetupHardware( void );
//
///* FreeRTOS tasks */
//void vTask1(void *pvParameters); //taskx
//void vTask2(void *pvParameters); //tasky
//
///* FreeRTOS Mutexes */
//xSemaphoreHandle xMutex;
//
//int main()
//{
//    /* Setup the hardware for use with the Tiva C board. */
//    prvSetupHardware();
//
//    /* Create a Mutex */
//    xMutex = xSemaphoreCreateMutex();
//
//    /* Create Tasks here */
//    xTaskCreate(vTask1, "Task 1", 256, NULL, 1, NULL);
//    xTaskCreate(vTask2, "Task 2", 256, NULL, 1, NULL);
//
//    vTaskStartScheduler();
//
//    /* Should never reach here!  If you do then there was not enough heap
//    available for the idle task to be created. */
//    for (;;);
//
//}
//
//
//static void prvSetupHardware( void )
//{
//    /* Place here any needed HW initialization such as GPIO, UART, etc.  */
//    GPIO_BuiltinButtonsLedsInit();
//}
//
//void vTask1(void *pvParameters)
//{
//    /* Establish the task's period. */
//    const TickType_t xDelay = pdMS_TO_TICKS(600);
//    const TickType_t xDelayMutex = pdMS_TO_TICKS(500);
//    for (;;) {
//        /* Block until the next release time. */
//        vTaskDelay(xDelay);
//        if (xSemaphoreTake(xMutex, xDelayMutex) == pdTRUE) {
//            UART0_SendString("Task x succeeded in acquiring the mutex\r\n");
//            vTaskDelay(xDelay);
//            /* Release the peripheral */
//            xSemaphoreGive(xMutex);
//        }
//        else{
//            UART0_SendString("Task x failed in acquiring the mutex\r\n");
//        }
//    }
//}
//void vTask2(void *pvParameters)
//{
//    /* Establish the task's period. */
//    const TickType_t xDelay = pdMS_TO_TICKS(600);
//    const TickType_t xDelayMutex = pdMS_TO_TICKS(500);
//
//    // Add an initial delay to desynchronize task start times
//    vTaskDelay(pdMS_TO_TICKS(300));
//    for (;;) {
//        /* Block until the next release time. */
//        vTaskDelay(xDelay);
//        if (xSemaphoreTake(xMutex, xDelayMutex) == pdTRUE) {
//            UART0_SendString("Task y succeeded in acquiring the mutex\r\n");
//            vTaskDelay(xDelay);
//            /* Release the peripheral */
//            xSemaphoreGive(xMutex);
//        }
//        else{
//            UART0_SendString("Task y failed in acquiring the mutex\r\n");
//        }
//    }
//}


/*-----------------------------------------------------------*/


//counting semaphores ex6

//My Implementation is missing another semaphore, i will need one semaphore to block producer
// when the array is full, and another to block consumer when array is empty


///* Kernel includes. */
//#include "FreeRTOS.h"
//#include "task.h"
//#include "semphr.h"
//
///* MCAL includes. */
//#include "gpio.h"
//#include "uart0.h"
//
///* The HW setup function */
//static void prvSetupHardware( void );
//
///* FreeRTOS tasks */
//void vProduceTask(void *pvParameters);
//void vConsumerTask(void *pvParameters);
//
///* FreeRTOS Counting Semaphores */
//xSemaphoreHandle xCountingSemaphore;
//SemaphoreHandle_t xMutex;       // protects buffer/head/tail/size
//
//volatile uint8 arr[10];
//volatile uint8 count = -1;
//
//int main()
//{
//    /* Setup the hardware for use with the Tiva C board. */
//    prvSetupHardware();
//
//    /* Add counting semaphore */
//    xCountingSemaphore = xSemaphoreCreateCounting(10, 0);
//
//    xMutex = xSemaphoreCreateMutex();
//
//    /* Create Tasks here */
//    xTaskCreate(vProduceTask, "Producer Task", 256, NULL, 1, NULL);
//    xTaskCreate(vConsumerTask, "Consumer Task", 256, NULL, 1, NULL);
//
//    vTaskStartScheduler();
//
//    /* Should never reach here!  If you do then there was not enough heap
//    available for the idle task to be created. */
//    for (;;);
//
//}
//
//static void prvSetupHardware( void )
//{
//    /* Place here any needed HW initialization such as GPIO, UART, etc.  */
//    GPIO_BuiltinButtonsLedsInit();
//    UART0_Init();
//}
//
//void vProduceTask(void *pvParameters)
//{
//    /* Establish the task's period. */
//    const TickType_t xDelay = pdMS_TO_TICKS(500);
//
//    for (;;) {
//        xSemaphoreTake(xMutex, pdMS_TO_TICKS(500));
//        if (count<10){
//            count++;
//            arr[count] = rand()%100 + 1;
//            xSemaphoreGive(xCountingSemaphore);
//        }
//        xSemaphoreGive(xMutex);
//        vTaskDelay(xDelay);
//        }
//    }
//}
//
//void vConsumerTask(void *pvParameters)
//{
//    /* Establish the task's period. */
//    const TickType_t xDelay = pdMS_TO_TICKS(1000);
//
//    uint8 reading;
//    for (;;) {
//        /* Blocked until the button is pressed. */
//        if (xSemaphoreTake(xCountingSemaphore, portMAX_DELAY) == pdTRUE) {
//            xSemaphoreTake(xMutex, pdMS_TO_TICKS(500));
//            if (count >= 0){
//                reading = arr[count];  //simulate consuming the element
//            }
//            xSemaphoreGive(xMutex);
//            vTaskDelay(xDelay);
//        }
//    }
//}
/*-----------------------------------------------------------*/


//
//
//
//

//
///* Kernel includes. */
//#include "FreeRTOS.h"
//#include "task.h"
//#include "queue.h"
//
///* MCAL includes. */
//#include "uart0.h"
//
///* The HW setup function */
//static void prvSetupHardware( void );
//
///* FreeRTOS tasks */
//void vSenderTask(void *pvParameters);
//void vReceiverTask(void *pvParameters);
//
///* FreeRTOS Queues */
//QueueHandle_t xQueue;
//
//int main()
//{
//    /* Setup the hardware for use with the Tiva C board. */
//    prvSetupHardware();
//
//    /* Create a queue capable of containing 5 uint32 values. */
//    xQueue = xQueueCreate(1, sizeof(uint32));
//
//    /* Create Tasks here */
//    xTaskCreate(vSenderTask, "Sender Task", 256, NULL, 1, NULL);
//    xTaskCreate(vReceiverTask, "Receiver Task", 256, NULL, 1, NULL);
//
//    vTaskStartScheduler();
//
//    /* Should never reach here!  If you do then there was not enough heap
//    available for the idle task to be created. */
//    for (;;);
//
//}
//
//
//static void prvSetupHardware( void )
//{
//    /* Place here any needed HW initialization such as GPIO, UART, etc.  */
//    UART0_Init();
//    GPIO_BuiltinButtonsLedsInit();
//}
//
//void vSenderTask(void *pvParameters)
//{
//    /* Establish the task's period. */
//    const TickType_t xDelay = pdMS_TO_TICKS(2000);
//    uint32 ulValueToSend = 0;
//
//    for (;;) {
//        /* Block until the next release time. */
//        vTaskDelay(xDelay);
//        /* Send data */
//        ulValueToSend = rand()%3;
//        xQueueSend(xQueue, &ulValueToSend, portMAX_DELAY);
////        ulValueToSend++;
//    }
//}
//
//void vReceiverTask(void *pvParameters)
//{
//    uint32 ulReceivedValue = 0;
//
//    for (;;) {
//        /* Block until the next release time. */
//        if (xQueueReceive(xQueue, &ulReceivedValue, portMAX_DELAY) == pdTRUE) {
//            UART0_SendString("Received: ");
//            UART0_SendInteger(ulReceivedValue);
//            UART0_SendString("\r\n");
//            switch (ulReceivedValue){
//            case 0: GPIO_RedLedToggle();
//                break;
//            case 1: GPIO_GreenLedToggle();
//                break;
//            case 2: GPIO_BlueLedToggle();
//                break;
//            }
//        }
//    }
//}
///*-----------------------------------------------------------*/





