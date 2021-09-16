//////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021 Kikyoko
// https://github.com/Kikyoko
//
// Function : bsp_key_int
// Device   : ALIENTEK STM32F1
// Author   : Kikyoko
// Contact  : Kikyoko@outlook.com
// Date     : 2021/9/16 15:26:04
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

#include "bsp_key_int.h"

//ִ�д˺���ǰ��������ִ��KEY_Config()
void KEY_INT_Config(void) {
    // ����AFIOʱ�ӣ������ȿ���AFIOʱ�ӣ�������NVIC
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
    
    //---------------- ����NVIC ----------------------------
    NVIC_InitTypeDef    NVIC_InitStructure;
    
    // ���� NVIC Ϊ���ȼ��� 1
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    
    // ������ռ���ȼ���1
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    // ���������ȼ���1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    // ʹ���ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    
    NVIC_InitStructure.NVIC_IRQChannel = KEY0_INT_EXTI_IRQ;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ;
    NVIC_Init(&NVIC_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = KEY_UP_INT_EXTI_IRQ;
    NVIC_Init(&NVIC_InitStructure);
    
    //---------------- ���ð����ж� ------------------------
    EXTI_InitTypeDef    EXTI_InitStructure;

    GPIO_EXTILineConfig(KEY0_INT_EXTI_PORTSOURCE, KEY0_INT_EXTI_PINSOURCE);
    EXTI_InitStructure.EXTI_Line    = KEY0_INT_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
    
    GPIO_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE, KEY1_INT_EXTI_PINSOURCE);
    EXTI_InitStructure.EXTI_Line    = KEY1_INT_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
    
    GPIO_EXTILineConfig(KEY_UP_INT_EXTI_PORTSOURCE, KEY_UP_INT_EXTI_PINSOURCE);
    EXTI_InitStructure.EXTI_Line    = KEY_UP_INT_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
}
