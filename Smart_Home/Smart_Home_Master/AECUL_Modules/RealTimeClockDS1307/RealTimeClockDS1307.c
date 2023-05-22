/* 
 * File:   RealTimeClockDS1307.c
 * Author: Mohamed Hossam
 *
 * Created on March 1, 2023, 7:38 PM
 */
#include"RealTimeClockDS1307.h"

static RealTimeClockDS1307_T RealTimeClockDS1307;

/* "Year" : " Month" : " Day " : " Hours " : " Minutes " : " Seconds " */
static uint8_t RealTimeClockDS1307_Pack[18] ;


RealTimeClockDS1307_T RealTimeClockDS1307_Get_Date_Time(void){
    RealTimeClockDS1307.Seconds = I2C_Read1ByteRegister(0xD0, 0x00);
    RealTimeClockDS1307.Minutes = I2C_Read1ByteRegister(0xD0, 0x01);
    RealTimeClockDS1307.Hours = I2C_Read1ByteRegister(0xD0, 0x02);
    RealTimeClockDS1307.Day = I2C_Read1ByteRegister(0xD0, 0x04);
    RealTimeClockDS1307.Month = I2C_Read1ByteRegister(0xD0, 0x05);
    RealTimeClockDS1307.Year = I2C_Read1ByteRegister(0xD0, 0x06);
    
    return RealTimeClockDS1307;
}

void print_RealTimeClockDS1307(void){
    
    RealTimeClockDS1307_Pack[0] = ((RealTimeClockDS1307.Day >> 4) + 0x30);
    RealTimeClockDS1307_Pack[1] = ((RealTimeClockDS1307.Day & 0x0F) + 0x30);
    RealTimeClockDS1307_Pack[2] = '-';
    RealTimeClockDS1307_Pack[3] = ((RealTimeClockDS1307.Month >> 4) + 0x30);
    RealTimeClockDS1307_Pack[4] = ((RealTimeClockDS1307.Month & 0x0F) + 0x30);
    RealTimeClockDS1307_Pack[5] = '-'; 
    RealTimeClockDS1307_Pack[6] = ((RealTimeClockDS1307.Year >> 4) + 0x30);
    RealTimeClockDS1307_Pack[7] = ((RealTimeClockDS1307.Year & 0x0F) + 0x30);
    
    RealTimeClockDS1307_Pack[8] = '/';
            
    RealTimeClockDS1307_Pack[9]  = ((RealTimeClockDS1307.Hours >> 4) + 0x30);
    RealTimeClockDS1307_Pack[10] = ((RealTimeClockDS1307.Hours & 0x0F) + 0x30);      
    RealTimeClockDS1307_Pack[11] = '-';
    RealTimeClockDS1307_Pack[12] = ((RealTimeClockDS1307.Minutes >> 4) + 0x30);
    RealTimeClockDS1307_Pack[13] = ((RealTimeClockDS1307.Minutes & 0x0F) + 0x30); 
    RealTimeClockDS1307_Pack[14] =  '-';      
    RealTimeClockDS1307_Pack[15] = ((RealTimeClockDS1307.Seconds >> 4) + 0x30);
    RealTimeClockDS1307_Pack[16] = ((RealTimeClockDS1307.Seconds & 0x0F) + 0x30);
    
    RealTimeClockDS1307_Pack[17] = '\r';
            
    UART_LoggingDebugData_Send_String("Date : ", 8);
    UART_LoggingDebugData_Send_String(RealTimeClockDS1307_Pack , 18);
}
