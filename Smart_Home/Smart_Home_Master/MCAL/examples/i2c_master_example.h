/*
  @File Name
    i2c_master_example.h
*/

#ifndef I2C_MASTER_EXAMPLE_H
#define I2C_MASTER_EXAMPLE_H

#include <stdint.h>
#include <stdio.h>
#include "../i2c_master.h"

uint8_t  I2C_Read1ByteRegister(i2c_address_t address, uint8_t reg);
uint16_t I2C_Read2ByteRegister(i2c_address_t address, uint8_t reg);
void I2C_Write1ByteRegister(i2c_address_t address, uint8_t reg, uint8_t data);
void I2C_Write2ByteRegister(i2c_address_t address, uint8_t reg, uint16_t data);
void I2C_WriteNBytes(i2c_address_t address, uint8_t *data, size_t len);
void I2C_ReadNBytes(i2c_address_t address, uint8_t *data, size_t len);
void I2C_ReadDataBlock(i2c_address_t address, uint8_t reg, uint8_t *data, size_t len);

#endif /* I2C_MASTER_EXAMPLE_H */