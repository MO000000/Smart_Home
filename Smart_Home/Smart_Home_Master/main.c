/**

  File Name:
    main.c
*/

#include"mcc_generated_files/examples/i2c_master_example.h"

#include "mcc_generated_files/mcc.h"
#include"AECUL_Modules/RealTimeClockDS1307/RealTimeClockDS1307.h"
#include"AECUL_Modules/EEPROM_24C02C/EEPROM_24C02C.h"
#include"AECUL_Modules/TemSensor_T74/TemSensor_74.h"

/*
                         Main application
 */


uint8_t U4Rec_val, U5Rece_val ;
uint8_t TC74_A7_Tempvalue = 10;
RealTimeClockDS1307_T RealTimeClockDS1307;
 
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
    
   UART_LoggingDebugData_Send_String("system started\r", 15);
   EEPROM_24C02C_Write_Byte(0xA2, 0x08, 5);
   __delay_us(100);
   EEPROM_24C02C_Write_Byte(0xA6, 0x08, 6);
   __delay_us(100);
   U4Rec_val  = EEPROM_24C02C_Read_Byte(0xA2, 0x08);
   U5Rece_val = EEPROM_24C02C_Read_Byte(0xA6, 0x08);

    while (1)
    {
      
      TC74_A7_Tempvalue = TempSensor_TC74_Read_Temp(0x9E);
     
      if(TC74_A7_Tempvalue > 35){
          I2C_Write1ByteRegister(0x70, 0x00, 0x55);        
      }
      else{
          I2C_Write1ByteRegister(0x70, 0x00, 0x44); 
      }
        
      RealTimeClockDS1307 = RealTimeClockDS1307_Get_Date_Time();
      print_RealTimeClockDS1307();
      
      
      
      __delay_ms(500);
    }
}
