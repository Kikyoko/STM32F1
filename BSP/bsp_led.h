#ifndef _BSP_LED_H
    #define _BSP_LED_H
   
    #include "stm32f10x.h"
    
    #define DS0                 0
    #define DS1                 1
    
    #define LED_ON              1
    #define LED_OFF             0
   
    #define LED_DS0_PIN         GPIO_Pin_5
    #define LED_DS0_PORT        GPIOB
    #define LED_DS0_CLK         RCC_APB2Periph_GPIOB
                                
    #define LED_DS1_PIN         GPIO_Pin_5
    #define LED_DS1_PORT        GPIOE
    #define LED_DS1_CLK         RCC_APB2Periph_GPIOE
    
    void LED_Config(void);
    void LED_Control(uint8_t led_id, uint8_t led_sts);
#endif
