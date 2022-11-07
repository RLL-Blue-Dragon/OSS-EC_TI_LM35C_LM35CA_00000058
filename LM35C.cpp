// License       : License.txt
// Specifications: Spec-LM35C_LM35CA.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM35C.cpp
// Reason for change: 01.00.00 : 03/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "LM35C.h"

#if     iLM35C_ma == iSMA                               // Simple moving average filter
static float32 LM35C_sma_buf[iLM35C_SMA_num];
static sma_f32_t LM35C_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iLM35C_SMA_num ,                                // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &LM35C_sma_buf[0]                               // buffer
};

#elif   iLM35C_ma == iEMA                               // Exponential moving average filter
static ema_f32_t LM35C_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iLM35C_EMA_K                                    // Exponential smoothing factor
};

#elif   iLM35C_ma == iWMA                               // Weighted moving average filter
static float32 LM35C_wma_buf[iLM35C_WMA_num];
static wma_f32_t LM35C_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iLM35C_WMA_num ,                                // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iLM35C_WMA_num * (iLM35C_WMA_num + 1)/2 ,       // kn sum
        &LM35C_wma_buf[0]                               // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_LM35C =
{
        iLM35C                  ,
        iLM35C_pin              ,
        iLM35C_xoff             ,
        iLM35C_yoff             ,
        iLM35C_gain             ,
        iLM35C_max              ,
        iLM35C_min              ,
        iLM35C_ma               ,
        
#if     iLM35C_ma == iSMA                               // Simple moving average filter
        &LM35C_Phy_SMA          ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iLM35C_ma == iEMA                               // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &LM35C_Phy_EMA          ,
        (wma_f32_t*)iDummy_adr
#elif   iLM35C_ma == iWMA                               // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &LM35C_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
