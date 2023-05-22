/* 
 * File:   RealTimeClockDS1307.h
 * Author: Mohamed Hossam
 *
 * Created on March 1, 2023, 7:38 PM
 */

#ifndef REALTIMECLOCKDS1307_H
#define	REALTIMECLOCKDS1307_H

#include "../../mcc_generated_files/mcc.h"
#include"../../mcc_generated_files/examples/i2c_master_example.h"
#include"../UART_LoggingDebugData/UART_LoggingDebugData.h"


typedef struct{
    uint8_t Hours;
    uint8_t Minutes;
    uint8_t Seconds;
    uint8_t Year;
    uint8_t Month;
    uint8_t Day;
}RealTimeClockDS1307_T;


RealTimeClockDS1307_T RealTimeClockDS1307_Get_Date_Time(void);
void print_RealTimeClockDS1307(void);




#endif	/* REALTIMECLOCKDS1307_H */