// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM35C_00000058.cpp
// BSL              : 00000058
// Model number     : Texas Instruments LM35C, LM35CA
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 03/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "LM35C.h"

AnalogIn LM35C_adc( iLM35C_pin , iVref );       // AnalogIn object

// Main Function
pp2ap_adc_t LM35C_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( LM35C_adc , tbl_LM35C );
        return( res );
}
