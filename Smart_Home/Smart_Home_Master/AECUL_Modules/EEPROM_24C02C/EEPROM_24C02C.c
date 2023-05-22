/* 
 * File:   EEPROM_24C02C.c
 * Author: Mohamed Hossam
 * 
 * Created on March 8, 2023, 1:44 PM
 */

#include"EEPROM_24C02C.h"

void EEPROM_24C02C_Write_Byte(i2c_address_t EEPROM_Address, i2c_address_t Byte_Address, uint8_t Data){
    I2C_Write1ByteRegister(EEPROM_Address, Byte_Address, Data);
}

uint8_t EEPROM_24C02C_Read_Byte(i2c_address_t EEPROM_Address, i2c_address_t Byte_Address){
    uint8_t Rec_Value = 0;
    Rec_Value = I2C_Read1ByteRegister(EEPROM_Address, Byte_Address);
    return Rec_Value;  
}



