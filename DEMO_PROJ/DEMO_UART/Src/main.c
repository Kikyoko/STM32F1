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

int main(void) {
    UART_Config();
    
    UART_SendStr(DEBUG_USARTx, "这是一个串口环回实验\n");
    
    while(1);
}

void DEBUG_USART_IRQHandler(void) {
    u8 rx_tmp;
    
    if (USART_GetITStatus(DEBUG_USARTx, USART_IT_RXNE) == SET) {
        rx_tmp = USART_ReceiveData(DEBUG_USARTx);
        USART_SendData(DEBUG_USARTx, rx_tmp);
    }
}

