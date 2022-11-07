// License       : License.txt
// Specifications: Spec-LM35C_LM35CA.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM35C.h
// Reason for change: 01.00.00 : 03/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __LM35C_H__
#define __LM35C_H__

#include "user_define.h"

// Components number
#define iLM35C                  127U                    // Texas Instruments LM35C, LM35CA

// LM35C, LM35CA System Parts definitions
#define iLM35C_xoff             0.0F                    // X offset [V]
#define iLM35C_yoff             0.0F                    // Y offset [degree celsius]
#define iLM35C_gain             0.01F                   // Gain [V/degree celsius]
#define iLM35C_max              110.0F                  // Temperature Max [degree celsius]
#define iLM35C_min              2.0F                    // Temperature Min [degree celsius]     CAUTION:-40[°C],the circuit needs a voltage Offset

extern const tbl_adc_t tbl_LM35C;

#endif /*__LM35C_H__*/
