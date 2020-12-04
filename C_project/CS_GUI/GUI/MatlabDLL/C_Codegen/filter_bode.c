/*
 * File: filter_bode.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 04-Dec-2020 09:16:34
 */

/* Include Files */
#include "filter_bode.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "string.h"
#include <math.h>

/* Function Declarations */
static double rt_atan2d_snf(double u0, double u1);
static double rt_hypotd_snf(double u0, double u1);

/* Function Definitions */
/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * sqrt(y * y + 1.0);
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

/*
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *  Function: filter_bode()
 *  Goal    : Calculates the frequency response of a given filter's type
 *
 *  IN      : - f      : vector of frequency values
 *            - f_0    : cutoff frequency of the filter
 *            - g      : gain of the filter
 *            - q_0    : quality factor of the filter (for 2nd order sections)
 *            - f_type : filter's type :'low', 'high', 'band' and 'stop'
 *            - f_order: filter's order
 *  IN/OUT  : -
 *  OUT     : - H_mod : module of the transfer function in [dB]
 *            - H_arg : argument of the transfer function in [&#xFFFD;]
 *            - err_f : returns execution error related to input parameters
 *
 *  Copyright 2018 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * Arguments    : const double f[100000]
 *                double f_0
 *                double q_0
 *                double g
 *                const char f_type[5]
 *                int f_order
 *                double H_mod[100000]
 *                double H_arg[100000]
 *                int *err_f
 * Return Type  : void
 */
void filter_bode(const double f[100000], double f_0, double q_0, double g, const
                 char f_type[5], int f_order, double H_mod[100000], double
                 H_arg[100000], int *err_f)
{
  static creal_T H[100000];
  static creal_T H_tmp[100000];
  static double w[100000];
  static const char TYPE[20] = { 'l', 'h', 'b', 's', 'o', 'i', 'a', 't', 'w',
    'g', 'n', 'o', '\x00', 'h', 'd', 'p', '\x00', '\x00', '\x00', '\x00' };

  double b_im;
  double b_re;
  double brm;
  double d;
  double im;
  double im_tmp;
  double re;
  double w_0;
  double y_im;
  double y_re;
  int exitg1;
  int filter_T_32;
  int i;
  int negate_bool;
  char b_f_type[5];
  char cv[5];
  boolean_T guard1 = false;

  /*  Constants */
  /*  Integer representation of filter's type */
  /*  Initializations */
  *err_f = 0;
  filter_T_32 = 0;

  /*  Pulsation's vectors */
  for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
    H[negate_bool].re = 1.0;
    H[negate_bool].im = 0.0;
    H_mod[negate_bool] = 0.0;
    H_arg[negate_bool] = 0.0;
    w[negate_bool] = 6.2831853071795862 * f[negate_bool];
  }

  w_0 = 6.2831853071795862 * f_0;

  /*  Set switches to work with integer */
  for (i = 0; i < 4; i++) {
    for (negate_bool = 0; negate_bool < 5; negate_bool++) {
      b_f_type[negate_bool] = f_type[negate_bool];
      cv[negate_bool] = TYPE[i + (negate_bool << 2)];
    }

    negate_bool = strcmp(&b_f_type[0], &cv[0]);
    if (negate_bool == 0) {
      filter_T_32 = i + 1;
    }
  }

  /*  Test the order of the filter against the filter type */
  if ((filter_T_32 > 2) && (f_order - ((f_order >> 1) << 1) != 0)) {
    /*  For band-pass and stop-band filters odd orders are not feasible */
    *err_f = 2;
  } else {
    /*  Bode diagram calculation */
    do {
      exitg1 = 0;
      guard1 = false;
      if (f_order > 1) {
        negate_bool = 2;
        guard1 = true;
      } else if (f_order == 1) {
        negate_bool = 1;
        guard1 = true;
      } else {
        /*  All filter's cells have been calculated */
        /*  Apply the filter gain only once */
        /*  Retrieves module and argument of the transfer function H */
        /*  [dB] */
        for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
          re = g * H[negate_bool].re;
          im = g * H[negate_bool].im;
          H[negate_bool].re = re;
          H[negate_bool].im = im;
          H_mod[negate_bool] = 20.0 * log10(rt_hypotd_snf(re, im));
          H_arg[negate_bool] = rt_atan2d_snf(im, re) * 180.0 /
            3.1415926535897931;
        }

        /*  [&#xFFFD;] */
        exitg1 = 1;
      }

      if (guard1) {
        f_order -= negate_bool;

        /*  Calculate each filter's cell separately */
        if (negate_bool == 1) {
          /*  1st order filter */
          /*  Initialization of the transfer function with the common divider */
          for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
            im_tmp = w[negate_bool] / w_0;
            re = im_tmp * 0.0;
            H_tmp[negate_bool].re = re;
            H_tmp[negate_bool].im = im_tmp;
            if (im_tmp == 0.0) {
              re = 1.0 / (1.0 + re);
              im = 0.0;
            } else {
              b_re = fabs(im_tmp);
              if (1.0 + re > b_re) {
                b_re = im_tmp / (1.0 + re);
                im_tmp = (1.0 + re) + b_re * im_tmp;
                re = (1.0 + b_re * 0.0) / im_tmp;
                im = (0.0 - b_re) / im_tmp;
              } else if (b_re == 1.0 + re) {
                if (1.0 + re > 0.0) {
                  b_re = 0.5;
                } else {
                  b_re = -0.5;
                }

                if (im_tmp > 0.0) {
                  im_tmp = 0.5;
                } else {
                  im_tmp = -0.5;
                }

                re = b_re + 0.0 * im_tmp;
                im = 0.0 * b_re - im_tmp;
              } else {
                b_re = (1.0 + re) / im_tmp;
                im_tmp += b_re * (1.0 + re);
                re = b_re / im_tmp;
                im = (b_re * 0.0 - 1.0) / im_tmp;
              }
            }

            brm = H[negate_bool].re;
            d = H[negate_bool].im;
            b_im = brm * im + d * re;
            brm = brm * re - d * im;
            H[negate_bool].re = brm;
            H[negate_bool].im = b_im;
          }

          switch (filter_T_32) {
           case 1:
            /*  Low-pass filter */
            break;

           case 2:
            /*  High-pass filter */
            for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
              brm = H_tmp[negate_bool].re;
              d = H_tmp[negate_bool].im;
              im_tmp = H[negate_bool].im;
              b_re = H[negate_bool].re;
              im = brm * im_tmp + d * b_re;
              b_re = brm * b_re - d * im_tmp;
              H[negate_bool].re = b_re;
              H[negate_bool].im = im;
            }
            break;

           default:
            /*  Type of filter not supported */
            *err_f = 1;
            exitg1 = 1;
            break;
          }
        } else {
          /*  2nd order filter */
          /*  Initialisation of the transfer function with the common divider */
          y_re = 1.0 / q_0 * 0.0;
          y_im = 1.0 / q_0;
          for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
            b_im = w[negate_bool] / w_0;
            re = b_im * 0.0;
            b_re = re * re - b_im * b_im;
            im_tmp = re * b_im;
            im = im_tmp + im_tmp;
            H_tmp[negate_bool].re = b_re;
            H_tmp[negate_bool].im = im;
            im_tmp = (1.0 + y_re * b_im) + b_re;
            b_im = y_im * b_im + im;
            if (b_im == 0.0) {
              re = 1.0 / im_tmp;
              im = 0.0;
            } else if (im_tmp == 0.0) {
              re = 0.0;
              im = -(1.0 / b_im);
            } else {
              brm = fabs(im_tmp);
              b_re = fabs(b_im);
              if (brm > b_re) {
                b_re = b_im / im_tmp;
                im_tmp += b_re * b_im;
                re = (1.0 + b_re * 0.0) / im_tmp;
                im = (0.0 - b_re) / im_tmp;
              } else if (b_re == brm) {
                if (im_tmp > 0.0) {
                  b_re = 0.5;
                } else {
                  b_re = -0.5;
                }

                if (b_im > 0.0) {
                  im_tmp = 0.5;
                } else {
                  im_tmp = -0.5;
                }

                re = (b_re + 0.0 * im_tmp) / brm;
                im = (0.0 * b_re - im_tmp) / brm;
              } else {
                b_re = im_tmp / b_im;
                im_tmp = b_im + b_re * im_tmp;
                re = b_re / im_tmp;
                im = (b_re * 0.0 - 1.0) / im_tmp;
              }
            }

            brm = H[negate_bool].re;
            d = H[negate_bool].im;
            b_im = brm * im + d * re;
            brm = brm * re - d * im;
            H[negate_bool].re = brm;
            H[negate_bool].im = b_im;
          }

          switch (filter_T_32) {
           case 1:
            /*  Low-pass filter */
            break;

           case 2:
            /*  High-pass filter */
            for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
              brm = H_tmp[negate_bool].re;
              d = H_tmp[negate_bool].im;
              im_tmp = H[negate_bool].im;
              b_re = H[negate_bool].re;
              im = brm * im_tmp + d * b_re;
              b_re = brm * b_re - d * im_tmp;
              H[negate_bool].re = b_re;
              H[negate_bool].im = im;
            }
            break;

           case 3:
            /*  Band-pass filter */
            y_im = 1.0 / (2.0 * q_0 * w_0);
            for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
              brm = w[negate_bool];
              y_re = brm * 0.0;
              im_tmp = brm * y_im;
              brm = H[negate_bool].im;
              d = H[negate_bool].re;
              im = y_re * brm + im_tmp * d;
              d = y_re * d - im_tmp * brm;
              H[negate_bool].re = d;
              H[negate_bool].im = im;
            }
            break;

           case 4:
            /*  Band-stop filter */
            for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
              re = 1.0 + H_tmp[negate_bool].re;
              im = H_tmp[negate_bool].im;
              brm = H[negate_bool].im;
              d = H[negate_bool].re;
              b_im = re * brm + im * d;
              d = re * d - im * brm;
              H[negate_bool].re = d;
              H[negate_bool].im = b_im;
            }
            break;

           default:
            /*  Type of filter not supported */
            *err_f = 1;
            exitg1 = 1;
            break;
          }
        }
      }
    } while (exitg1 == 0);
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void filter_bode_initialize(void)
{
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void filter_bode_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for filter_bode.c
 *
 * [EOF]
 */
