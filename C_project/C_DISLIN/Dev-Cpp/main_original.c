/*
 * File: main.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 10-Jul-2024 11:15:53
 */

/* Include Files */
#include "main.h"
#include <math.h>
#include <stdio.h>

/* Variable Definitions */
static const char cv[20] = {'l',    'o', 'w',    '\x00', '\x00', 'h',   'i',
                            'g',    'h', '\x00', 'b',    'a',    'n',   'd',
                            '\x00', 's', 't',    'o',    'p',    '\x00'};

/* Function Declarations */
static double b_check_num_input(char *c_param);

static void b_check_yes_or_no(char param_p[2]);

static double c_check_num_input(char *c_param);

static int check_num_input(const double limits[2], char *c_param);

static void check_str_input(char param_p[5]);

static void check_yes_or_no(char param_p[2]);

static double d_check_num_input(char *c_param);

static int filter_bode(const double f[100000], double f_0, double q_0, double g,
                       const char f_type[5], int f_order, double H_mod[100000],
                       double H_arg[100000]);

static void power(const creal_T a[100000], creal_T y[100000]);

static double rt_hypotd(double u0, double u1);

/* Function Definitions */
/*
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *  Function: check_num_input()
 *  Goal    : Checks a numerical input parameter given by the user
 *
 *  IN      : - limits : boundaries allowed for the desired parameter
 *            - text_id: text to display related to the desired parameter
 *            - c_param: type of C data
 *  IN/OUT  : - param_p: parameter to set via the user interface
 *  OUT     : -
 *
 *  Copyright 2024 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * Arguments    : char * c_param
 * Return Type  : double
 */
static double b_check_num_input(char *c_param)
{
  char *CLEAR_STDIN;
  double param_p;
  int exitg1;
  int exitg2;
  int nb_params;
  int negate_bool;
  /*  Constant */
  /*  Force the string regular expression in the generated C code for scanf_s */
  CLEAR_STDIN = "%*[^\n]%*1[\n]";
  /*  Initialization */
  /*  Check user's input */
  do {
    exitg1 = 0;
    do {
      exitg2 = 0;
      /*  Ask the user to enter a number  */
      printf("%s", "Cutoff frequency: ");
      fflush(stdout);
      nb_params = scanf_s(c_param, &param_p, 1);
      /*  Check if a number or some chars have been entered */
      if (nb_params == 1) {
        /*  One entry => this is a number */
        negate_bool = 0;
      } else {
        /*  Multiple entries => this is an array of chars */
        negate_bool = 1;
      }
      /*  Post process the keyboard input buffer data */
      if (negate_bool == 1) {
        printf("The value provided is not of the right data type.\n");
        fflush(stdout);
        printf("Please, enter a correct value.\n");
        fflush(stdout);
        /*  Clear the input buffer */
        scanf_s(CLEAR_STDIN);
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);
    /*  Compare the entry to the possible data range */
    if ((param_p >= 1.0) && (param_p <= 1.0E+9)) {
      exitg1 = 1;
    } else {
      printf(
          "For this filter, the parameter should be between %.3f and %.3f.\n",
          1.0, 1.0E+9);
      fflush(stdout);
      printf("Please, enter a correct value.\n");
      fflush(stdout);
    }
  } while (exitg1 == 0);
  /*  The parameter stands into the correct range */
  return param_p;
}

/*
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *  Function: check_yes_or_no()
 *  Goal    : Checks if the given parameter is either 'yes' or 'no'
 *
 *  IN      : - text_id: text to display related to the desired parameter
 *  IN/OUT  : - param_p: parameter to set via the user interface
 *  OUT     : -
 *
 *  Copyright 2024 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * Arguments    : char param_p[2]
 * Return Type  : void
 */
static void b_check_yes_or_no(char param_p[2])
{
  int exitg1;
  int negate_bool_idx_0;
  int negate_bool_idx_1;
  char b_cv[2];
  char cv1[2];
  /*  Constants */
  /*  Initialization */
  /*  sizeof(char) */
  /*  Loop to get and validate user's input */
  do {
    exitg1 = 0;
    /*  Ask the user to enter a selection */
    printf("%s", "Do you want to see Bodes of another filter [y,n]? ");
    fflush(stdout);
    b_cv[0] = '%';
    b_cv[1] = 's';
    scanf_s(&b_cv[0], &param_p[0], 2);
    /*  Compare the entry to the available types */
    b_cv[0] = param_p[0];
    cv1[0] = 'n';
    b_cv[1] = param_p[1];
    cv1[1] = '\x00';
    negate_bool_idx_0 = _strcmpi(&b_cv[0], &cv1[0]);
    b_cv[0] = param_p[0];
    cv1[0] = 'y';
    b_cv[1] = param_p[1];
    cv1[1] = '\x00';
    negate_bool_idx_1 = _strcmpi(&b_cv[0], &cv1[0]);
    if ((negate_bool_idx_0 == 0) || (negate_bool_idx_1 == 0)) {
      exitg1 = 1;
    } else {
      printf("%s\n", "Please, enter [y,Y] for YES or [n,N] for NO.\n");
      fflush(stdout);
      /*  Force the string regular expression in the generated C code for
       * scanf_s */
      /*  Clear the input buffer */
      scanf_s("%*[^\n]%*1[\n]");
    }
  } while (exitg1 == 0);
  /*  Handle graphical windows in C */
}

/*
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *  Function: check_num_input()
 *  Goal    : Checks a numerical input parameter given by the user
 *
 *  IN      : - limits : boundaries allowed for the desired parameter
 *            - text_id: text to display related to the desired parameter
 *            - c_param: type of C data
 *  IN/OUT  : - param_p: parameter to set via the user interface
 *  OUT     : -
 *
 *  Copyright 2024 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * Arguments    : char * c_param
 * Return Type  : double
 */
static double c_check_num_input(char *c_param)
{
  char *CLEAR_STDIN;
  double param_p;
  int exitg1;
  int exitg2;
  int nb_params;
  int negate_bool;
  /*  Constant */
  /*  Force the string regular expression in the generated C code for scanf_s */
  CLEAR_STDIN = "%*[^\n]%*1[\n]";
  /*  Initialization */
  /*  Check user's input */
  do {
    exitg1 = 0;
    do {
      exitg2 = 0;
      /*  Ask the user to enter a number  */
      printf("%s", "Quality factor: ");
      fflush(stdout);
      nb_params = scanf_s(c_param, &param_p, 1);
      /*  Check if a number or some chars have been entered */
      if (nb_params == 1) {
        /*  One entry => this is a number */
        negate_bool = 0;
      } else {
        /*  Multiple entries => this is an array of chars */
        negate_bool = 1;
      }
      /*  Post process the keyboard input buffer data */
      if (negate_bool == 1) {
        printf("The value provided is not of the right data type.\n");
        fflush(stdout);
        printf("Please, enter a correct value.\n");
        fflush(stdout);
        /*  Clear the input buffer */
        scanf_s(CLEAR_STDIN);
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);
    /*  Compare the entry to the possible data range */
    if ((param_p >= 0.1) && (param_p <= 10.0)) {
      exitg1 = 1;
    } else {
      printf(
          "For this filter, the parameter should be between %.3f and %.3f.\n",
          0.1, 10.0);
      fflush(stdout);
      printf("Please, enter a correct value.\n");
      fflush(stdout);
    }
  } while (exitg1 == 0);
  /*  The parameter stands into the correct range */
  return param_p;
}

/*
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *  Function: check_num_input()
 *  Goal    : Checks a numerical input parameter given by the user
 *
 *  IN      : - limits : boundaries allowed for the desired parameter
 *            - text_id: text to display related to the desired parameter
 *            - c_param: type of C data
 *  IN/OUT  : - param_p: parameter to set via the user interface
 *  OUT     : -
 *
 *  Copyright 2024 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * Arguments    : const double limits[2]
 *                char * c_param
 * Return Type  : int
 */
static int check_num_input(const double limits[2], char *c_param)
{
  char *CLEAR_STDIN;
  int exitg1;
  int exitg2;
  int nb_params;
  int negate_bool;
  int param_p;
  /*  Constant */
  /*  Force the string regular expression in the generated C code for scanf_s */
  CLEAR_STDIN = "%*[^\n]%*1[\n]";
  /*  Initialization */
  /*  Check user's input */
  do {
    exitg1 = 0;
    do {
      exitg2 = 0;
      /*  Ask the user to enter a number  */
      printf("%s", "Order of the filter: ");
      fflush(stdout);
      nb_params = scanf_s(c_param, &param_p, 1);
      /*  Check if a number or some chars have been entered */
      if (nb_params == 1) {
        /*  One entry => this is a number */
        negate_bool = 0;
      } else {
        /*  Multiple entries => this is an array of chars */
        negate_bool = 1;
      }
      /*  Post process the keyboard input buffer data */
      if (negate_bool == 1) {
        printf("The value provided is not of the right data type.\n");
        fflush(stdout);
        printf("Please, enter a correct value.\n");
        fflush(stdout);
        /*  Clear the input buffer */
        scanf_s(CLEAR_STDIN);
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);
    /*  Compare the entry to the possible data range */
    if ((param_p >= limits[0]) && (param_p <= limits[1])) {
      exitg1 = 1;
    } else {
      printf(
          "For this filter, the parameter should be between %.3f and %.3f.\n",
          limits[0], limits[1]);
      fflush(stdout);
      printf("Please, enter a correct value.\n");
      fflush(stdout);
    }
  } while (exitg1 == 0);
  /*  The parameter stands into the correct range */
  return param_p;
}

/*
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *  Function: check_str_input()
 *  Goal    : Checks string input parameter given by the user
 *
 *  IN      : - text_id: text to display related to the desired parameter
 *  IN/OUT  : - param_p: parameter to set via the user interface
 *  OUT     : -
 *
 *  Copyright 2024 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * Arguments    : char param_p[5]
 * Return Type  : void
 */
static void check_str_input(char param_p[5])
{
  int b_i;
  int exitg1;
  int i;
  int negate_bool;
  char cv1[5];
  char cv2[5];
  char b_cv[3];
  boolean_T exitg2;
  /*  Constants */
  /*  Initialization */
  negate_bool = 1;
  /*  sizeof(char) */
  /*  Loop to get and validate user's input */
  do {
    exitg1 = 0;
    /*  Ask the user to enter a filter type */
    printf("%s", "Type of filter [low][high][band][stop]: ");
    fflush(stdout);
    b_cv[0] = '%';
    b_cv[1] = '4';
    b_cv[2] = 's';
    scanf_s(&b_cv[0], &param_p[0], 8);
    /*  Compare the entry to the available types */
    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i < 4)) {
      for (b_i = 0; b_i < 5; b_i++) {
        cv1[b_i] = param_p[b_i];
        cv2[b_i] = cv[b_i + 5 * i];
      }
      negate_bool = strcmp(&cv1[0], &cv2[0]);
      if (negate_bool == 0) {
        exitg2 = true;
      } else {
        i++;
      }
    }
    if (negate_bool == 0) {
      exitg1 = 1;
    } else {
      /*  No right type selected */
      printf("%s\n", "Unknown filter type. Please, enter a correct one.");
      fflush(stdout);
      /*  Force the string regular expression in the generated C code for
       * scanf_s */
      /*  Clear the input buffer */
      scanf_s("%*[^\n]%*1[\n]");
    }
  } while (exitg1 == 0);
}

/*
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *  Function: check_yes_or_no()
 *  Goal    : Checks if the given parameter is either 'yes' or 'no'
 *
 *  IN      : - text_id: text to display related to the desired parameter
 *  IN/OUT  : - param_p: parameter to set via the user interface
 *  OUT     : -
 *
 *  Copyright 2024 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * Arguments    : char param_p[2]
 * Return Type  : void
 */
static void check_yes_or_no(char param_p[2])
{
  int exitg1;
  int negate_bool_idx_0;
  int negate_bool_idx_1;
  char b_cv[2];
  char cv1[2];
  /*  Constants */
  /*  Initialization */
  /*  sizeof(char) */
  /*  Loop to get and validate user's input */
  do {
    exitg1 = 0;
    /*  Ask the user to enter a selection */
    printf("%s", "Do you want to keep the previous Bodes [y,n]? ");
    fflush(stdout);
    b_cv[0] = '%';
    b_cv[1] = 's';
    scanf_s(&b_cv[0], &param_p[0], 2);
    /*  Compare the entry to the available types */
    b_cv[0] = param_p[0];
    cv1[0] = 'n';
    b_cv[1] = param_p[1];
    cv1[1] = '\x00';
    negate_bool_idx_0 = _strcmpi(&b_cv[0], &cv1[0]);
    b_cv[0] = param_p[0];
    cv1[0] = 'y';
    b_cv[1] = param_p[1];
    cv1[1] = '\x00';
    negate_bool_idx_1 = _strcmpi(&b_cv[0], &cv1[0]);
    if ((negate_bool_idx_0 == 0) || (negate_bool_idx_1 == 0)) {
      exitg1 = 1;
    } else {
      printf("%s\n", "Please, enter [y,Y] for YES or [n,N] for NO.\n");
      fflush(stdout);
      /*  Force the string regular expression in the generated C code for
       * scanf_s */
      /*  Clear the input buffer */
      scanf_s("%*[^\n]%*1[\n]");
    }
  } while (exitg1 == 0);
  /*  Handle graphical windows in C */
}

/*
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *  Function: check_num_input()
 *  Goal    : Checks a numerical input parameter given by the user
 *
 *  IN      : - limits : boundaries allowed for the desired parameter
 *            - text_id: text to display related to the desired parameter
 *            - c_param: type of C data
 *  IN/OUT  : - param_p: parameter to set via the user interface
 *  OUT     : -
 *
 *  Copyright 2024 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * Arguments    : char * c_param
 * Return Type  : double
 */
static double d_check_num_input(char *c_param)
{
  char *CLEAR_STDIN;
  double param_p;
  int exitg1;
  int exitg2;
  int nb_params;
  int negate_bool;
  /*  Constant */
  /*  Force the string regular expression in the generated C code for scanf_s */
  CLEAR_STDIN = "%*[^\n]%*1[\n]";
  /*  Initialization */
  /*  Check user's input */
  do {
    exitg1 = 0;
    do {
      exitg2 = 0;
      /*  Ask the user to enter a number  */
      printf("%s", "Linear gain of the filter: ");
      fflush(stdout);
      nb_params = scanf_s(c_param, &param_p, 1);
      /*  Check if a number or some chars have been entered */
      if (nb_params == 1) {
        /*  One entry => this is a number */
        negate_bool = 0;
      } else {
        /*  Multiple entries => this is an array of chars */
        negate_bool = 1;
      }
      /*  Post process the keyboard input buffer data */
      if (negate_bool == 1) {
        printf("The value provided is not of the right data type.\n");
        fflush(stdout);
        printf("Please, enter a correct value.\n");
        fflush(stdout);
        /*  Clear the input buffer */
        scanf_s(CLEAR_STDIN);
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);
    /*  Compare the entry to the possible data range */
    if ((param_p >= 0.001) && (param_p <= 1000.0)) {
      exitg1 = 1;
    } else {
      printf(
          "For this filter, the parameter should be between %.3f and %.3f.\n",
          0.001, 1000.0);
      fflush(stdout);
      printf("Please, enter a correct value.\n");
      fflush(stdout);
    }
  } while (exitg1 == 0);
  /*  The parameter stands into the correct range */
  return param_p;
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
 *            - H_arg : argument of the transfer function in [°]
 *            - err_f : returns execution error related to input parameters
 *
 *  Copyright 2024 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * Arguments    : const double f[100000]
 *                double f_0
 *                double q_0
 *                double g
 *                const char f_type[5]
 *                int f_order
 *                double H_mod[100000]
 *                double H_arg[100000]
 * Return Type  : int
 */
static int filter_bode(const double f[100000], double f_0, double q_0, double g,
                       const char f_type[5], int f_order, double H_mod[100000],
                       double H_arg[100000])
{
  static creal_T H[100000];
  static creal_T b_H_tmp[100000];
  static creal_T dcv[100000];
  static double H_tmp[100000];
  static double w[100000];
  double H_tmp_im;
  double H_tmp_re;
  double a_im;
  double b_a_im;
  double b_bim;
  double b_d;
  double b_im;
  double b_re;
  double b_re_tmp;
  double b_s;
  double bi;
  double bim;
  double br;
  double brm;
  double c_d;
  double c_im;
  double c_re;
  double c_re_tmp;
  double d;
  double d1;
  double d2;
  double d3;
  double d_im;
  double d_re_tmp;
  double e_re_tmp;
  double f_re_tmp;
  double g_re_tmp;
  double h_re_tmp;
  double i_re_tmp;
  double im;
  double j_re_tmp;
  double k_re_tmp;
  double l_re_tmp;
  double m_re_tmp;
  double re;
  double re_tmp;
  double s;
  double w_0;
  int b_i;
  int err_f;
  int exitg1;
  int filter_T_32;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int i6;
  int i7;
  int i8;
  int k;
  int n_cell_order;
  int negate_bool;
  char b_cv[5];
  char cv1[5];
  boolean_T guard1;
  /*  Constants */
  /*  Integer representation of filter's type */
  /*  Initialization */
  err_f = 0;
  filter_T_32 = 0;
  /*  Pulsation's vectors */
  for (i = 0; i < 100000; i++) {
    H[i].re = 1.0;
    H[i].im = 0.0;
    H_mod[i] = 0.0;
    H_arg[i] = 0.0;
    w[i] = 6.2831853071795862 * f[i];
  }
  w_0 = 6.2831853071795862 * f_0;
  /*  Set switches to work with integer */
  for (b_i = 0; b_i < 4; b_i++) {
    for (i1 = 0; i1 < 5; i1++) {
      b_cv[i1] = f_type[i1];
      cv1[i1] = cv[i1 + 5 * b_i];
    }
    negate_bool = strcmp(&b_cv[0], &cv1[0]);
    if (negate_bool == 0) {
      filter_T_32 = b_i + 1;
    }
  }
  /*  Test the order of the filter against the filter type */
  if ((filter_T_32 > 2) && (f_order - ((f_order >> 1) << 1) != 0)) {
    /*  For band-pass and stop-band filters odd orders are not feasible */
    err_f = 2;
  } else {
    /*  Bode diagram calculation */
    do {
      exitg1 = 0;
      guard1 = false;
      if (f_order > 1) {
        n_cell_order = 2;
        guard1 = true;
      } else if (f_order == 1) {
        n_cell_order = 1;
        guard1 = true;
      } else {
        /*  All filter's cells have been calculated */
        /*  Apply the filter gain only once */
        /*  Retrieves module and argument of the transfer function H */
        /*  [dB] */
        for (k = 0; k < 100000; k++) {
          re = g * H[k].re;
          im = g * H[k].im;
          H[k].re = re;
          H[k].im = im;
          H_mod[k] = 20.0 * log10(rt_hypotd(re, im));
          H_arg[k] = atan2(im, re) * 180.0 / 3.1415926535897931;
        }
        /*  [°] */
        exitg1 = 1;
      }
      if (guard1) {
        f_order -= n_cell_order;
        /*  Calculate each filter's cell separately */
        if (n_cell_order == 1) {
          /*  1st order filter */
          /*  Initialization of the transfer function with the common divider */
          for (i3 = 0; i3 < 100000; i3++) {
            b_im = w[i3] / w_0;
            b_H_tmp[i3].re = 0.0;
            b_H_tmp[i3].im = b_im;
            if (b_im == 0.0) {
              b_re = 1.0;
              c_im = 0.0;
            } else {
              bim = fabs(b_im);
              if (bim < 1.0) {
                b_d = b_im * b_im + 1.0;
                b_re = 1.0 / b_d;
                c_im = (0.0 - b_im) / b_d;
              } else if (bim == 1.0) {
                b_re = 0.5;
                if (b_im > 0.0) {
                  d1 = 0.5;
                } else {
                  d1 = -0.5;
                }
                c_im = 0.0 - d1;
              } else {
                s = 1.0 / b_im;
                b_d = b_im + s;
                b_re = s / b_d;
                c_im = -1.0 / b_d;
              }
            }
            c_re_tmp = H[i3].re;
            d_re_tmp = H[i3].im;
            H[i3].re = c_re_tmp * b_re - d_re_tmp * c_im;
            H[i3].im = c_re_tmp * c_im + d_re_tmp * b_re;
          }
          switch (filter_T_32) {
          case 1:
            /*  Low-pass filter */
            break;
          case 2:
            /*  High-pass filter */
            for (i4 = 0; i4 < 100000; i4++) {
              re_tmp = b_H_tmp[i4].im;
              b_re_tmp = H[i4].re;
              H[i4].re = 0.0 - re_tmp * H[i4].im;
              H[i4].im = re_tmp * b_re_tmp;
            }
            break;
          default:
            /*  Type of filter not supported */
            err_f = 1;
            exitg1 = 1;
            break;
          }
        } else {
          /*  2nd order filter */
          /*  Initialisation of the transfer function with the common divider */
          for (i2 = 0; i2 < 100000; i2++) {
            d = w[i2] / w_0;
            H_tmp[i2] = d;
            dcv[i2].re = 0.0;
            dcv[i2].im = d;
          }
          power(dcv, b_H_tmp);
          a_im = 1.0 / q_0;
          for (i5 = 0; i5 < 100000; i5++) {
            br = b_H_tmp[i5].re + 1.0;
            bi = a_im * H_tmp[i5] + b_H_tmp[i5].im;
            if (bi == 0.0) {
              c_re = 1.0 / br;
              d_im = 0.0;
            } else if (br == 0.0) {
              c_re = 0.0;
              d_im = -(1.0 / bi);
            } else {
              brm = fabs(br);
              b_bim = fabs(bi);
              if (brm > b_bim) {
                b_s = bi / br;
                c_d = br + b_s * bi;
                c_re = 1.0 / c_d;
                d_im = (0.0 - b_s) / c_d;
              } else if (b_bim == brm) {
                if (br > 0.0) {
                  d2 = 0.5;
                } else {
                  d2 = -0.5;
                }
                c_re = d2 / brm;
                if (bi > 0.0) {
                  d3 = 0.5;
                } else {
                  d3 = -0.5;
                }
                d_im = (0.0 - d3) / brm;
              } else {
                b_s = br / bi;
                c_d = bi + b_s * br;
                c_re = b_s / c_d;
                d_im = -1.0 / c_d;
              }
            }
            j_re_tmp = H[i5].re;
            l_re_tmp = H[i5].im;
            H[i5].re = j_re_tmp * c_re - l_re_tmp * d_im;
            H[i5].im = j_re_tmp * d_im + l_re_tmp * c_re;
          }
          switch (filter_T_32) {
          case 1:
            /*  Low-pass filter */
            break;
          case 2:
            /*  High-pass filter */
            for (i6 = 0; i6 < 100000; i6++) {
              e_re_tmp = b_H_tmp[i6].re;
              f_re_tmp = H[i6].im;
              g_re_tmp = b_H_tmp[i6].im;
              h_re_tmp = H[i6].re;
              H[i6].re = e_re_tmp * h_re_tmp - g_re_tmp * f_re_tmp;
              H[i6].im = e_re_tmp * f_re_tmp + g_re_tmp * h_re_tmp;
            }
            break;
          case 3:
            /*  Band-pass filter */
            a_im = 1.0 / (2.0 * q_0 * w_0);
            for (i8 = 0; i8 < 100000; i8++) {
              b_a_im = w[i8] * a_im;
              m_re_tmp = H[i8].re;
              H[i8].re = 0.0 - b_a_im * H[i8].im;
              H[i8].im = b_a_im * m_re_tmp;
            }
            break;
          case 4:
            /*  Band-stop filter */
            for (i7 = 0; i7 < 100000; i7++) {
              H_tmp_re = b_H_tmp[i7].re + 1.0;
              H_tmp_im = b_H_tmp[i7].im;
              i_re_tmp = H[i7].im;
              k_re_tmp = H[i7].re;
              H[i7].re = H_tmp_re * k_re_tmp - H_tmp_im * i_re_tmp;
              H[i7].im = H_tmp_re * i_re_tmp + H_tmp_im * k_re_tmp;
            }
            break;
          default:
            /*  Type of filter not supported */
            err_f = 1;
            exitg1 = 1;
            break;
          }
        }
      }
    } while (exitg1 == 0);
  }
  return err_f;
}

/*
 * Arguments    : const creal_T a[100000]
 *                creal_T y[100000]
 * Return Type  : void
 */
static void power(const creal_T a[100000], creal_T y[100000])
{
  double ai_tmp;
  double ar_tmp;
  double b_im;
  double b_re;
  double r;
  double y_im;
  double y_re;
  int k;
  for (k = 0; k < 100000; k++) {
    ar_tmp = a[k].re;
    ai_tmp = a[k].im;
    if ((ai_tmp == 0.0) && (ar_tmp >= 0.0)) {
      y[k].re = pow(ar_tmp, 2.0);
      y[k].im = 0.0;
    } else if (ar_tmp == 0.0) {
      y[k].re = -pow(ai_tmp, 2.0);
      y[k].im = 0.0;
    } else {
      if (ai_tmp == 0.0) {
        if (ar_tmp < 0.0) {
          b_re = log(fabs(ar_tmp));
          b_im = 3.1415926535897931;
        } else {
          b_re = log(fabs(ar_tmp));
          b_im = 0.0;
        }
      } else if ((fabs(ar_tmp) > 8.9884656743115785E+307) ||
                 (fabs(ai_tmp) > 8.9884656743115785E+307)) {
        b_re = log(rt_hypotd(ar_tmp / 2.0, ai_tmp / 2.0)) + 0.69314718055994529;
        b_im = atan2(ai_tmp, ar_tmp);
      } else {
        b_re = log(rt_hypotd(ar_tmp, ai_tmp));
        b_im = atan2(ai_tmp, ar_tmp);
      }
      y_re = 2.0 * b_re;
      y_im = 2.0 * b_im;
      if (y_re == 0.0) {
        y[k].re = cos(y_im);
        y[k].im = sin(y_im);
      } else if (y_im == 0.0) {
        y[k].re = exp(y_re);
        y[k].im = 0.0;
      } else {
        r = exp(y_re / 2.0);
        y[k].re = r * (r * cos(y_im));
        y[k].im = r * (r * sin(y_im));
      }
    }
  }
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_hypotd(double u0, double u1)
{
  double a;
  double b;
  double y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = b * sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * sqrt(b * b + 1.0);
  } else {
    y = a * 1.4142135623730951;
  }
  return y;
}

/*
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *  Function: main()
 *  Goal    : Main C function of the executable
 *
 *  IN      : -
 *  IN/OUT  : -
 *  OUT     : -
 *
 *  Copyright 2024 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * Arguments    : void
 * Return Type  : int
 */
int main(void)
{
  static double H_arg[100000];
  static double H_mod[100000];
  static double y[100000];
  static double z1[100000];
  static const char cv2[5] = "band";
  static const char cv3[5] = "stop";
  char *INTEGER;
  char *LONG_DOUBLE;
  double dv[2];
  double f_0;
  double g;
  double q_0;
  int b_k;
  int error_flag;
  int exitg1;
  int i;
  int i1;
  int k;
  int n_f;
  int neg_band_bool;
  int neg_stop_bool;
  int negate_bool;
  char b_cv[5];
  char f_t[5];
  char cv1[2];
  char new_bodes[2];
  /*  Functions that are not translated into C code */
  /*  Constants */
  INTEGER = "%d";
  LONG_DOUBLE = "%lf";
  /*  Initialization */
  q_0 = 0.0;
  /*  Definition of the logarithmic frequency range */
  y[99999] = 9.0;
  y[0] = 0.0;
  for (k = 0; k < 99998; k++) {
    y[k + 1] = ((double)k + 1.0) * 9.0000900009000085E-5;
  }
  for (b_k = 0; b_k < 100000; b_k++) {
    z1[b_k] = pow(10.0, y[b_k]);
  }
  /*  Program title */
  printf("%s\n", "-------------------------------------------------------------"
                 "------------------");
  fflush(stdout);
  printf("%s\n", "--------------------------- FILTER DESIGN AND VIEWER "
                 "--------------------------");
  fflush(stdout);
  printf("%s\n", "-------------------------------------------------------------"
                 "------------------");
  fflush(stdout);
  /*  Forever loop */
  do {
    exitg1 = 0;
    /*  Ask for filter's parameters */
    check_str_input(f_t);
    for (i = 0; i < 5; i++) {
      b_cv[i] = cv2[i];
    }
    neg_band_bool = strcmp(&f_t[0], &b_cv[0]);
    for (i1 = 0; i1 < 5; i1++) {
      b_cv[i1] = cv3[i1];
    }
    neg_stop_bool = strcmp(&f_t[0], &b_cv[0]);
    if ((neg_band_bool == 0) || (neg_stop_bool == 0)) {
      dv[0] = 2.0;
      dv[1] = 10.0;
      n_f = check_num_input(dv, INTEGER);
    } else {
      dv[0] = 1.0;
      dv[1] = 10.0;
      n_f = check_num_input(dv, INTEGER);
    }
    f_0 = b_check_num_input(LONG_DOUBLE);
    if (n_f > 1) {
      q_0 = c_check_num_input(LONG_DOUBLE);
    }
    g = d_check_num_input(LONG_DOUBLE);
    /*  Bodes calculation */
    error_flag = filter_bode(z1, f_0, q_0, g, f_t, n_f, H_mod, H_arg);
    /*  Display of results (target dependent) */
    /*  Ask the user if he wants to keep the previous graphs */
    check_yes_or_no(new_bodes);
    cv1[0] = 'n';
    cv1[1] = '\x00';
    _strcmpi(&new_bodes[0], &cv1[0]);
    /*  Ask the user if he wants to see other filter's Bodes */
    b_check_yes_or_no(new_bodes);
    cv1[0] = 'n';
    cv1[1] = '\x00';
    negate_bool = _strcmpi(&new_bodes[0], &cv1[0]);
    if (negate_bool == 0) {
      exitg1 = 1;
    } else {
      printf("%s\n", "---------------------------------------------------------"
                     "----------------------");
      fflush(stdout);
    }
  } while (exitg1 == 0);
  return error_flag;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_initialize(void)
{
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
