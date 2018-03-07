/*
 * File: main.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 08-Feb-2018 11:07:30
 */

/* Include Files */
#include <float.h>
#include "dislin.h" /* Added of the graphical library */
#include "main.h"
#include "stdio.h"

/* Variable Definitions */
static const char cv0[20] = { 'l', 'h', 'b', 's', 'o', 'i', 'a', 't', 'w', 'g',
  'n', 'o', '\x00', 'h', 'd', 'p', '\x00', '\x00', '\x00', '\x00' };

static const char cv1[55] = { 'I', 'n', 'p', 'u', 't', ' ', 'n', 'o', 't', ' ',
  'r', 'e', 'c', 'o', 'g', 'n', 'i', 's', 'e', 'd', ' ', 'a', 's', ' ', 'a', 'n',
  ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ',', ' ', 'p', 'l', 'e', 'a', 's', 'e',
  ' ', 't', 'r', 'y', ' ', 'a', 'g', 'a', 'i', 'n', '.', '\x0a', '\x00' };

static const char cv2[96] = { 'F', 'o', 'r', ' ', 't', 'h', 'i', 's', ' ', 'f',
  'i', 'l', 't', 'e', 'r', ',', ' ', 't', 'h', 'e', ' ', 'p', 'a', 'r', 'a', 'm',
  'e', 't', 'e', 'r', ' ', 's', 'h', 'o', 'u', 'l', 'd', ' ', 'b', 'e', ' ', 'b',
  'e', 't', 'w', 'e', 'e', 'n', ' ', '%', '.', '3', 'f', ' ', 'a', 'n', 'd', ' ',
  '%', '.', '3', 'f', '.', '\x0a', 'P', 'l', 'e', 'a', 's', 'e', ',', ' ', 'e',
  'n', 't', 'e', 'r', ' ', 'a', ' ', 'c', 'o', 'r', 'r', 'e', 'c', 't', ' ', 'v',
  'a', 'l', 'u', 'e', '.', '\x0a', '\x00' };

static const char cv3[46] = { 'P', 'l', 'e', 'a', 's', 'e', ',', ' ', 'e', 'n',
  't', 'e', 'r', ' ', '[', 'y', ',', 'Y', ']', ' ', 'f', 'o', 'r', ' ', 'Y', 'E',
  'S', ' ', 'o', 'r', ' ', '[', 'n', ',', 'N', ']', ' ', 'f', 'o', 'r', ' ', 'N',
  'O', '.', '\x0a', '\x00' };

/* Function Declarations */
static void angle_tf(const creal_T x[NB_SAMPLES], double y[NB_SAMPLES]);
static void b_abs(const creal_T x[NB_SAMPLES], double y[NB_SAMPLES]);
static void b_check_num_input(double *param_p, const double limits[2]);
static void b_check_yes_or_no(char param_p[2]);
static void b_log10(double x[NB_SAMPLES]);
static int b_mod(int x);
static void b_power(const creal_T a[NB_SAMPLES], creal_T y[NB_SAMPLES]);
static void c_check_num_input(double *param_p, const double limits[2]);
static void check_num_input(int *param_p, const double limits[2]);
static void check_str_input(char param_p[5]);
static void check_yes_or_no(char param_p[2]);
static void d_check_num_input(double *param_p, const double limits[2]);
static void filter_bode(const double f[NB_SAMPLES], double f_0, double q_0, double g,
  const char f_type[5], int f_order, double H_mod[NB_SAMPLES], double H_arg[NB_SAMPLES],
  int *error_flag);
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
  int k;
  for (k = 0; k < NB_SAMPLES; k++) {
    y[k] = atan2(x[k].im, x[k].re);
  }
}

/*
 * Arguments    : const creal_T x[NB_SAMPLES]
 *                double y[NB_SAMPLES]
 * Return Type  : void
 */
static void b_abs(const creal_T x[NB_SAMPLES], double y[NB_SAMPLES])
{
  int k;
  for (k = 0; k < NB_SAMPLES; k++) {
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
 * Return Type  : void
 */
static void b_check_num_input(double *param_p, const double limits[2])
{
  
  int exitg1;
  int exitg2;
  static const char text_id[19] = { 'C', 'u', 't', 'o', 'f', 'f', ' ', 'f', 'r',
    'e', 'q', 'u', 'e', 'n', 'c', 'y', ':', ' ', '\x00' };

  int nb_params;
  static const char c_param[3] = { '%', 'l', 'f' };

  char WRONG_TYPE_IN[55];
  char ERROR_MESSAGE[96];

  /*  Constants */
  /*  String not supported for codegen: to replace with "%*[^\n]%*1[\n]"; */
  char CLEAR_STDIN[14] = "%*[^\n]%*1[\n]";

  /*  Initialization */
  /*  Check user's input */
  do {
    exitg1 = 0;
    do {
      exitg2 = 0;

      /*  Ask the user to enter a number  */
      printf(text_id);
      nb_params = scanf(c_param, param_p);

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
        for (nb_params = 0; nb_params < 55; nb_params++) {
          WRONG_TYPE_IN[nb_params] = cv1[nb_params];
        }

        printf(WRONG_TYPE_IN);
        scanf(CLEAR_STDIN);

        /*  Clear of stdin buffer */
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    /*  Compare the entry to the possible data range */
    if ((*param_p >= limits[0]) && (*param_p <= limits[1])) {
      exitg1 = 1;
    } else {
      memcpy(&ERROR_MESSAGE[0], &cv2[0], 96U * sizeof(char));
      printf(ERROR_MESSAGE, limits[0], limits[1]);
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
  static const char text_id[51] = { 'D', 'o', ' ', 'y', 'o', 'u', ' ', 'w', 'a',
    'n', 't', ' ', 't', 'o', ' ', 's', 'e', 'e', ' ', 'B', 'o', 'd', 'e', 's',
    ' ', 'o', 'f', ' ', 'a', 'n', 'o', 't', 'h', 'e', 'r', ' ', 'f', 'i', 'l',
    't', 'e', 'r', ' ', '[', 'y', ',', 'n', ']', '?', ' ', '\x00' };

  int negate_bool_idx_1;
  char N_CHAR[2];
  static const char cv9[2] = { '%', 's' };

  int negate_bool_idx_0;
  char b_param_p[2];
  static const char b_N_CHAR[2] = { 'n', '\x00' };

  static const char Y_CHAR[2] = { 'y', '\x00' };

  char ERROR_MESSAGE[46];

  /*  Constants */
  /*  Initialization */
  /*  Loop to get and validate user's input */
  do {
    exitg1 = 0;

    /*  Ask the user to enter a selection */
    printf(text_id);
    for (negate_bool_idx_1 = 0; negate_bool_idx_1 < 2; negate_bool_idx_1++) {
      N_CHAR[negate_bool_idx_1] = cv9[negate_bool_idx_1];
    }

    scanf(N_CHAR, param_p);

    /*  Compare the entry to the available types */
    for (negate_bool_idx_1 = 0; negate_bool_idx_1 < 2; negate_bool_idx_1++) {
      b_param_p[negate_bool_idx_1] = param_p[negate_bool_idx_1];
      N_CHAR[negate_bool_idx_1] = b_N_CHAR[negate_bool_idx_1];
    }

    negate_bool_idx_0 = strcmpi(b_param_p, N_CHAR);
    for (negate_bool_idx_1 = 0; negate_bool_idx_1 < 2; negate_bool_idx_1++) {
      b_param_p[negate_bool_idx_1] = param_p[negate_bool_idx_1];
      N_CHAR[negate_bool_idx_1] = Y_CHAR[negate_bool_idx_1];
    }

    negate_bool_idx_1 = strcmpi(b_param_p, N_CHAR);
    if ((negate_bool_idx_0 == 0) || (negate_bool_idx_1 == 0)) {
      exitg1 = 1;
    } else {
      for (negate_bool_idx_1 = 0; negate_bool_idx_1 < 46; negate_bool_idx_1++) {
        ERROR_MESSAGE[negate_bool_idx_1] = cv3[negate_bool_idx_1];
      }

      printf(ERROR_MESSAGE);
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
  int k;
  for (k = 0; k < NB_SAMPLES; k++) {
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
 * Return Type  : void
 */
static void c_check_num_input(double *param_p, const double limits[2])
{
  
  int exitg1;
  int exitg2;
  static const char text_id[17] = { 'Q', 'u', 'a', 'l', 'i', 't', 'y', ' ', 'f',
    'a', 'c', 't', 'o', 'r', ':', ' ', '\x00' };

  int nb_params;
  static const char c_param[3] = { '%', 'l', 'f' };

  char WRONG_TYPE_IN[55];
  char ERROR_MESSAGE[96];

  /*  Constants */
  /*  String not supported for codegen: to replace with "%*[^\n]%*1[\n]"; */
  char CLEAR_STDIN[14] = "%*[^\n]%*1[\n]";

  /*  Initialization */
  /*  Check user's input */
  do {
    exitg1 = 0;
    do {
      exitg2 = 0;

      /*  Ask the user to enter a number  */
      printf(text_id);
      nb_params = scanf(c_param, param_p);

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
        for (nb_params = 0; nb_params < 55; nb_params++) {
          WRONG_TYPE_IN[nb_params] = cv1[nb_params];
        }

        printf(WRONG_TYPE_IN);
        scanf(CLEAR_STDIN);

        /*  Clear of stdin buffer */
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    /*  Compare the entry to the possible data range */
    if ((*param_p >= limits[0]) && (*param_p <= limits[1])) {
      exitg1 = 1;
    } else {
      memcpy(&ERROR_MESSAGE[0], &cv2[0], 96U * sizeof(char));
      printf(ERROR_MESSAGE, limits[0], limits[1]);
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
 * Return Type  : void
 */
static void check_num_input(int *param_p, const double limits[2])
{
  
  int exitg1;
  int exitg2;
  static const char text_id[22] = { 'O', 'r', 'd', 'e', 'r', ' ', 'o', 'f', ' ',
    't', 'h', 'e', ' ', 'f', 'i', 'l', 't', 'e', 'r', ':', ' ', '\x00' };

  int nb_params;
  static const char c_param[2] = { '%', 'd' };

  char WRONG_TYPE_IN[55];
  char ERROR_MESSAGE[96];

  /*  Constants */
  /*  String not supported for codegen: to replace with "%*[^\n]%*1[\n]"; */
  char CLEAR_STDIN[14] = "%*[^\n]%*1[\n]";

  /*  Initialization */
  /*  Check user's input */
  do {
    exitg1 = 0;
    do {
      exitg2 = 0;

      /*  Ask the user to enter a number  */
      printf(text_id);
      nb_params = scanf(c_param, param_p);

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
        for (nb_params = 0; nb_params < 55; nb_params++) {
          WRONG_TYPE_IN[nb_params] = cv1[nb_params];
        }

        printf(WRONG_TYPE_IN);
        scanf(CLEAR_STDIN);

        /*  Clear of stdin buffer */
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    /*  Compare the entry to the possible data range */
    if ((*param_p >= limits[0]) && (*param_p <= limits[1])) {
      exitg1 = 1;
    } else {
      memcpy(&ERROR_MESSAGE[0], &cv2[0], 96U * sizeof(char));
      printf(ERROR_MESSAGE, limits[0], limits[1]);
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
  static const char text_id[41] = { 'T', 'y', 'p', 'e', ' ', 'o', 'f', ' ', 'f',
    'i', 'l', 't', 'e', 'r', ' ', '[', 'l', 'o', 'w', ']', '[', 'h', 'i', 'g',
    'h', ']', '[', 'b', 'a', 'n', 'd', ']', '[', 's', 't', 'o', 'p', ']', ':',
    ' ', '\x00' };

  int i0;
  char cv6[2];
  static const char cv7[2] = { '%', 's' };

  int i;
  boolean_T exitg2;
  char b_param_p[5];
  char FILTER[5];
  char ERROR_MESSAGE[51];
  static const char b_ERROR_MESSAGE[51] = { 'U', 'n', 'k', 'n', 'o', 'w', 'n',
    ' ', 'f', 'i', 'l', 't', 'e', 'r', ' ', 't', 'y', 'p', 'e', '.', ' ', 'P',
    'l', 'e', 'a', 's', 'e', ',', ' ', 'e', 'n', 't', 'e', 'r', ' ', 'a', ' ',
    'c', 'o', 'r', 'r', 'e', 'c', 't', ' ', 'o', 'n', 'e', '.', '\x0a', '\x00' };

  /*  Constants */
  /*  Initialization */
  negate_bool = 1;

  /*  Loop to get and validate user's input */
  do {
    exitg1 = 0;

    /*  Ask the user to enter a filter type */
    printf(text_id);
    for (i0 = 0; i0 < 2; i0++) {
      cv6[i0] = cv7[i0];
    }

    scanf(cv6, param_p);

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
      for (i0 = 0; i0 < 51; i0++) {
        ERROR_MESSAGE[i0] = b_ERROR_MESSAGE[i0];
      }

      printf(ERROR_MESSAGE);
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
  static const char text_id[47] = { 'D', 'o', ' ', 'y', 'o', 'u', ' ', 'w', 'a',
    'n', 't', ' ', 't', 'o', ' ', 'k', 'e', 'e', 'p', ' ', 't', 'h', 'e', ' ',
    'p', 'r', 'e', 'v', 'i', 'o', 'u', 's', ' ', 'B', 'o', 'd', 'e', 's', ' ',
    '[', 'y', ',', 'n', ']', '?', ' ', '\x00' };

  int negate_bool_idx_1;
  char N_CHAR[2];
  static const char cv8[2] = { '%', 's' };

  int negate_bool_idx_0;
  char b_param_p[2];
  static const char b_N_CHAR[2] = { 'n', '\x00' };

  static const char Y_CHAR[2] = { 'y', '\x00' };

  char ERROR_MESSAGE[46];

  /*  Constants */
  /*  Initialization */
  /*  Loop to get and validate user's input */
  do {
    exitg1 = 0;

    /*  Ask the user to enter a selection */
    printf(text_id);
    for (negate_bool_idx_1 = 0; negate_bool_idx_1 < 2; negate_bool_idx_1++) {
      N_CHAR[negate_bool_idx_1] = cv8[negate_bool_idx_1];
    }

    scanf(N_CHAR, param_p);

    /*  Compare the entry to the available types */
    for (negate_bool_idx_1 = 0; negate_bool_idx_1 < 2; negate_bool_idx_1++) {
      b_param_p[negate_bool_idx_1] = param_p[negate_bool_idx_1];
      N_CHAR[negate_bool_idx_1] = b_N_CHAR[negate_bool_idx_1];
    }

    negate_bool_idx_0 = strcmpi(b_param_p, N_CHAR);
    for (negate_bool_idx_1 = 0; negate_bool_idx_1 < 2; negate_bool_idx_1++) {
      b_param_p[negate_bool_idx_1] = param_p[negate_bool_idx_1];
      N_CHAR[negate_bool_idx_1] = Y_CHAR[negate_bool_idx_1];
    }

    negate_bool_idx_1 = strcmpi(b_param_p, N_CHAR);
    if ((negate_bool_idx_0 == 0) || (negate_bool_idx_1 == 0)) {
      exitg1 = 1;
    } else {
      for (negate_bool_idx_1 = 0; negate_bool_idx_1 < 46; negate_bool_idx_1++) {
        ERROR_MESSAGE[negate_bool_idx_1] = cv3[negate_bool_idx_1];
      }

      printf(ERROR_MESSAGE);
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
 * Return Type  : void
 */
static void d_check_num_input(double *param_p, const double limits[2])
{
  
  int exitg1;
  int exitg2;
  static const char text_id[28] = { 'L', 'i', 'n', 'e', 'a', 'r', ' ', 'g', 'a',
    'i', 'n', ' ', 'o', 'f', ' ', 't', 'h', 'e', ' ', 'f', 'i', 'l', 't', 'e',
    'r', ':', ' ', '\x00' };

  int nb_params;
  static const char c_param[3] = { '%', 'l', 'f' };

  char WRONG_TYPE_IN[55];
  char ERROR_MESSAGE[96];

  /*  Constants */
  /*  String not supported for codegen: to replace with "%*[^\n]%*1[\n]"; */
  char CLEAR_STDIN[14] = "%*[^\n]%*1[\n]";

  /*  Initialization */
  /*  Check user's input */
  do {
    exitg1 = 0;
    do {
      exitg2 = 0;

      /*  Ask the user to enter a number  */
      printf(text_id);
      nb_params = scanf(c_param, param_p);

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
        for (nb_params = 0; nb_params < 55; nb_params++) {
          WRONG_TYPE_IN[nb_params] = cv1[nb_params];
        }

        printf(WRONG_TYPE_IN);
        scanf(CLEAR_STDIN);

        /*  Clear of stdin buffer */
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    /*  Compare the entry to the possible data range */
    if ((*param_p >= limits[0]) && (*param_p <= limits[1])) {
      exitg1 = 1;
    } else {
      memcpy(&ERROR_MESSAGE[0], &cv2[0], 96U * sizeof(char));
      printf(ERROR_MESSAGE, limits[0], limits[1]);
    }
  } while (exitg1 == 0);

  /*  The parameter stands into the correct range */
}

/*
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *  Function: filter()
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
 *                int *error_flag
 * Return Type  : void
 */
static void filter_bode(const double f[NB_SAMPLES], double f_0, double q_0, double g,
  const char f_type[5], int f_order, double H_mod[NB_SAMPLES], double H_arg[NB_SAMPLES],
  int *error_flag)
{
  int filter_T_32;
  int negate_bool;
  double w_0;
  static creal_T H[NB_SAMPLES];
  int i;
  static double w[NB_SAMPLES];
  char b_f_type[5];
  char TYPE[5];
  int exitg1;
  boolean_T guard1 = false;
  double y_im;
  double bi;
  static creal_T dcv0[NB_SAMPLES];
  static creal_T dcv1[NB_SAMPLES];
  double im;
  double re;
  double br;
  double brm;

  /*  Constants */
  /*  Integer representation of filter's type */
  /*  Initializations */
  *error_flag = 0;
  filter_T_32 = 0;

  /*  Pulsation's vectors */
  for (negate_bool = 0; negate_bool < NB_SAMPLES; negate_bool++) {
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
    *error_flag = 2;
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
        for (negate_bool = 0; negate_bool < NB_SAMPLES; negate_bool++) {
          H[negate_bool].re *= g;
          H[negate_bool].im *= g;
        }

        /*  Apply the filter gain only once */
        /*  Retrieves module and argument of the transfer function H */
        b_abs(H, H_mod);
        b_log10(H_mod);

        /*  [dB] */
        angle_tf(H, H_arg);
        for (negate_bool = 0; negate_bool < NB_SAMPLES; negate_bool++) {
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
          for (negate_bool = 0; negate_bool < NB_SAMPLES; negate_bool++) {
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
            for (negate_bool = 0; negate_bool < NB_SAMPLES; negate_bool++) {
              im = w[negate_bool] / w_0;
              br = H[negate_bool].re;
              H[negate_bool].re = 0.0 - im * H[negate_bool].im;
              H[negate_bool].im = im * br;
            }
            break;

           default:
            /*  Type of filter not supported */
            *error_flag = 1;
            exitg1 = 1;
            break;
          }
        } else {
          /*  2nd order filter */
          /*  Initialisation of the transfer function with the common divider */
          y_im = 1.0 / q_0;
          for (negate_bool = 0; negate_bool < NB_SAMPLES; negate_bool++) {
            dcv0[negate_bool].re = 0.0;
            dcv0[negate_bool].im = w[negate_bool] / w_0;
          }

          b_power(dcv0, dcv1);
          for (negate_bool = 0; negate_bool < NB_SAMPLES; negate_bool++) {
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
            for (negate_bool = 0; negate_bool < NB_SAMPLES; negate_bool++) {
              dcv0[negate_bool].re = 0.0;
              dcv0[negate_bool].im = w[negate_bool] / w_0;
            }

            b_power(dcv0, dcv1);
            for (negate_bool = 0; negate_bool < NB_SAMPLES; negate_bool++) {
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
            for (negate_bool = 0; negate_bool < NB_SAMPLES; negate_bool++) {
              im = w[negate_bool] * y_im;
              br = H[negate_bool].re;
              H[negate_bool].re = 0.0 - im * H[negate_bool].im;
              H[negate_bool].im = im * br;
            }
            break;

           case 4:
            /*  Band-stop filter */
            for (negate_bool = 0; negate_bool < NB_SAMPLES; negate_bool++) {
              dcv0[negate_bool].re = 0.0;
              dcv0[negate_bool].im = w[negate_bool] / w_0;
            }

            b_power(dcv0, dcv1);
            for (negate_bool = 0; negate_bool < NB_SAMPLES; negate_bool++) {
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
            *error_flag = 1;
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
  b_y[NB_SAMPLES-1] = d2;
  b_y[0] = d1;
  if (((d1 < 0.0) != (d2 < 0.0)) && ((fabs(d1) > 8.9884656743115785E+307) ||
       (fabs(d2) > 8.9884656743115785E+307))) {
    delta1 = d1 / (NB_SAMPLES-1.0);
    delta2 = d2 / (NB_SAMPLES-1.0);
    for (k = 0; k < NB_SAMPLES-2; k++) {
      b_y[k + 1] = (d1 + delta2 * (1.0 + (double)k)) - delta1 * (1.0 + (double)k);
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
  int k;
  for (k = 0; k < NB_SAMPLES; k++) {
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
    temp_min = min(data[i],data[i+1]);
    temp_max = max(data[i],data[i+1]);
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
  static const char SEPARATOR[81] = {'-', '-', '-', '-', '-', '-', '-', '-',
  '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
  '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
  '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
  '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
  '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '\x00' };

  static const char TITLE[81]= {'-', '-', '-', '-', '-', '-', '-', '-', '-',
  '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
  '-', '-', '-', ' ', 'F', 'I', 'L', 'T', 'E', 'R', ' ', 'D', 'E', 'S', 'I',
  'G', 'N', ' ', 'A', 'N', 'D', ' ', 'V', 'I', 'E', 'W', 'E', 'R', ' ', '-',
  '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
  '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '\x00' };

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
  int    n_f;
  double f_0, q_0, g;
  double mod_min, mod_max, arg_min, arg_max;
  double frequency_range[2];
  int error_flag , i0;
  int negate_bool, neg_band_bool, neg_stop_bool;
  int mod_y_axs_step, arg_y_axs_step;
  int32_T exitg1;
  boolean_T bool = false;

  /*  Initialization */
  error_flag = 0;
  n_f = 0;
  f_0 = 0.0;
  q_0 = 0.0;
  g   = 1.0;

  /*  Definition of the logarithmic frequency range till 1 Tera Hertz */
  logspace(0.0, 9.0, f);

  /*  Program title */
  printf(SEPARATOR);
  printf(TITLE);
  printf(SEPARATOR);

  /*  Forever loop */
  int fig_id = 0;
  do {
    exitg1 = 0;

    /*  Ask for filter's parameters */
    check_str_input(f_t);
    neg_band_bool = strcmp(f_t, BAND_FILTER);
    neg_stop_bool = strcmp(f_t, BAND_FILTER);	
    if ((neg_band_bool == 0) || (neg_stop_bool == 0)) {
      check_num_input(&n_f, ORDER_LIMS_2);
    } else {
      check_num_input(&n_f, ORDER_LIMS_1);
        }
    for (i0 = 0; i0 < 2; i0++) {
      frequency_range[i0] = 1.0 + 9.99999999E+8 * (double)i0;
    }
    b_check_num_input(&f_0, frequency_range);
    if (n_f > 1) {
      c_check_num_input(&q_0, QUAL_LIMS);
    }
    d_check_num_input(&g, GAIN_LIMS);

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
        strncpy(t_word,"band",4);
      }
      else {
        strncpy(t_word,"pass",4);
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
      snprintf(amplitude_title,sizeof(amplitude_title),"%s %s%s%s %s %d ",
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
      snprintf(phase_title,sizeof(phase_title),"%s %s%s%s %s %d",
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

    negate_bool = strcmpi(keep_bodes, N_CHAR);
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

    negate_bool = strcmpi(new_bodes, N_CHAR);
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
    printf(SEPARATOR);
  } while (negate_bool != 0);

  return error_flag;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
