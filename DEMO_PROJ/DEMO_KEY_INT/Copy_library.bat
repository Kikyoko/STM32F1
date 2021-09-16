@echo off

xcopy /y /s ..\STM32F10x_StdPeriph_Lib_V3.5.0\Libraries\CMSIS\CM3\CoreSupport               .\Library\
xcopy /y /s ..\STM32F10x_StdPeriph_Lib_V3.5.0\Libraries\STM32F10x_StdPeriph_Driver\src      .\Library\
xcopy /y /s ..\STM32F10x_StdPeriph_Lib_V3.5.0\Libraries\CMSIS\CM3\DeviceSupport\ST\STM32F10x\startup\arm\startup_stm32f10x_hd.s      .\Library\

xcopy /y /s ..\BSP               .\BSP\
