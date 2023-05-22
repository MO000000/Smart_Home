/* 
 * File:   TemSensor_74.h
 * Author: Mohamed Hossam
 *
 * Created on March 8, 2023, 7:30 PM
 */

#ifndef TEMSENSOR_74_H
#define	TEMSENSOR_74_H

#include"../../mcc_generated_files/mcc.h"
#include"../../mcc_generated_files/examples/i2c_master_example.h"

uint8_t TempSensor_TC74_Read_Temp(i2c_address_t TC74_Address);

#endif	/* TEMSENSOR_74_H */

