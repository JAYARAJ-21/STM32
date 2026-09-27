I was trying to flash program to STM32 by ST-link but I hardly gets connected as only clone ST-link debugger is available in the market for cheap. 
So I'm gonna use CP2102 USB to UART converter board to flash code. 

Required components 
                 1. STM32 ( Here I'm using STM32f103C8T6 [blue pill] )
                 2. USB to UART board ( you can use any board which you have, here I'm using CP2102 )

STM32F103C8T6 works on two modes.
                 1. Bootloader mode
                 2. Normal mode

Bootloader mode : By this mode we can flash our code to blue pill.
Normal mode : In this mode the program already stored in the memory gets executed when powered. This is the mode which the MCU runs often. 

To upload code, Blue pill has to be in the Bootloader mode. We have to do that by simply place the BOOT0 jumber at 1.
<img width="316" height="316" alt="image" src="https://github.com/user-attachments/assets/7bfb1322-6d02-4861-beeb-37f9fa77e98b" />

