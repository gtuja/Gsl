/**
 * @file    gsl.c
 * @brief   This file is used to ... 
 * @author  Gtuja
 * @date    Oct 9, 2024
 * @note    Copyleft, All rights reversed.
 */

/* Includes ------------------------------------------------------------------*/
#include "gsl_def.h"
#include "gsl_api.h"
#include <string.h>

/* External variables --------------------------------------------------------*/
/* External functions --------------------------------------------------------*/
EXTERN void vidGnosInitialize(void* pvArgs);

/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
typedef struct {
  tstrGslInitializeArgs strArgs;
} tstrGslControl;

/* Private function prototypes -----------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
PRIVATE tstrGslControl strGslControl;


/* Public functions ----------------------------------------------------------*/

/**
 * @brief   A public function that xxx.
 * @param   xxParam  A xxx parameter used for xxxx from Xxx.
 * @sa      vidXxx
 * @return  void
 */

PUBLIC void vidGslInitialize(tstrGslInitializeArgs* pstrArgs) {
  memcpy(&(strGslControl.strArgs), pstrArgs, sizeof(tstrGslInitializeArgs));

  vidGnosInitialize(NULL);
}

PUBLIC void vidGslTrace(char* pcTrace) {
  if (strGslControl.strArgs.strAppCallbacks.pfTrace != NULL) {
    strGslControl.strArgs.strAppCallbacks.pfTrace(pcTrace);
  }
}

PUBLIC U32 u32GslTick(void) {
  return (strGslControl.strArgs.strAppCallbacks.pfTick != NULL) ? \
          strGslControl.strArgs.strAppCallbacks.pfTick() : (U32)0;
}
