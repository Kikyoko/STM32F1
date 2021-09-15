//////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021 Kikyoko
// https://github.com/Kikyoko
//
// Function : main
// Device   : ALIENTEK STM32F1
// Author   : Kikyoko
// Contact  : Kikyoko@outlook.com
// Date     : 2021/9/2 17:33:07
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
#include "bsp_led.h"

void Delay(uint32_t count) {
    for(; count!=0; count--);
}

int main(void) {
    LED_Config();
    
    while(1) {
        LED_Control(0,ON);
        Delay(0xFFFFF);
        LED_Control(0,OFF);
        LED_Control(1,ON);
        Delay(0xFFFFF);
        LED_Control(1,OFF);
    }
}
