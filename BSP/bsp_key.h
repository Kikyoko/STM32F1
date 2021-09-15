#ifndef _BSP_KEY_H
    #define _BSP_KEY_H

    #include "stm32f10x.h"
    
    #define KEY_0               0
    #define KEY_1               1
    #define KEY_UP              2
    
    #define KEY_ON              1
    #define KEY_OFF             0

    #define KEY_0_PIN           GPIO_Pin_4
    #define KEY_0_PORT          GPIOE
    #define KEY_0_CLK           RCC_APB2Periph_GPIOE

    #define KEY_1_PIN           GPIO_Pin_3
    #define KEY_1_PORT          GPIOE
    #define KEY_1_CLK           RCC_APB2Periph_GPIOE
    
    #define KEY_UP_PIN          GPIO_Pin_0
    #define KEY_UP_PORT         GPIOA
    #define KEY_UP_CLK          RCC_APB2Periph_GPIOA

    void KEY_Config(void);
    uint8_t KEY_Scan(uint8_t key_id);
#endif
