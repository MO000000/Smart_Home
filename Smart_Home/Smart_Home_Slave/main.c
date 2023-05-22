

#include "mcc_generated_files/mcc.h"

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();
    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    while (1)
    {

    }
}
