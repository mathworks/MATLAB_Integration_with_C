/*
 * File: main.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 30-Apr-2018 17:05:27
 */

/* Include Files */
#include "main.h"
#include <stdio.h>

/* Type Definitions */

/* Variable Definitions */
static const char cv0[20] = { 'l', 'h', 'b', 's', 'o', 'i', 'a', 't', 'w', 'g',
  'n', 'o', '\x00', 'h', 'd', 'p', '\x00', '\x00', '\x00', '\x00' };

/* Function Declarations */
static void angle(const creal_T x[100000], double y[100000]);
static void b_abs(const creal_T x[100000], double y[100000]);
static void b_check_num_input(double *param_p, const double limits[2], char
  * c_param);
static void b_check_yes_or_no(char param_p[2]);
static void b_log10(double x[100000]);
static int b_mod(int x);
static void b_power(const creal_T a[100000], creal_T y[100000]);
static void c_check_num_input(double *param_p, const double limits[2], char
  * c_param);
static void check_num_input(int *param_p, const double limits[2], char * c_param);
static void check_str_input(char param_p[5]);
static void check_yes_or_no(char param_p[2]);
static void d_check_num_input(double *param_p, const double limits[2], char
  * c_param);
static void filter_bode(const double f[100000], double f_0, double q_0, double g,
  const char f_type[5], int f_order, double H_mod[100000], double H_arg[100000],
  int *err_f);
static void logspace(double d1, double d2, double y[100000]);
static void power(double a, const double b[100000], double y[100000]);
static double rt_hypotd(double u0, double u1);

/* Function Definitions */

/*
 * Arguments    : const creal_T x[100000]
 *                double y[100000]
 * Return Type  : void
 */
static void angle(const creal_T x[100000], double y[100000])
{
  int k;
  for (k = 0; k < 100000; k++) {
    y[k] = atan2(x[k].im, x[k].re);
  }
}

/*
 * Arguments    : const creal_T x[100000]
 *                double y[100000]
 * Return Type  : void
 */
static void b_abs(const creal_T x[100000], double y[100000])
{
  int k;
  for (k = 0; k < 100000; k++) {
    y[k] = rt_hypotd(x[k].re, x[k].im);
  }
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
 *  Copyright 2018 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * Arguments    : double *param_p
 *                const double limits[2]
 *                char * c_param
 * Return Type  : void
 */
static void b_check_num_input(double *param_p, const double limits[2], char
  * c_param)
{
  char * CLEAR_STDIN;
  int exitg1;
  int exitg2;
  int nb_params;

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
      nb_params = scanf_s(c_param, param_p, 1);

      /*  Check if a number or some chars have been entered */
      if (nb_params == 1) {
        /*  One entry => this is a number */
        nb_params = 0;
      } else {
        /*  Multiple entries => this is an array of chars */
        nb_params = 1;
      }

      /*  Post process the keyboard input buffer data */
      if (nb_params == 1) {
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
    if ((*param_p >= limits[0]) && (*param_p <= limits[1])) {
      exitg1 = 1;
    } else {
      printf("For this filter, the parameter should be between %.3f and %.3f.\n",
             limits[0], limits[1]);
      fflush(stdout);
      printf("Please, enter a correct value.\n");
      fflush(stdout);
    }
  } while (exitg1 == 0);

  /*  The parameter stands into the correct range */
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
 *  Copyright 2018 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * Arguments    : char param_p[2]
 * Return Type  : void
 */
static void b_check_yes_or_no(char param_p[2])
{
  int exitg1;
  int negate_bool_idx_1;
  char N_CHAR[2];
  static const char cv6[2] = { '%', 's' };

  int negate_bool_idx_0;
  char b_param_p[2];
  static const char b_N_CHAR[2] = { 'n', '\x00' };

  static const char Y_CHAR[2] = { 'y', '\x00' };

  /*  Constants */
  /*  Initialization */
  /*  sizeof(char) */
  /*  Loop to get and validate user's input */
  do {
    exitg1 = 0;

    /*  Ask the user to enter a selection */
    printf("%s", "Do you want to see Bodes of another filter [y,n]? ");
    fflush(stdout);
    for (negate_bool_idx_1 = 0; negate_bool_idx_1 < 2; negate_bool_idx_1++) {
      N_CHAR[negate_bool_idx_1] = cv6[negate_bool_idx_1];
    }

    scanf_s(N_CHAR, param_p, 2);

    /*  Compare the entry to the available types */
    for (negate_bool_idx_1 = 0; negate_bool_idx_1 < 2; negate_bool_idx_1++) {
      b_param_p[negate_bool_idx_1] = param_p[negate_bool_idx_1];
      N_CHAR[negate_bool_idx_1] = b_N_CHAR[negate_bool_idx_1];
    }

    negate_bool_idx_0 = _strcmpi(b_param_p, N_CHAR);
    for (negate_bool_idx_1 = 0; negate_bool_idx_1 < 2; negate_bool_idx_1++) {
      b_param_p[negate_bool_idx_1] = param_p[negate_bool_idx_1];
      N_CHAR[negate_bool_idx_1] = Y_CHAR[negate_bool_idx_1];
    }

    negate_bool_idx_1 = _strcmpi(b_param_p, N_CHAR);
    if ((negate_bool_idx_0 == 0) || (negate_bool_idx_1 == 0)) {
      exitg1 = 1;
    } else {
      printf("%s\n", "Please, enter [y,Y] for YES or [n,N] for NO.\n");
      fflush(stdout);

      /*  Force the string regular expression in the generated C code for scanf_s */
      /*  Clear the input buffer */
      scanf_s("%*[^\n]%*1[\n]");
    }
  } while (exitg1 == 0);

  /*  Handle graphical windows in C */
}

/*
 * Arguments    : double x[100000]
 * Return Type  : void
 */
static void b_log10(double x[100000])
{
  int k;
  for (k = 0; k < 100000; k++) {
    x[k] = log10(x[k]);
  }
}

/*
 * Arguments    : int x
 * Return Type  : int
 */
static int b_mod(int x)
{
  return x - ((x >> 1) << 1);
}

/*
 * Arguments    : const creal_T a[100000]
 *                creal_T y[100000]
 * Return Type  : void
 */
static void b_power(const creal_T a[100000], creal_T y[100000])
{
  int k;
  for (k = 0; k < 100000; k++) {
    y[k].re = a[k].re * a[k].re - a[k].im * a[k].im;
    y[k].im = a[k].re * a[k].im + a[k].im * a[k].re;
  }
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
 *  Copyright 2018 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * Arguments    : double *param_p
 *                const double limits[2]
 *                char * c_param
 * Return Type  : void
 */
static void c_check_num_input(double *param_p, const double limits[2], char
  * c_param)
{
  char * CLEAR_STDIN;
  int exitg1;
  int exitg2;
  int nb_params;

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
      nb_params = scanf_s(c_param, param_p, 1);

      /*  Check if a number or some chars have been entered */
      if (nb_params == 1) {
        /*  One entry => this is a number */
        nb_params = 0;
      } else {
        /*  Multiple entries => this is an array of chars */
        nb_params = 1;
      }

      /*  Post process the keyboard input buffer data */
      if (nb_params == 1) {
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
    if ((*param_p >= limits[0]) && (*param_p <= limits[1])) {
      exitg1 = 1;
    } else {
      printf("For this filter, the parameter should be between %.3f and %.3f.\n",
             limits[0], limits[1]);
      fflush(stdout);
      printf("Please, enter a correct value.\n");
      fflush(stdout);
    }
  } while (exitg1 == 0);

  /*  The parameter stands into the correct range */
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
 *  Copyright 2018 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * Arguments    : int *param_p
 *                const double limits[2]
 *                char * c_param
 * Return Type  : void
 */
static void check_num_input(int *param_p, const double limits[2], char * c_param)
{
  char * CLEAR_STDIN;
  int exitg1;
  int exitg2;
  int nb_params;

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
      nb_params = scanf_s(c_param, param_p, 1);

      /*  Check if a number or some chars have been entered */
      if (nb_params == 1) {
        /*  One entry => this is a number */
        nb_params = 0;
      } else {
        /*  Multiple entries => this is an array of chars */
        nb_params = 1;
      }

      /*  Post process the keyboard input buffer data */
      if (nb_params == 1) {
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
    if ((*param_p >= limits[0]) && (*param_p <= limits[1])) {
      exitg1 = 1;
    } else {
      printf("For this filter, the parameter should be between %.3f and %.3f.\n",
             limits[0], limits[1]);
      fflush(stdout);
      printf("Please, enter a correct value.\n");
      fflush(stdout);
    }
  } while (exitg1 == 0);

  /*  The parameter stands into the correct range */
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
 *  Copyright 2018 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * Arguments    : char param_p[5]
 * Return Type  : void
 */
static void check_str_input(char param_p[5])
{
  int negate_bool;
  int exitg1;
  int i0;
  char cv3[3];
  static const char cv4[3] = { '%', '4', 's' };

  int i;
  boolean_T exitg2;
  char b_param_p[5];
  char FILTER[5];

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
    for (i0 = 0; i0 < 3; i0++) {
      cv3[i0] = cv4[i0];
    }

    scanf_s(cv3, param_p, 8);

    /*  Compare the entry to the available types */
    i = 1;
    exitg2 = false;
    while ((!exitg2) && (i < 5)) {
      for (i0 = 0; i0 < 5; i0++) {
        b_param_p[i0] = param_p[i0];
        FILTER[i0] = cv0[(i + (i0 << 2)) - 1];
      }

      negate_bool = strcmp(b_param_p, FILTER);
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

      /*  Force the string regular expression in the generated C code for scanf_s */
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
 *  Copyright 2018 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * Arguments    : char param_p[2]
 * Return Type  : void
 */
static void check_yes_or_no(char param_p[2])
{
  int exitg1;
  int negate_bool_idx_1;
  char N_CHAR[2];
  static const char cv5[2] = { '%', 's' };

  int negate_bool_idx_0;
  char b_param_p[2];
  static const char b_N_CHAR[2] = { 'n', '\x00' };

  static const char Y_CHAR[2] = { 'y', '\x00' };

  /*  Constants */
  /*  Initialization */
  /*  sizeof(char) */
  /*  Loop to get and validate user's input */
  do {
    exitg1 = 0;

    /*  Ask the user to enter a selection */
    printf("%s", "Do you want to keep the previous Bodes [y,n]? ");
    fflush(stdout);
    for (negate_bool_idx_1 = 0; negate_bool_idx_1 < 2; negate_bool_idx_1++) {
      N_CHAR[negate_bool_idx_1] = cv5[negate_bool_idx_1];
    }

    scanf_s(N_CHAR, param_p, 2);

    /*  Compare the entry to the available types */
    for (negate_bool_idx_1 = 0; negate_bool_idx_1 < 2; negate_bool_idx_1++) {
      b_param_p[negate_bool_idx_1] = param_p[negate_bool_idx_1];
      N_CHAR[negate_bool_idx_1] = b_N_CHAR[negate_bool_idx_1];
    }

    negate_bool_idx_0 = _strcmpi(b_param_p, N_CHAR);
    for (negate_bool_idx_1 = 0; negate_bool_idx_1 < 2; negate_bool_idx_1++) {
      b_param_p[negate_bool_idx_1] = param_p[negate_bool_idx_1];
      N_CHAR[negate_bool_idx_1] = Y_CHAR[negate_bool_idx_1];
    }

    negate_bool_idx_1 = _strcmpi(b_param_p, N_CHAR);
    if ((negate_bool_idx_0 == 0) || (negate_bool_idx_1 == 0)) {
      exitg1 = 1;
    } else {
      printf("%s\n", "Please, enter [y,Y] for YES or [n,N] for NO.\n");
      fflush(stdout);

      /*  Force the string regular expression in the generated C code for scanf_s */
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
 *  Copyright 2018 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * Arguments    : double *param_p
 *                const double limits[2]
 *                char * c_param
 * Return Type  : void
 */
static void d_check_num_input(double *param_p, const double limits[2], char
  * c_param)
{
  char * CLEAR_STDIN;
  int exitg1;
  int exitg2;
  int nb_params;

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
      nb_params = scanf_s(c_param, param_p, 1);

      /*  Check if a number or some chars have been entered */
      if (nb_params == 1) {
        /*  One entry => this is a number */
        nb_params = 0;
      } else {
        /*  Multiple entries => this is an array of chars */
        nb_params = 1;
      }

      /*  Post process the keyboard input buffer data */
      if (nb_params == 1) {
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
    if ((*param_p >= limits[0]) && (*param_p <= limits[1])) {
      exitg1 = 1;
    } else {
      printf("For this filter, the parameter should be between %.3f and %.3f.\n",
             limits[0], limits[1]);
      fflush(stdout);
      printf("Please, enter a correct value.\n");
      fflush(stdout);
    }
  } while (exitg1 == 0);

  /*  The parameter stands into the correct range */
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
static void filter_bode(const double f[100000], double f_0, double q_0, double g,
  const char f_type[5], int f_order, double H_mod[100000], double H_arg[100000],
  int *err_f)
{
  int filter_T_32;
  int negate_bool;
  double w_0;
  static creal_T H[100000];
  int i;
  static double w[100000];
  char b_f_type[5];
  char TYPE[5];
  int exitg1;
  boolean_T guard1 = false;
  double y_im;
  double bi;
  static creal_T dcv0[100000];
  static creal_T dcv1[100000];
  double im;
  double re;
  double br;
  double brm;

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
      TYPE[negate_bool] = cv0[i + (negate_bool << 2)];
    }

    negate_bool = strcmp(b_f_type, TYPE);
    if (negate_bool == 0) {
      filter_T_32 = i + 1;
    }
  }

  /*  Test the order of the filter against the filter type */
  if ((filter_T_32 > 2) && (b_mod(f_order) != 0)) {
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
        for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
          H[negate_bool].re *= g;
          H[negate_bool].im *= g;
        }

        /*  Apply the filter gain only once */
        /*  Retrieves module and argument of the transfer function H */
        b_abs(H, H_mod);
        b_log10(H_mod);

        /*  [dB] */
        angle(H, H_arg);
        for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
          H_mod[negate_bool] *= 20.0;
          H_arg[negate_bool] = H_arg[negate_bool] * 180.0 / 3.1415926535897931;
        }

        /*  [°] */
        exitg1 = 1;
      }

      if (guard1) {
        f_order -= negate_bool;

        /*  Calculate each filter's cell separately */
        if (negate_bool == 1) {
          /*  1st order filter */
          /*  Initialization of the transfer function with the common divider */
          for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
            bi = w[negate_bool] / w_0;
            if (bi == 0.0) {
              re = 1.0;
              im = 0.0;
            } else {
              im = fabs(bi);
              if (1.0 > im) {
                im = 1.0 + bi * bi;
                re = 1.0 / im;
                im = (0.0 - bi) / im;
              } else if (im == 1.0) {
                re = 0.5;
                if (bi > 0.0) {
                  im = 0.5;
                } else {
                  im = -0.5;
                }

                im = 0.0 - im;
              } else {
                brm = 1.0 / bi;
                im = bi + brm;
                re = brm / im;
                im = -1.0 / im;
              }
            }

            br = H[negate_bool].re;
            H[negate_bool].re = H[negate_bool].re * re - H[negate_bool].im * im;
            H[negate_bool].im = br * im + H[negate_bool].im * re;
          }

          switch (filter_T_32) {
           case 1:
            /*  Low-pass filter */
            break;

           case 2:
            /*  High-pass filter */
            for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
              im = w[negate_bool] / w_0;
              br = H[negate_bool].re;
              H[negate_bool].re = 0.0 - im * H[negate_bool].im;
              H[negate_bool].im = im * br;
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
          y_im = 1.0 / q_0;
          for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
            dcv0[negate_bool].re = 0.0;
            dcv0[negate_bool].im = w[negate_bool] / w_0;
          }

          b_power(dcv0, dcv1);
          for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
            br = 1.0 + dcv1[negate_bool].re;
            bi = y_im * (w[negate_bool] / w_0) + dcv1[negate_bool].im;
            if (bi == 0.0) {
              re = 1.0 / br;
              im = 0.0;
            } else if (br == 0.0) {
              re = 0.0;
              im = -(1.0 / bi);
            } else {
              brm = fabs(br);
              im = fabs(bi);
              if (brm > im) {
                brm = bi / br;
                im = br + brm * bi;
                re = 1.0 / im;
                im = (0.0 - brm) / im;
              } else if (im == brm) {
                if (br > 0.0) {
                  re = 0.5;
                } else {
                  re = -0.5;
                }

                if (bi > 0.0) {
                  im = 0.5;
                } else {
                  im = -0.5;
                }

                re /= brm;
                im = (0.0 - im) / brm;
              } else {
                brm = br / bi;
                im = bi + brm * br;
                re = brm / im;
                im = -1.0 / im;
              }
            }

            br = H[negate_bool].re;
            H[negate_bool].re = H[negate_bool].re * re - H[negate_bool].im * im;
            H[negate_bool].im = br * im + H[negate_bool].im * re;
          }

          switch (filter_T_32) {
           case 1:
            /*  Low-pass filter */
            break;

           case 2:
            /*  High-pass filter */
            for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
              dcv0[negate_bool].re = 0.0;
              dcv0[negate_bool].im = w[negate_bool] / w_0;
            }

            b_power(dcv0, dcv1);
            for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
              br = H[negate_bool].re;
              H[negate_bool].re = dcv1[negate_bool].re * H[negate_bool].re -
                dcv1[negate_bool].im * H[negate_bool].im;
              H[negate_bool].im = dcv1[negate_bool].re * H[negate_bool].im +
                dcv1[negate_bool].im * br;
            }
            break;

           case 3:
            /*  Band-pass filter */
            br = 2.0 * q_0 * w_0;
            y_im = 1.0 / br;
            for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
              im = w[negate_bool] * y_im;
              br = H[negate_bool].re;
              H[negate_bool].re = 0.0 - im * H[negate_bool].im;
              H[negate_bool].im = im * br;
            }
            break;

           case 4:
            /*  Band-stop filter */
            for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
              dcv0[negate_bool].re = 0.0;
              dcv0[negate_bool].im = w[negate_bool] / w_0;
            }

            b_power(dcv0, dcv1);
            for (negate_bool = 0; negate_bool < 100000; negate_bool++) {
              re = 1.0 + dcv1[negate_bool].re;
              im = dcv1[negate_bool].im;
              br = H[negate_bool].re;
              H[negate_bool].re = re * H[negate_bool].re - im * H[negate_bool].
                im;
              H[negate_bool].im = re * H[negate_bool].im + im * br;
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
 * Arguments    : double d1
 *                double d2
 *                double y[100000]
 * Return Type  : void
 */
static void logspace(double d1, double d2, double y[100000])
{
  static double b_y[100000];
  double delta1;
  int k;
  double delta2;
  b_y[99999] = d2;
  b_y[0] = d1;
  if (((d1 < 0.0) != (d2 < 0.0)) && ((fabs(d1) > 8.9884656743115785E+307) ||
       (fabs(d2) > 8.9884656743115785E+307))) {
    delta1 = d1 / 99999.0;
    delta2 = d2 / 99999.0;
    for (k = 0; k < 99998; k++) {
      b_y[k + 1] = (d1 + delta2 * (1.0 + (double)k)) - delta1 * (1.0 + (double)k);
    }
  } else {
    delta1 = (d2 - d1) / 99999.0;
    for (k = 0; k < 99998; k++) {
      b_y[k + 1] = d1 + (1.0 + (double)k) * delta1;
    }
  }

  power(10.0, b_y, y);
}

/*
 * Arguments    : double a
 *                const double b[100000]
 *                double y[100000]
 * Return Type  : void
 */
static void power(double a, const double b[100000], double y[100000])
{
  int k;
  for (k = 0; k < 100000; k++) {
    y[k] = pow(a, b[k]);
  }
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_hypotd(double u0, double u1)
{
  double y;
  double a;
  double b;
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
 *  Copyright 2018 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * Arguments    : void
 * Return Type  : int
 */
int main(void)
{
  int error_flag;
  boolean_T b0;
  boolean_T b1;
  boolean_T b2;
  boolean_T b3;
  boolean_T b4;
  char * INTEGER;
  char * LONG_DOUBLE;
  double f_0;
  double q_0;
  double g;
  int n_f;
  int neg_stop_bool;
  char f_t[5];
  static const char cv1[5] = { '0', '0', '0', '0', '\x00' };

  char keep_bodes[2];
  static const char cv2[2] = { '0', '\x00' };

  static double f[100000];
  char new_bodes[2];
  int exitg1;
  int neg_band_bool;
  char BAND_FILTER[5];
  static const char b_BAND_FILTER[5] = { 'b', 'a', 'n', 'd', '\x00' };

  static const char STOP_FILTER[5] = { 's', 't', 'o', 'p', '\x00' };

  double dv0[2];
  double dv1[2];
  double dv2[2];
  double dv3[2];
  double dv4[2];
  static double H_mod[100000];
  static double H_arg[100000];
  char N_CHAR[2];
  static const char b_N_CHAR[2] = { 'n', '\x00' };

  b0 = false;
  b1 = false;
  b2 = false;
  b3 = false;
  b4 = false;

  /*  Functions that are not translated into C code */
  /*  Constants */
  INTEGER = "%d";
  LONG_DOUBLE = "%lf";

  /*  Initialization */
  f_0 = 0.0;
  q_0 = 0.0;
  g = 1.0;
  n_f = 0;
  for (neg_stop_bool = 0; neg_stop_bool < 5; neg_stop_bool++) {
    f_t[neg_stop_bool] = cv1[neg_stop_bool];
  }

  for (neg_stop_bool = 0; neg_stop_bool < 2; neg_stop_bool++) {
    keep_bodes[neg_stop_bool] = cv2[neg_stop_bool];
    new_bodes[neg_stop_bool] = cv2[neg_stop_bool];
  }

  /*  Definition of the logarithmic frequency range */
  logspace(0.0, 9.0, f);

  /*  Program title */
  printf("%s\n",
         "-------------------------------------------------------------------------------");
  fflush(stdout);
  printf("%s\n",
         "--------------------------- FILTER DESIGN AND VIEWER --------------------------");
  fflush(stdout);
  printf("%s\n",
         "-------------------------------------------------------------------------------");
  fflush(stdout);

  /*  Forever loop */
  do {
    exitg1 = 0;

    /*  Ask for filter's parameters */
    check_str_input(f_t);
    for (neg_stop_bool = 0; neg_stop_bool < 5; neg_stop_bool++) {
      BAND_FILTER[neg_stop_bool] = b_BAND_FILTER[neg_stop_bool];
    }

    neg_band_bool = strcmp(f_t, BAND_FILTER);
    for (neg_stop_bool = 0; neg_stop_bool < 5; neg_stop_bool++) {
      BAND_FILTER[neg_stop_bool] = STOP_FILTER[neg_stop_bool];
    }

    neg_stop_bool = strcmp(f_t, BAND_FILTER);
    if ((neg_band_bool == 0) || (neg_stop_bool == 0)) {
      if (!b0) {
        for (neg_stop_bool = 0; neg_stop_bool < 2; neg_stop_bool++) {
          dv1[neg_stop_bool] = 2.0 + 8.0 * (double)neg_stop_bool;
        }

        b0 = true;
      }

      check_num_input(&n_f, dv1, INTEGER);
    } else {
      if (!b1) {
        for (neg_stop_bool = 0; neg_stop_bool < 2; neg_stop_bool++) {
          dv0[neg_stop_bool] = 1.0 + 9.0 * (double)neg_stop_bool;
        }

        b1 = true;
      }

      check_num_input(&n_f, dv0, INTEGER);
    }

    if (!b2) {
      for (neg_stop_bool = 0; neg_stop_bool < 2; neg_stop_bool++) {
        dv2[neg_stop_bool] = 1.0 + 9.99999999E+8 * (double)neg_stop_bool;
      }

      b2 = true;
    }

    b_check_num_input(&f_0, dv2, LONG_DOUBLE);
    if (n_f > 1) {
      if (!b3) {
        for (neg_stop_bool = 0; neg_stop_bool < 2; neg_stop_bool++) {
          dv3[neg_stop_bool] = 0.1 + 9.9 * (double)neg_stop_bool;
        }

        b3 = true;
      }

      c_check_num_input(&q_0, dv3, LONG_DOUBLE);
    }

    if (!b4) {
      for (neg_stop_bool = 0; neg_stop_bool < 2; neg_stop_bool++) {
        dv4[neg_stop_bool] = 0.001 + 999.999 * (double)neg_stop_bool;
      }

      b4 = true;
    }

    d_check_num_input(&g, dv4, LONG_DOUBLE);

    /*  Bodes calculation */
    filter_bode(f, f_0, q_0, g, f_t, n_f, H_mod, H_arg, &error_flag);

    /*  Display of results (target dependent) */
    /*  Ask the user if he wants to keep the previous graphs */
    check_yes_or_no(keep_bodes);
    for (neg_stop_bool = 0; neg_stop_bool < 2; neg_stop_bool++) {
      N_CHAR[neg_stop_bool] = b_N_CHAR[neg_stop_bool];
    }

    _strcmpi(keep_bodes, N_CHAR);

    /*  Ask the user if he wants to see other filter's Bodes */
    b_check_yes_or_no(new_bodes);
    for (neg_stop_bool = 0; neg_stop_bool < 2; neg_stop_bool++) {
      N_CHAR[neg_stop_bool] = b_N_CHAR[neg_stop_bool];
    }

    neg_stop_bool = _strcmpi(new_bodes, N_CHAR);
    if (neg_stop_bool == 0) {
      exitg1 = 1;
    } else {
      printf("%s\n",
             "-------------------------------------------------------------------------------");
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
 * Arguments    : void
 * Return Type  : void
 */
void main_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
