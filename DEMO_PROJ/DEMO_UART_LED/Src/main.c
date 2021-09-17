//////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021 Kikyoko
// https://github.com/Kikyoko
//
// Function : main
// Device   : ALIENTEK STM32F1
// Author   : Kikyoko
// Contact  : Kikyoko@outlook.com
// Date     : 2021/9/14 14:07:07
// Revision : 1.00
//
// Description  : main function
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

#include "stm32f10x.h"  //CHN: 相当于51单片机中的  #include <reg51.h>
#include "bsp_uart.h"
#include "bsp_led.h"

static u8 uart_int_vld;
static u8 uart_rxd;

int main(void) {
    UART_Config();
    LED_Config();
    
    uart_int_vld = 0;
    
    printf("测试printf函数，以及getchar函数 \n");
    
    while(1) {
        printf("等待串口输入LED编号\n");
        while (!uart_int_vld);
        uart_int_vld = 0;
        printf("收到串口输入LED编号，当前输入编号为%c\n", uart_rxd);
        
        switch (uart_rxd) {
            case '0'    :
                LED_Control(DS0, LED_ON);
                LED_Control(DS1, LED_OFF);
                break;
            case '1'    :
                LED_Control(DS0, LED_OFF);
                LED_Control(DS1, LED_ON);
                break;
            default     :
                LED_Control(DS0, LED_OFF);
                LED_Control(DS1, LED_OFF);
                printf("不支持的LED编号\n");
                break;
        }
    };
}

void DEBUG_USART_IRQHandler(void) {
    if (USART_GetITStatus(DEBUG_USARTx, USART_IT_RXNE) == SET) {
        uart_rxd        = USART_ReceiveData(DEBUG_USARTx);
        uart_int_vld    = 1;
    }
}
