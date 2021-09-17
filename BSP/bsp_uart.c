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
    // ����AFIOʱ�ӣ������ȿ���AFIOʱ�ӣ�������NVIC
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
    
    //---------------- ����NVIC ----------------------------
    NVIC_InitTypeDef    NVIC_InitStructure;
    
    // ���� NVIC Ϊ���ȼ��� 1
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    // ������ռ���ȼ���1
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    // ���������ȼ���1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    // ʹ���ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    
    NVIC_InitStructure.NVIC_IRQChannel = DEBUG_USART_IRQ;
    NVIC_Init(&NVIC_InitStructure);
    
    //---------------- ���ô��� ----------------------------
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    
    // �򿪴���GPIOʱ��/��������ʱ��
    DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK, ENABLE);
    DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK, ENABLE);
    
    // �� USART Tx �� GPIO ����Ϊ���츴��ģʽ
    GPIO_InitStructure.GPIO_Pin     = DEBUG_USART_TX_GPIO_PIN;   
    GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AF_PP;          
    GPIO_InitStructure.GPIO_Speed   = GPIO_Speed_50MHz;        
    GPIO_Init(DEBUG_USART_TX_GPIO_PORT, &GPIO_InitStructure);

    // �� USART Rx �� GPIO ����Ϊ��������ģʽ                 
    GPIO_InitStructure.GPIO_Pin     = DEBUG_USART_RX_GPIO_PIN;    
    GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_IN_FLOATING;     
    GPIO_Init(DEBUG_USART_RX_GPIO_PORT, &GPIO_InitStructure); 
    
    // ���ô��ڵĹ�������
    // ���ò�����
    USART_InitStructure.USART_BaudRate      = DEBUG_USART_BAUDRATE;
    // ���� �������ֳ�
    USART_InitStructure.USART_WordLength    = USART_WordLength_8b;
    // ����ֹͣλ
    USART_InitStructure.USART_StopBits      = USART_StopBits_1;
    // ����У��λ
    USART_InitStructure.USART_Parity        = USART_Parity_No ;
    // ����Ӳ��������
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    // ���ù���ģʽ���շ�һ��
    USART_InitStructure.USART_Mode          = USART_Mode_Rx | USART_Mode_Tx;
    // ��ɴ��ڵĳ�ʼ������
    USART_Init(DEBUG_USARTx, &USART_InitStructure);

    // ʹ�ܴ��ڽ����ж�
    USART_ITConfig(DEBUG_USARTx, USART_IT_RXNE, ENABLE);
    // ʹ�ܴ���
    USART_Cmd(DEBUG_USARTx, ENABLE);
}

void UART_SendStr(USART_TypeDef * pUSARTx, char *str) {
    u16 k = 0;
    while (*(str + k)!='\0') {
        USART_SendData(pUSARTx,*(str + k++));
        // �ȴ��������ݼĴ���Ϊ��
        while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
    }
    // �ȴ��������
    while (USART_GetFlagStatus(pUSARTx,USART_FLAG_TC) == RESET);
}
