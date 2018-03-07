/*
 * File: main.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 08-Feb-2018 11:07:30
 */

#ifndef MAIN_H
#define MAIN_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "main_types.h"

/* Function Declarations */
extern int main(void);

/* Constants definition */
#define NB_SAMPLES 100000
#define NB_FILTERS  8
#define FREQ_STEP  10
#define Y_AXS_STEP 20
#define ERROR_TYPE  1
#define ERROR_ORDER 2
/* Macros definition */
#define min_data(a,b) (a<=b?a:b)
#define max_data(a,b) (a>=b?a:b)

#endif

/*
 * File trailer for main.h
 *
 * [EOF]
 */
