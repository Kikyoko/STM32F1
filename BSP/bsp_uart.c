//////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021 Kikyoko
// https://github.com/Kikyoko
//
// Function : bsp_uart
// Device   : ALIENTEK STM32F1
// Author   : Kikyoko
// Contact  : Kikyoko@outlook.com
// Date     : 2021/9/17 11:05:29
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

#include "bsp_uart.h"

void UART_Config(void) {
    // 开启AFIO时钟，必须先开启AFIO时钟，再配置NVIC
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
    
    //---------------- 配置NVIC ----------------------------
    NVIC_InitTypeDef    NVIC_InitStructure;
    
    // 配置 NVIC 为优先级组 1
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    // 配置抢占优先级：1
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    // 配置子优先级：1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    // 使能中断通道
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    
    NVIC_InitStructure.NVIC_IRQChannel = DEBUG_USART_IRQ;
    NVIC_Init(&NVIC_InitStructure);
    
    //---------------- 配置串口 ----------------------------
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    
    // 打开串口GPIO时钟/串口外设时钟
    DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK, ENABLE);
    DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK, ENABLE);
    
    // 将 USART Tx 的 GPIO 配置为推挽复用模式
    GPIO_InitStructure.GPIO_Pin     = DEBUG_USART_TX_GPIO_PIN;   
    GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AF_PP;          
    GPIO_InitStructure.GPIO_Speed   = GPIO_Speed_50MHz;        
    GPIO_Init(DEBUG_USART_TX_GPIO_PORT, &GPIO_InitStructure);

    // 将 USART Rx 的 GPIO 配置为浮空输入模式                 
    GPIO_InitStructure.GPIO_Pin     = DEBUG_USART_RX_GPIO_PIN;    
    GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_IN_FLOATING;     
    GPIO_Init(DEBUG_USART_RX_GPIO_PORT, &GPIO_InitStructure); 
    
    // 配置串口的工作参数
    // 配置波特率
    USART_InitStructure.USART_BaudRate      = DEBUG_USART_BAUDRATE;
    // 配置 针数据字长
    USART_InitStructure.USART_WordLength    = USART_WordLength_8b;
    // 配置停止位
    USART_InitStructure.USART_StopBits      = USART_StopBits_1;
    // 配置校验位
    USART_InitStructure.USART_Parity        = USART_Parity_No ;
    // 配置硬件流控制
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    // 配置工作模式，收发一起
    USART_InitStructure.USART_Mode          = USART_Mode_Rx | USART_Mode_Tx;
    // 完成串口的初始化配置
    USART_Init(DEBUG_USARTx, &USART_InitStructure);

    // 使能串口接收中断
    USART_ITConfig(DEBUG_USARTx, USART_IT_RXNE, ENABLE);
    // 使能串口
    USART_Cmd(DEBUG_USARTx, ENABLE);
}

void UART_SendStr(USART_TypeDef * pUSARTx, char *str) {
    u16 k = 0;
    while (*(str + k)!='\0') {
        USART_SendData(pUSARTx,*(str + k++));
        // 等待发送数据寄存器为空
        while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
    }
    // 等待发送完成
    while (USART_GetFlagStatus(pUSARTx,USART_FLAG_TC) == RESET);
}
