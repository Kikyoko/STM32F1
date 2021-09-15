#ifndef _BSP_LED_H
    #define _BSP_LED_H
   
    #include "stm32f10x.h"
   
    #define LED_DS0_PIN         GPIO_Pin_5
    #define LED_DS0_PORT        GPIOB
    #define LED_DS0_CLK         RCC_APB2Periph_GPIOB
                                
    #define LED_DS1_PIN         GPIO_Pin_5
    #define LED_DS1_PORT        GPIOE
    #define LED_DS1_CLK         RCC_APB2Periph_GPIOE
                                
    #define ON                  1
    #define OFF                 0
    
    void LED_Config(void);
    void LED_Control(int led_id, int led_sts);
#endif
