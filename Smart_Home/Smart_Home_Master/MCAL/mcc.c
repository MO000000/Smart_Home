/**
 
  @File Name:
    mcc.c

*/
    


#include "mcc.h"


void SYSTEM_Initialize(void)
{

    INTERRUPT_Initialize();
    I2C_Initialize();
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    EUSART_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    // SCS FOSC; OSTS intosc; IRCF 1MHz_HFINTOSC/16; IDLEN disabled; 
    OSCCON = 0x30;
    // INTSRC disabled; PLLEN disabled; TUN 0; 
    OSCTUNE = 0x00;
}


/**
 End of File
*/
