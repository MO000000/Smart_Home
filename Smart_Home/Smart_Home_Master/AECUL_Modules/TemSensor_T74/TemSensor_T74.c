/* 
 * File:   TemSensor_74.c
 * Author: Mohamed Hossam
 *
 * Created on March 8, 2023, 7:30 PM
 */

#include"TemSensor_74.h"

uint8_t TempSensor_TC74_Read_Temp(i2c_address_t TC74_Address){
    uint8_t TC74_Tempvalue = 0;
    TC74_Tempvalue = I2C_Read1ByteRegister(TC74_Address, 0x00);
    
    return TC74_Tempvalue;  
}
