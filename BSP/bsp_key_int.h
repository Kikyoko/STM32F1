#ifndef _BSP_KEY_INT_H
    #define _BSP_KEY_INT_H

    #include "stm32f10x.h"
    
    #define KEY0_INT_EXTI_PORTSOURCE    GPIO_PortSourceGPIOE
    #define KEY0_INT_EXTI_PINSOURCE     GPIO_PinSource4
    #define KEY0_INT_EXTI_LINE          EXTI_Line4
    #define KEY0_INT_EXTI_IRQ           EXTI4_IRQn
    #define KEY0_IRQHandler             EXTI4_IRQHandler
    
    #define KEY1_INT_EXTI_PORTSOURCE    GPIO_PortSourceGPIOE
    #define KEY1_INT_EXTI_PINSOURCE     GPIO_PinSource3
    #define KEY1_INT_EXTI_LINE          EXTI_Line3
    #define KEY1_INT_EXTI_IRQ           EXTI3_IRQn
    #define KEY1_IRQHandler             EXTI3_IRQHandler
    
    #define KEY_UP_INT_EXTI_PORTSOURCE  GPIO_PortSourceGPIOA
    #define KEY_UP_INT_EXTI_PINSOURCE   GPIO_PinSource0
    #define KEY_UP_INT_EXTI_LINE        EXTI_Line0
    #define KEY_UP_INT_EXTI_IRQ         EXTI0_IRQn
    #define KEY_UP_IRQHandler           EXTI0_IRQHandler

    void KEY_INT_Config(void);
#endif
