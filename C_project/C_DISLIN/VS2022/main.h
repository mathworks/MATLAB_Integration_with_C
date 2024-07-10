/*
 * File: main.h
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 09-Jul-2024 17:03:17
 */

#ifndef MAIN_H
#define MAIN_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern int main(void);

/* Constants definition */
#define NB_SAMPLES 100000
#define FREQ_STEP  10
#define Y_AXS_STEP 20
#define ERROR_TYPE  1
#define ERROR_ORDER 2
/* Macros definition */
#define min_data(a,b) (a<=b?a:b)
#define max_data(a,b) (a>=b?a:b)

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for main.h
 *
 * [EOF]
 */
