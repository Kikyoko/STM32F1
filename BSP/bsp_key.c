//////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021 Kikyoko
// https://github.com/Kikyoko
//
// Function : bsp_key
// Device   : ALIENTEK STM32F1
// Author   : Kikyoko
// Contact  : Kikyoko@outlook.com
// Date     : 2021/9/14 13:52:31
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

#include "bsp_key.h"

void KEY_Config(void) {
    GPIO_InitTypeDef    GPIO_InitStruct;
    
    RCC_APB2PeriphClockCmd(KEY_0_CLK|KEY_1_CLK|KEY_UP_CLK, ENABLE);
    GPIO_InitStruct.GPIO_Mode   = GPIO_Mode_IPU;
    
    GPIO_InitStruct.GPIO_Pin    = KEY_0_PIN;
    GPIO_Init(KEY_0_PORT, &GPIO_InitStruct);	
        
    GPIO_InitStruct.GPIO_Pin    = KEY_1_PIN;
    GPIO_Init(KEY_1_PORT, &GPIO_InitStruct);	
    
    GPIO_InitStruct.GPIO_Mode   = GPIO_Mode_IPD;
    GPIO_InitStruct.GPIO_Pin    = KEY_UP_PIN;
    GPIO_Init(KEY_UP_PORT, &GPIO_InitStruct);	
}

uint8_t KEY_Scan(uint8_t key_id) {
    if (key_id == 0) {
        if (GPIO_ReadInputDataBit(KEY_0_PORT,KEY_0_PIN) == 0) \
            return KEY_ON;
        else \
            return KEY_OFF;
    }
    if (key_id == 1) {
        if (GPIO_ReadInputDataBit(KEY_1_PORT,KEY_1_PIN) == 0) \
            return KEY_ON;
        else \
            return KEY_OFF;
    }
    if (key_id == 2) {
        if (GPIO_ReadInputDataBit(KEY_UP_PORT,KEY_UP_PIN) == 1) \
            return KEY_ON;
        else \
            return KEY_OFF;
    }
}
