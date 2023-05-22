/**

  @File Name:
    interrupt_manager.h

*/

#include "interrupt_manager.h"
#include "mcc.h"

void  INTERRUPT_Initialize (void)
{
    // Enable Interrupt Priority Vectors
    RCONbits.IPEN = 1;

    // Assign peripheral interrupt priority vectors

    // BCLI - high priority
    IPR2bits.BCLIP = 1;

    // SSPI - high priority
    IPR1bits.SSPIP = 1;


}

void __interrupt() INTERRUPT_InterruptManagerHigh (void)
{
   // interrupt handler
    if(PIE2bits.BCLIE == 1 && PIR2bits.BCLIF == 1)
    {
        MSSP_InterruptHandler();
    }
    else if(PIE1bits.SSPIE == 1 && PIR1bits.SSPIF == 1)
    {
        MSSP_InterruptHandler();
    }
    else
    {
        //Unhandled Interrupt
    }
}

/**
 End of File
*/
