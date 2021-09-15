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
#include "bsp_led.h"
#include "bsp_key.h"

void Delay(uint32_t count) {
    for(; count!=0; count--);
}

int main(void) {
    LED_Config();
    KEY_Config();
    
    uint8_t key_flash = 0;
    
    while(1) {
        if (KEY_Scan(KEY_0) == KEY_ON) {
            LED_Control(DS0,LED_ON);
            LED_Control(DS1,LED_OFF);
            key_flash   = 0;
        };
        if (KEY_Scan(KEY_1) == KEY_ON) {
            LED_Control(DS0,LED_OFF);
            LED_Control(DS1,LED_ON);
            key_flash   = 0;
        };
        if (KEY_Scan(KEY_UP) == KEY_ON) {
            key_flash   = ~key_flash & 0x1;
					  LED_Control(DS0,LED_OFF);
					  LED_Control(DS1,LED_OFF);
        };
        
        if (key_flash) {
            LED_Control(DS0,LED_ON);
            LED_Control(DS1,LED_OFF);
            Delay(0xFFFFF);
            LED_Control(DS0,LED_OFF);
            LED_Control(DS1,LED_ON);
            Delay(0xFFFFF);
        }
    }
}
