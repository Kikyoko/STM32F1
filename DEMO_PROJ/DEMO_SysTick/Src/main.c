//////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021 Kikyoko
// https://github.com/Kikyoko
//
// Function : main
// Device   : ALIENTEK STM32F1
// Author   : Kikyoko
// Contact  : Kikyoko@outlook.com
// Date     : 2021/9/16 18:52:39
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
#include "bsp_delay.h"
#include "bsp_led.h"

int main(void) {
    LED_Config();
    
    LED_Control(DS0, LED_OFF);
    LED_Control(DS1, LED_OFF);
    
    while (1) {
        SysTick_Delay_ms(1000);
        LED_Control(DS0, LED_ON);
        LED_Control(DS1, LED_OFF);
        SysTick_Delay_ms(500);
        LED_Control(DS0, LED_OFF);
        LED_Control(DS1, LED_ON);
    };
}

