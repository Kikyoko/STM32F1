#ifndef _BSP_DELAY_H
    #define _BSP_DELAY_H
   
    #include "stm32f10x.h"
    
    void SysTick_Delay_ms(u32 ms);
    void SysTick_Handler(void);
#endif
