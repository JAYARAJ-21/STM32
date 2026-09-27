STM32f411CEU6 also known as Black Pill.

To access a GPIO pin, we have to configure it's associated registers. 
  1.GPIO clock. 
  2.Mode
  3.Output type
  4.Speed 
  5.Output data

The onboard led of Black Pill is connected to PC13.
1.Enable the GPIO clock.
2.MODE - Output
3.OUTPUT MODE - Push pull
4.SPEED - 2MHz( low speed as this wouldn't requre high speed )
5.OUTPUT DATA - Toggle bit 13 of Port C.  



