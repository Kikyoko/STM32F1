//////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021 Kikyoko
// https://github.com/Kikyoko
//
// Function : bsp_led
// Device   : ALIENTEK STM32F1
// Author   : Kikyoko
// Contact  : Kikyoko@outlook.com
// Date     : 2021/9/2 17:27:47
// Revision : 1.00
//
// Description  : 
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//////////////////////////////////////////////////////////////////////////////////////////

#include "bsp_led.h"

void LED_Config(void) {
    GPIO_InitTypeDef    GPIO_InitStruct;
    
    RCC_APB2PeriphClockCmd(LED_DS0_CLK|LED_DS1_CLK, ENABLE);
    GPIO_InitStruct.GPIO_Mode   = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed  = GPIO_Speed_50MHz;
    
    GPIO_InitStruct.GPIO_Pin    = LED_DS0_PIN;
    GPIO_Init(LED_DS0_PORT, &GPIO_InitStruct);	
        
    GPIO_InitStruct.GPIO_Pin    = LED_DS1_PIN;
    GPIO_Init(LED_DS1_PORT, &GPIO_InitStruct);	
}

void LED_Control(uint8_t led_id, uint8_t led_sts) {
    if (led_id == 0) {
        if (led_sts == LED_ON) \
            GPIO_ResetBits(LED_DS0_PORT, LED_DS0_PIN);
        else \
            GPIO_SetBits(LED_DS0_PORT, LED_DS0_PIN);
    } else {
        if (led_sts == LED_ON) \
            GPIO_ResetBits(LED_DS1_PORT, LED_DS1_PIN);
        else \
            GPIO_SetBits(LED_DS1_PORT, LED_DS1_PIN);
    }
}
