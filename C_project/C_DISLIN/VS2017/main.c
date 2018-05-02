/*
 * File: main.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 30-Apr-2018 13:53:32
 */

/* Include Files */
#include <float.h>
#include "dislin.h" /* Added of the graphical library */
#include <math.h>
#include <string.h>
#include "main.h"
#include <stdio.h>

/* Variable Definitions */
static const char cv0[20] = { 'l', 'o', 'w', '\x00', '\x00', 'h', 'i', 'g', 'h',
  '\x00', 'b', 'a', 'n', 'd', '\x00', 's', 't', 'o', 'p', '\x00' };

/* Function Declarations */
static void angle_tf(const creal_T x[NB_SAMPLES], double y[NB_SAMPLES]);
static void b_abs(const creal_T x[NB_SAMPLES], double y[NB_SAMPLES]);
static void b_check_num_input(double *param_p, const double limits[2], char
  * c_param);
static void b_check_yes_or_no(char param_p[2]);
static void b_log10(double x[NB_SAMPLES]);
static int b_mod(int x);
static void b_power(const creal_T a[NB_SAMPLES], creal_T y[NB_SAMPLES]);
static void c_check_num_input(double *param_p, const double limits[2], char
  * c_param);
static void check_num_input(int *param_p, const double limits[2], char * c_param);
static void check_str_input(char param_p[5]);
static void check_yes_or_no(char param_p[2]);
static void d_check_num_input(double *param_p, const double limits[2], char
  * c_param);
static void filter_bode(const double f[NB_SAMPLES], double f_0, double q_0, double g,
  const char f_type[5], int f_order, double H_mod[NB_SAMPLES], double H_arg[NB_SAMPLES],
  int *err_f);
static void logspace(double d1, double d2, double y[NB_SAMPLES]);
static void power(double a, const double b[NB_SAMPLES], double y[NB_SAMPLES]);
static double rt_hypotd(double u0, double u1);

/* Function Definitions */

/*
 * Arguments    : const creal_T x[NB_SAMPLES]
 *                double y[NB_SAMPLES]
 * Return Type  : void
 */
static void angle_tf(const creal_T x[NB_SAMPLES], double y[NB_SAMPLES])
{
  static double z1[NB_SAMPLES];
  int k;
  memcpy(&z1[0], &y[0], NB_SAMPLES * sizeof(double));
  for (k = 0; k < NB_SAMPLES; k++) {
    z1[k] = atan2(x[k].im, x[k].re);
  }

  memcpy(&y[0], &z1[0], NB_SAMPLES * sizeof(double));
}

/*
 * Arguments    : const creal_T x[NB_SAMPLES]
 *                double y[NB_SAMPLES]
 * Return Type  : void
 */
static void b_abs(const creal_T x[NB_SAMPLES], double y[NB_SAMPLES])
{
  static double z1[NB_SAMPLES];
  int k;
  memcpy(&z1[0], &y[0], NB_SAMPLES * sizeof(double));
  for (k = 0; k < NB_SAMPLES; k++) {
    z1[k] = rt_hypotd(x[k].re, x[k].im);
  }

  memcpy(&y[0], &z1[0], NB_SAMPLES * sizeof(double));
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
      nb_params = scanf_s(c_param, param_p, 1);

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
  int i31;
  char cv25[2];
  char cv26[2];
  static const char cv27[2] = { '%', 's' };

  int i32;
  int negate_bool_idx_0;
  char cv28[2];
  char cv29[2];
  int i33;
  static const char cv30[2] = { 'n', '\x00' };

  int negate_bool_idx_1;
  char cv31[2];
  char cv32[2];
  static const char cv33[2] = { 'y', '\x00' };

  char * CLEAR_STDIN;

  /*  Constants */
  /*  Initialization */
  /*  sizeof(char) */
  /*  Loop to get and validate user's input */
  do {
    exitg1 = 0;

    /*  Ask the user to enter a selection */
    printf("%s", "Do you want to see Bodes of another filter [y,n]? ");
    fflush(stdout);
    for (i31 = 0; i31 < 2; i31++) {
      cv25[i31] = cv27[i31];
    }

    scanf_s(cv25, cv26, 2);

    /*  Compare the entry to the available types */
    for (i32 = 0; i32 < 2; i32++) {
      param_p[i32] = cv26[i32];
      cv28[i32] = cv26[i32];
      cv29[i32] = cv30[i32];
    }

    negate_bool_idx_0 = _strcmpi(cv28, cv29);
    for (i33 = 0; i33 < 2; i33++) {
      cv31[i33] = cv26[i33];
      cv32[i33] = cv33[i33];
    }

    negate_bool_idx_1 = _strcmpi(cv31, cv32);
    if ((negate_bool_idx_0 == 0) || (negate_bool_idx_1 == 0)) {
      exitg1 = 1;
    } else {
      printf("%s\n", "Please, enter [y,Y] for YES or [n,N] for NO.\n");
      fflush(stdout);

      /*  Force the string regular expression in the generated C code for scanf_s */
      CLEAR_STDIN = "%*[^\n]%*1[\n]";

      /*  Clear the input buffer */
      scanf_s(CLEAR_STDIN);
    }
  } while (exitg1 == 0);

  /*  Handle graphical windows in C */
}

/*
 * Arguments    : double x[NB_SAMPLES]
 * Return Type  : void
 */
static void b_log10(double x[NB_SAMPLES])
{
  int k;
  for (k = 0; k < NB_SAMPLES; k++) {
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
 * Arguments    : const creal_T a[NB_SAMPLES]
 *                creal_T y[NB_SAMPLES]
 * Return Type  : void
 */
static void b_power(const creal_T a[NB_SAMPLES], creal_T y[NB_SAMPLES])
{
  static creal_T z1[NB_SAMPLES];
  int k;
  double y_re;
  double y_im;
  double x_re;
  double x_im;
  double r;
  memcpy(&z1[0], &y[0], NB_SAMPLES * sizeof(creal_T));
  for (k = 0; k < NB_SAMPLES; k++) {
    if ((a[k].im == 0.0) && (a[k].re >= 0.0)) {
      y_re = pow(a[k].re, 2.0);
      y_im = 0.0;
    } else if (a[k].re == 0.0) {
      y_re = -pow(a[k].im, 2.0);
      y_im = 0.0;
    } else {
      if (a[k].im == 0.0) {
        if (a[k].re < 0.0) {
          x_re = log(fabs(a[k].re));
          x_im = 3.1415926535897931;
        } else {
          x_re = log(fabs(a[k].re));
          x_im = 0.0;
        }
      } else if ((fabs(a[k].re) > 8.9884656743115785E+307) || (fabs(a[k].im) >
                  8.9884656743115785E+307)) {
        x_re = log(rt_hypotd(a[k].re / 2.0, a[k].im / 2.0)) +
          0.69314718055994529;
        x_im = atan2(a[k].im, a[k].re);
      } else {
        x_re = log(rt_hypotd(a[k].re, a[k].im));
        x_im = atan2(a[k].im, a[k].re);
      }

      y_re = 2.0 * x_re;
      y_im = 2.0 * x_im;
      if (y_im == 0.0) {
        y_re = exp(y_re);
        y_im = 0.0;
      } else {
        r = exp(y_re / 2.0);
        y_re = r * (r * cos(y_im));
        y_im = r * (r * sin(y_im));
      }
    }

    z1[k].re = y_re;
    z1[k].im = y_im;
  }

  memcpy(&y[0], &z1[0], NB_SAMPLES * sizeof(creal_T));
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
      nb_params = scanf_s(c_param, param_p, 1);

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
      printf("%s", "Order of the filter: ");
      fflush(stdout);
      nb_params = scanf_s(c_param, param_p, 1);

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
  int i25;
  char cv12[3];
  char cv13[5];
  static const char cv14[3] = { '%', '4', 's' };

  int i26;
  int i;
  boolean_T exitg2;
  int i27;
  char cv15[5];
  char FILTER[5];
  char * CLEAR_STDIN;

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
    for (i25 = 0; i25 < 3; i25++) {
      cv12[i25] = cv14[i25];
    }

    scanf_s(cv12, cv13, 8);
    for (i26 = 0; i26 < 5; i26++) {
      param_p[i26] = cv13[i26];
    }

    /*  Compare the entry to the available types */
    i = 1;
    exitg2 = false;
    while ((!exitg2) && (i < 5)) {
      for (i27 = 0; i27 < 5; i27++) {
        cv15[i27] = cv13[i27];
        FILTER[i27] = cv0[i27 + 5 * (i - 1)];
      }

      negate_bool = strcmp(cv15, FILTER);
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
      CLEAR_STDIN = "%*[^\n]%*1[\n]";

      /*  Clear the input buffer */
      scanf_s(CLEAR_STDIN);
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
  int i28;
  char cv16[2];
  char cv17[2];
  static const char cv18[2] = { '%', 's' };

  int i29;
  int negate_bool_idx_0;
  char cv19[2];
  char cv20[2];
  int i30;
  static const char cv21[2] = { 'n', '\x00' };

  int negate_bool_idx_1;
  char cv22[2];
  char cv23[2];
  static const char cv24[2] = { 'y', '\x00' };

  char * CLEAR_STDIN;

  /*  Constants */
  /*  Initialization */
  /*  sizeof(char) */
  /*  Loop to get and validate user's input */
  do {
    exitg1 = 0;

    /*  Ask the user to enter a selection */
    printf("%s", "Do you want to keep the previous Bodes [y,n]? ");
    fflush(stdout);
    for (i28 = 0; i28 < 2; i28++) {
      cv16[i28] = cv18[i28];
    }

    scanf_s(cv16, cv17, 2);

    /*  Compare the entry to the available types */
    for (i29 = 0; i29 < 2; i29++) {
      param_p[i29] = cv17[i29];
      cv19[i29] = cv17[i29];
      cv20[i29] = cv21[i29];
    }

    negate_bool_idx_0 = _strcmpi(cv19, cv20);
    for (i30 = 0; i30 < 2; i30++) {
      cv22[i30] = cv17[i30];
      cv23[i30] = cv24[i30];
    }

    negate_bool_idx_1 = _strcmpi(cv22, cv23);
    if ((negate_bool_idx_0 == 0) || (negate_bool_idx_1 == 0)) {
      exitg1 = 1;
    } else {
      printf("%s\n", "Please, enter [y,Y] for YES or [n,N] for NO.\n");
      fflush(stdout);

      /*  Force the string regular expression in the generated C code for scanf_s */
      CLEAR_STDIN = "%*[^\n]%*1[\n]";

      /*  Clear the input buffer */
      scanf_s(CLEAR_STDIN);
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
      nb_params = scanf_s(c_param, param_p, 1);

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
 * Arguments    : const double f[NB_SAMPLES]
 *                double f_0
 *                double q_0
 *                double g
 *                const char f_type[5]
 *                int f_order
 *                double H_mod[NB_SAMPLES]
 *                double H_arg[NB_SAMPLES]
 *                int *err_f
 * Return Type  : void
 */
static void filter_bode(const double f[NB_SAMPLES], double f_0, double q_0, double g,
  const char f_type[5], int f_order, double H_mod[NB_SAMPLES], double H_arg[NB_SAMPLES],
  int *err_f)
{
  int filter_T_32;
  int i11;
  double w_0;
  static creal_T H[NB_SAMPLES];
  int i;
  int i12;
  static double w[NB_SAMPLES];
  int negate_bool;
  char b_f_type[5];
  char TYPE[5];
  int exitg1;
  boolean_T guard1 = false;
  int n_cell_order;
  int i13;
  static double dv5[NB_SAMPLES];
  int i14;
  double y_im;
  int i15;
  int i16;
  double bi;
  int i17;
  static creal_T dcv0[NB_SAMPLES];
  static creal_T dcv1[NB_SAMPLES];
  int i18;
  int i19;
  double bim;
  double re;
  double im;
  double br;
  double b_im;
  double d;
  double b_bi;
  double H_re;
  double s;
  double b_H_re;
  int i20;
  double b_br;
  int i21;
  double sgnbi;
  double b_re;
  static creal_T dcv2[NB_SAMPLES];
  int i22;
  static creal_T dcv3[NB_SAMPLES];
  double brm;
  double c_im;
  int i23;
  int i24;
  double b_bim;
  double b_y_im;
  double c_H_re;
  double d_H_re;
  double e_H_re;
  double c_re;
  double b_s;
  double d_im;
  double b_d;
  double f_H_re;
  double sgnbr;
  double b_sgnbi;

  /*  Constants */
  /*  Integer representation of filter's type */
  /*  Initializations */
  *err_f = 0;
  filter_T_32 = 0;

  /*  Pulsation's vectors */
  for (i11 = 0; i11 < NB_SAMPLES; i11++) {
    H[i11].re = 1.0;
    H[i11].im = 0.0;
    H_mod[i11] = 0.0;
    H_arg[i11] = 0.0;
    w[i11] = 6.2831853071795862 * f[i11];
  }

  w_0 = 6.2831853071795862 * f_0;

  /*  Set switches to work with integer */
  for (i = 0; i < 4; i++) {
    for (i12 = 0; i12 < 5; i12++) {
      b_f_type[i12] = f_type[i12];
      TYPE[i12] = cv0[i12 + 5 * i];
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
        n_cell_order = 2;
        guard1 = true;
      } else if (f_order == 1) {
        n_cell_order = 1;
        guard1 = true;
      } else {
        /*  All filter's cells have been calculated */
        for (i13 = 0; i13 < NB_SAMPLES; i13++) {
          H[i13].re *= g;
          H[i13].im *= g;
        }

        /*  Apply the filter gain only once */
        /*  Retrieves module and argument of the transfer function H */
        b_abs(H, dv5);
        b_log10(dv5);
        for (i14 = 0; i14 < NB_SAMPLES; i14++) {
          H_mod[i14] = 20.0 * dv5[i14];
        }

        /*  [dB] */
        angle_tf(H, dv5);
        for (i17 = 0; i17 < NB_SAMPLES; i17++) {
          H_arg[i17] = dv5[i17] * 180.0 / 3.1415926535897931;
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
          for (i15 = 0; i15 < NB_SAMPLES; i15++) {
            bi = w[i15] / w_0;
            if (bi == 0.0) {
              re = 1.0;
              im = 0.0;
            } else {
              bim = fabs(bi);
              if (1.0 > bim) {
                d = 1.0 + bi * bi;
                re = 1.0 / d;
                im = (0.0 - bi) / d;
              } else if (bim == 1.0) {
                if (bi > 0.0) {
                  sgnbi = 0.5;
                } else {
                  sgnbi = -0.5;
                }

                re = 0.5;
                im = 0.0 - sgnbi;
              } else {
                s = 1.0 / bi;
                d = bi + s;
                re = s / d;
                im = -1.0 / d;
              }
            }

            b_H_re = H[i15].re;
            H[i15].re = H[i15].re * re - H[i15].im * im;
            H[i15].im = b_H_re * im + H[i15].im * re;
          }

          switch (filter_T_32) {
           case 1:
            /*  Low-pass filter */
            break;

           case 2:
            /*  High-pass filter */
            for (i19 = 0; i19 < NB_SAMPLES; i19++) {
              b_im = w[i19] / w_0;
              H_re = H[i19].re;
              H[i19].re = 0.0 - b_im * H[i19].im;
              H[i19].im = b_im * H_re;
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
          for (i16 = 0; i16 < NB_SAMPLES; i16++) {
            dcv0[i16].re = 0.0;
            dcv0[i16].im = w[i16] / w_0;
          }

          b_power(dcv0, dcv1);
          for (i18 = 0; i18 < NB_SAMPLES; i18++) {
            br = 1.0 + dcv1[i18].re;
            b_bi = y_im * (w[i18] / w_0) + dcv1[i18].im;
            if (b_bi == 0.0) {
              b_re = 1.0 / br;
              c_im = 0.0;
            } else if (br == 0.0) {
              b_re = 0.0;
              c_im = -(1.0 / b_bi);
            } else {
              brm = fabs(br);
              b_bim = fabs(b_bi);
              if (brm > b_bim) {
                b_s = b_bi / br;
                b_d = br + b_s * b_bi;
                b_re = 1.0 / b_d;
                c_im = (0.0 - b_s) / b_d;
              } else if (b_bim == brm) {
                if (br > 0.0) {
                  sgnbr = 0.5;
                } else {
                  sgnbr = -0.5;
                }

                if (b_bi > 0.0) {
                  b_sgnbi = 0.5;
                } else {
                  b_sgnbi = -0.5;
                }

                b_re = sgnbr / brm;
                c_im = (0.0 - b_sgnbi) / brm;
              } else {
                b_s = br / b_bi;
                b_d = b_bi + b_s * br;
                b_re = b_s / b_d;
                c_im = -1.0 / b_d;
              }
            }

            c_H_re = H[i18].re;
            H[i18].re = H[i18].re * b_re - H[i18].im * c_im;
            H[i18].im = c_H_re * c_im + H[i18].im * b_re;
          }

          switch (filter_T_32) {
           case 1:
            /*  Low-pass filter */
            break;

           case 2:
            /*  High-pass filter */
            for (i20 = 0; i20 < NB_SAMPLES; i20++) {
              dcv2[i20].re = 0.0;
              dcv2[i20].im = w[i20] / w_0;
            }

            b_power(dcv2, dcv1);
            for (i23 = 0; i23 < NB_SAMPLES; i23++) {
              d_H_re = H[i23].re;
              H[i23].re = dcv1[i23].re * H[i23].re - dcv1[i23].im * H[i23].im;
              H[i23].im = dcv1[i23].re * H[i23].im + dcv1[i23].im * d_H_re;
            }
            break;

           case 3:
            /*  Band-pass filter */
            b_br = 2.0 * q_0 * w_0;
            y_im = 1.0 / b_br;
            for (i22 = 0; i22 < NB_SAMPLES; i22++) {
              b_y_im = w[i22] * y_im;
              e_H_re = H[i22].re;
              H[i22].re = 0.0 - b_y_im * H[i22].im;
              H[i22].im = b_y_im * e_H_re;
            }
            break;

           case 4:
            /*  Band-stop filter */
            for (i21 = 0; i21 < NB_SAMPLES; i21++) {
              dcv3[i21].re = 0.0;
              dcv3[i21].im = w[i21] / w_0;
            }

            b_power(dcv3, dcv1);
            for (i24 = 0; i24 < NB_SAMPLES; i24++) {
              c_re = 1.0 + dcv1[i24].re;
              d_im = dcv1[i24].im;
              f_H_re = H[i24].re;
              H[i24].re = c_re * H[i24].re - d_im * H[i24].im;
              H[i24].im = c_re * H[i24].im + d_im * f_H_re;
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
 *                double y[NB_SAMPLES]
 * Return Type  : void
 */
static void logspace(double d1, double d2, double y[NB_SAMPLES])
{
  static double b_y[NB_SAMPLES];
  double delta1;
  int k;
  double delta2;
  int b_k;
  b_y[NB_SAMPLES-1] = d2;
  b_y[0] = d1;
  if (((d1 < 0.0) != (d2 < 0.0)) && ((fabs(d1) > 8.9884656743115785E+307) ||
       (fabs(d2) > 8.9884656743115785E+307))) {
    delta1 = d1 / (NB_SAMPLES-1.0);
    delta2 = d2 / (NB_SAMPLES-1.0);
    for (b_k = 0; b_k < NB_SAMPLES-2; b_k++) {
      b_y[b_k + 1] = (d1 + delta2 * (1.0 + (double)b_k)) - delta1 * (1.0 +
        (double)b_k);
    }
  } else {
    delta1 = (d2 - d1) / (NB_SAMPLES-1.0);
    for (k = 0; k < NB_SAMPLES-2; k++) {
      b_y[k + 1] = d1 + (1.0 + (double)k) * delta1;
    }
  }

  power(10.0, b_y, y);
}

/*
 * Arguments    : double a
 *                const double b[NB_SAMPLES]
 *                double y[NB_SAMPLES]
 * Return Type  : void
 */
static void power(double a, const double b[NB_SAMPLES], double y[NB_SAMPLES])
{
  static double z1[NB_SAMPLES];
  int k;
  memcpy(&z1[0], &y[0], NB_SAMPLES * sizeof(double));
  for (k = 0; k < NB_SAMPLES; k++) {
    z1[k] = pow(a, b[k]);
  }

  memcpy(&y[0], &z1[0], NB_SAMPLES * sizeof(double));
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
 *  Function: min_and_max()
 *  Goal    : Set the min and max values of axes for the graphical display
 *
 *  IN      : - data[NB_SAMPLES]: data to display
 *            - min_val  : minimal possible value
 *            - max_val  : maximal possible value
 *  IN/OUT  : - *data_min: min value to display
 *            - *data_max: max value to display
 *  OUT     : -
 *
 *  Copyright 2018 The MathWorks, Inc.
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 */
static void min_and_max(double *data_min, double *data_max,
                        double min_val, double max_val, double data[NB_SAMPLES])
{
  double temp_min, temp_max;
  int  i, min_idx, max_idx;
  
  /* Looking for the boundaries */
  for (i = 0; i < NB_SAMPLES-1; i++) {
    temp_min = min_data(data[i],data[i+1]);
    temp_max = max_data(data[i],data[i+1]);
    if (temp_min < *data_min) {
      *data_min = temp_min;
      min_idx = i;
    }
    if (temp_max > *data_max) {
      *data_max = temp_max;
      max_idx = i;
    }
  }
  
  /* Round up of the boundaries */
  *data_min = ceil(*data_min-1);
  *data_max = ceil(*data_max+1);
  if (fmod(*data_min,10) != 0){
    /* Set the min boundary to have no division remainder for a divider of 10 */
    *data_min = *data_min - Y_AXS_STEP+1;
  }
  
  /* Check infinite values and set min/max limits if needed */
  if (*data_min < -DBL_MAX) {
    *data_min = min_val;
    data[min_idx+1] = min_val; /* Saturate to avoid plotting out of scope */
  }
  if (*data_max > DBL_MAX) {
    *data_max = max_val;
    data[max_idx+1] = max_val; /* Saturate to avoid plotting out of scope */
  }
  /* For debug purposes only */
  //printf("min = %lf, max = %lf\n", *data_min,*data_max);
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
  /* Graphs parameters for dislin */
  const int X_ORIG_W =  100;
  const int Y_ORIG_W =  100;
  const int X_SIZE_W = 1600;
  const int Y_SIZE_W = 1000;
  const int X_AXIS_L = 1400;
  const int Y_AXIS_L = 1400;
  const int X_AXIS_P =  600;
  const int Y_AXIS_P = 2200;

  /* Constants declaration */

  static const char BAND_FILTER[5] = { 'b', 'a', 'n', 'd', '\x00' };
  static const char STOP_FILTER[5] = { 's', 't', 'o', 'p', '\x00' };
  static const char N_CHAR[2]      = { 'n', '\x00' };

  const double ORDER_LIMS_1[2] = {1,10};
  const double ORDER_LIMS_2[2] = {2,10};
  const double QUAL_LIMS[2]    = {0.1,10};
  const double GAIN_LIMS[2]    = {0.001,1000};
  
  /* Vectors definition */
  static double f[NB_SAMPLES];
  static double H_arg[NB_SAMPLES];
  static double H_mod[NB_SAMPLES];
  
  /* Variables declaration */
  char f_t[5]        = { '0', '0', '0', '0', '\x00' };
  char t_word[5]     = { '0', '0', '0', '0', '\x00' };
  char keep_bodes[2] = { '0', '\x00' };
  char new_bodes[2]  = { '0', '\x00' };
  char amplitude_title[50] = "";
  char phase_title[50]     = "";
  size_t size_title = 0;
  int    n_f;
  double f_0, q_0, g;
  double mod_min, mod_max, arg_min, arg_max;
  double frequency_range[2];
  int error_flag, fig_id, i0;
  int negate_bool, neg_band_bool, neg_stop_bool;
  int mod_y_axs_step, arg_y_axs_step;
  int32_T exitg1;
  /*  scanf_s input format */
  char * INTEGER;
  char * LONG_DOUBLE;
  INTEGER = "%d";
  LONG_DOUBLE = "%lf";

  /*  Initialization */
  error_flag = 0;
  n_f = 0;
  f_0 = 0.0;
  q_0 = 0.0;
  g   = 1.0;

  /*  Definition of the logarithmic frequency range till 1 Tera Hertz */
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
  fig_id = 0;
  do {
    exitg1 = 0;

    /*  Ask for filter's parameters */
    check_str_input(f_t);
    neg_band_bool = strcmp(f_t, BAND_FILTER);
    neg_stop_bool = strcmp(f_t, BAND_FILTER);	
    if ((neg_band_bool == 0) || (neg_stop_bool == 0)) {
      check_num_input(&n_f, ORDER_LIMS_2, INTEGER);
    } else {
      check_num_input(&n_f, ORDER_LIMS_1, INTEGER);
        }
    for (i0 = 0; i0 < 2; i0++) {
      frequency_range[i0] = 1.0 + 9.99999999E+8 * (double)i0;
    }
    b_check_num_input(&f_0, frequency_range, LONG_DOUBLE);
    if (n_f > 1) {
      c_check_num_input(&q_0, QUAL_LIMS, LONG_DOUBLE);
    }
    d_check_num_input(&g, GAIN_LIMS, LONG_DOUBLE);

    /*  Bodes calculation */
    filter_bode(f, f_0, q_0, g, f_t, n_f, H_mod, H_arg, &error_flag);

    /*  Display of results (target dependent) */
    if (error_flag == 0) {
      /* Search of the min and max values in order to set a correct scale on axes */
      mod_min = 0; mod_max = 0;
      arg_min = 0; arg_max = 0;
      min_and_max(&mod_min, &mod_max, -200, 200, H_mod);
      min_and_max(&arg_min, &arg_max, -181, 181, H_arg);

      if (fig_id == 0) {
        /* Initialization of dislin */
        metafl("XWIN");    /* Defines the META file format        */
        setpag("DA3L");    /* Sets the size of the graphical area */
        scrmod("REVERSE"); /* Sets the background color to white  */
        units ("CM");      /* Sets the plot's units (100[pts/cm]) */
        disini();          /* Launches the first dislin window    */
        noclip();
        fig_id = fig_id+1;
      }
      else if (fig_id > 0) {
        /* Creation of a new graphical windows */
        fig_id = fig_id+1;
        opnwin(fig_id);
      }
      /* Selects the current window */ 
      selwin(fig_id);
      /* Sets the window's sizes and position */
      window(X_ORIG_W,Y_ORIG_W,X_SIZE_W,Y_SIZE_W);

      if (!strncmp(f_t,"stop",4)) {
        strncpy_s(t_word,sizeof(t_word),"band",4);
      }
      else {
        strncpy_s(t_word,sizeof(t_word),"pass",4);
      }

      /* Set the space between Y-axis labels for the module */
      switch (n_f) {
        case 1:
          mod_y_axs_step = 10;
          arg_y_axs_step = 5;
          break;
        case 2:
          mod_y_axs_step = 10;
          arg_y_axs_step = 10;
          break;
        case 3:
        case 4:
          mod_y_axs_step = 20;
          arg_y_axs_step = 20;
          break;
        case 5:
        case 6:
        case 7:
          mod_y_axs_step = 40;
          arg_y_axs_step = 20;
          break;
        default:
          mod_y_axs_step = 50;
          arg_y_axs_step = 20;
          break;
      }
      
      /* Creation of the title of the amplitude's bode */
      size_title = sizeof(amplitude_title);
      _snprintf_s(amplitude_title,size_title,size_title,"%s %s%s%s %s %d",
                  "Module of the",f_t,"-",t_word,"filter of order",n_f);
      titlin(amplitude_title,1);
      /* Settings of the amplitude's bode */
      name  ("Frequency [Hz]","X");
      name  ("|H| [dB]","Y");
      axsscl("LOG","X");
      labels("LOG","XY");
      axslen(X_AXIS_L,Y_AXIS_L);
      axspos(X_AXIS_P,Y_AXIS_P);
      graf  (0,9,0,1, mod_min,mod_max,mod_min,mod_y_axs_step);
      title ();
      /* Drawing of the amplitude's bode */
      thkcrv(10);
      color ("red");
      curve (f,H_mod,NB_SAMPLES);
      color ("fore");
      grid  (1,1);
      endgrf();

      /* Creation of the title of the phase's bode */
      size_title = sizeof(phase_title);
      _snprintf_s(phase_title,size_title,size_title,"%s %s%s%s %s %d",
                  "Phase of the",f_t,"-",t_word,"filter of order",n_f);
      titlin(phase_title,1);
      /* Settings of the phase's bode */
      name  ("Frequency [Hz]","X");
      name  ("arg(H) [degree]","Y"); // °symbol in unicode:"\u00B0"
      axsscl("LOG","X");
      labels("LOG","XY");
      axslen(X_AXIS_L,Y_AXIS_L);
      axspos(2*X_AXIS_P+X_AXIS_L,Y_AXIS_P);
      graf  (0,9,0,1, arg_min,arg_max,arg_min,arg_y_axs_step);
      title ();
      /* Drawing of the phase's bode */
      thkcrv(10);
      color ("red");
      curve (f,H_arg,NB_SAMPLES);
      color ("fore");
      grid  (1,1);
      endgrf();
      }
    else {
      printf("Plots cannot be maid due to a misconfiguration of parameters.\n");
      switch (error_flag) {
        case ERROR_TYPE:
          printf("This type of filter is not supported.\n");
          break;
        case ERROR_ORDER:
          printf("This order value is not supported for such filters. It must be an even value.\n");
          break;
        default:
          printf("Unknown error. Please re-submit filter's parameters.\n");
          break;
      }
    }

    /*  Ask the user if he wants to keep the previous graphs */
    check_yes_or_no(keep_bodes);

    negate_bool = _strcmpi(keep_bodes, N_CHAR);
    if (negate_bool == 0)
    {
      if (fig_id > 1)
      {
        /* Close other windows */
        clswin(fig_id);
        fig_id = fig_id-1;
      }
      else {
        /* Termination of dislin */
        printf("Close the window to terminate the application...");
        disfin();
      }
    }
    /* Ask the user if he wants to see other filter's Bodes */
    b_check_yes_or_no(new_bodes);

    negate_bool = _strcmpi(new_bodes, N_CHAR);
    if (negate_bool == 0)
    {
      /* Close all windows */
      for (fig_id; fig_id>0; fig_id--) {
        clswin(fig_id);
      }
      /* Termination of dislin */
      printf("Close the window to terminate the application...");
      disfin();
    }
    else {
      printf("%s\n",
             "-------------------------------------------------------------------------------");
      fflush(stdout);
    }
  } while (negate_bool != 0);

  return error_flag;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
