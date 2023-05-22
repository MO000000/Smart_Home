/* 
 * File:   UART_LoggingDebugData.c
 * Author: Mohamed Hossam
 *
 * Created on March 1, 2023, 11:30 PM
 */


#include"UART_LoggingDebugData.h"


void UART_LoggingDebugData_Send_String(uint8_t *String, uint16_t String_Length){
   uint16_t l_String_Length = 0;
    for(l_String_Length = 0; l_String_Length < String_Length; l_String_Length++ ){
          EUSART_Write(*String++); 
    }
}
