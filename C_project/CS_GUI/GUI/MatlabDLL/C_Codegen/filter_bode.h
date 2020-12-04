/*
 * File: filter_bode.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 04-Dec-2020 09:16:34
 */

#ifndef FILTER_BODE_H
#define FILTER_BODE_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  extern void filter_bode(const double f[100000], double f_0, double q_0, double
    g, const char f_type[5], int f_order, double H_mod[100000], double H_arg
    [100000], int *err_f);
  extern void filter_bode_initialize(void);
  extern void filter_bode_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for filter_bode.h
 *
 * [EOF]
 */
