/*
 * File: main.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 30-Apr-2018 17:05:27
 */

#ifndef MAIN_H
#define MAIN_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "main_types.h"

/* Type Definitions */
#include <stdio.h>

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

#endif

/*
 * File trailer for main.h
 *
 * [EOF]
 */
