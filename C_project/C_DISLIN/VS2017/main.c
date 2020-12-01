/*
 * File: main.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 01-Dec-2020 16:51:46
 */

/* Include Files */
#include "main.h"
#include <string.h>
#include <float.h>
#include "dislin.h" /* Added of the graphical library */
#include <math.h>
#include <stdio.h>

/* Variable Definitions */
static const char cv[20] = { 'l', 'o', 'w', '\x00', '\x00', 'h', 'i', 'g', 'h',
  '\x00', 'b', 'a', 'n', 'd', '\x00', 's', 't', 'o', 'p', '\x00' };

/* Function Declarations */
static void b_check_num_input(double *param_p, const double limits[2], char
  * c_param);
static void b_check_yes_or_no(char param_p[2]);
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
static void power(const creal_T a[NB_SAMPLES], creal_T y[NB_SAMPLES]);
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
  int negate_bool_idx_0;
  int negate_bool_idx_1;
  char b_cv[2];
  char cv1[2];
  char cv2[2];

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
    scanf_s(&b_cv[0], &cv1[0], 2);

    /*  Compare the entry to the available types */
    param_p[0] = cv1[0];
    b_cv[0] = cv1[0];
    cv2[0] = 'n';
    param_p[1] = cv1[1];
    b_cv[1] = cv1[1];
    cv2[1] = '\x00';
    negate_bool_idx_0 = _strcmpi(&b_cv[0], &cv2[0]);
    b_cv[0] = cv1[0];
    cv2[0] = 'y';
    b_cv[1] = cv1[1];
    cv2[1] = '\x00';
    negate_bool_idx_1 = _strcmpi(&b_cv[0], &cv2[0]);
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
  int b_i;
  int exitg1;
  int i;
  int i1;
  int negate_bool;
  char cv1[5];
  char cv2[5];
  char cv3[5];
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
    scanf_s(&b_cv[0], &cv1[0], 8);
    for (i = 0; i < 5; i++) {
      param_p[i] = cv1[i];
    }

    /*  Compare the entry to the available types */
    b_i = 0;
    exitg2 = false;
    while ((!exitg2) && (b_i < 4)) {
      for (i1 = 0; i1 < 5; i1++) {
        cv2[i1] = cv1[i1];
        cv3[i1] = cv[i1 + 5 * b_i];
      }

      negate_bool = strcmp(&cv2[0], &cv3[0]);
      if (negate_bool == 0) {
        exitg2 = true;
      } else {
        b_i++;
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
  int negate_bool_idx_0;
  int negate_bool_idx_1;
  char b_cv[2];
  char cv1[2];
  char cv2[2];

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
    scanf_s(&b_cv[0], &cv1[0], 2);

    /*  Compare the entry to the available types */
    param_p[0] = cv1[0];
    b_cv[0] = cv1[0];
    cv2[0] = 'n';
    param_p[1] = cv1[1];
    b_cv[1] = cv1[1];
    cv2[1] = '\x00';
    negate_bool_idx_0 = _strcmpi(&b_cv[0], &cv2[0]);
    b_cv[0] = cv1[0];
    cv2[0] = 'y';
    b_cv[1] = cv1[1];
    cv2[1] = '\x00';
    negate_bool_idx_1 = _strcmpi(&b_cv[0], &cv2[0]);
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
 *            - H_arg : argument of the transfer function in [&#xFFFD;]
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
  static creal_T H[NB_SAMPLES];
  static creal_T H_tmp[NB_SAMPLES];
  static creal_T dcv[NB_SAMPLES];
  static double b_H_tmp[NB_SAMPLES];
  static double w[NB_SAMPLES];
  double a_im;
  double b_a_im;
  double b_bi;
  double b_bim;
  double b_br;
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
  double d;
  double d1;
  double d10;
  double d11;
  double d12;
  double d13;
  double d14;
  double d15;
  double d16;
  double d17;
  double d2;
  double d3;
  double d4;
  double d5;
  double d6;
  double d7;
  double d8;
  double d9;
  double d_im;
  double d_re;
  double e_im;
  double f_im;
  double g_im;
  double h_im;
  double i_im;
  double im;
  double j_im;
  double re;
  double re_tmp;
  double s;
  double w_0;
  int b_i;
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
  boolean_T guard1 = false;

  /*  Constants */
  /*  Integer representation of filter's type */
  /*  Initializations */
  *err_f = 0;
  filter_T_32 = 0;

  /*  Pulsation's vectors */
  for (i = 0; i < NB_SAMPLES; i++) {
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
        /*  Apply the filter gain only once */
        /*  Retrieves module and argument of the transfer function H */
        /*  [dB] */
        for (k = 0; k < NB_SAMPLES; k++) {
          re = g * H[k].re;
          im = g * H[k].im;
          H[k].re = re;
          H[k].im = im;
          H_mod[k] = 20.0 * log10(rt_hypotd(re, im));
          H_arg[k] = atan2(im, re) * 180.0 / 3.1415926535897931;
        }

        /*  [&#xFFFD;] */
        exitg1 = 1;
      }

      if (guard1) {
        f_order -= n_cell_order;

        /*  Calculate each filter's cell separately */
        if (n_cell_order == 1) {
          /*  1st order filter */
          /*  Initialization of the transfer function with the common divider */
          for (i3 = 0; i3 < NB_SAMPLES; i3++) {
            re_tmp = w[i3] / w_0;
            H_tmp[i3].re = 0.0;
            H_tmp[i3].im = re_tmp;
            if (re_tmp == 0.0) {
              b_re = 1.0;
              b_im = 0.0;
            } else {
              bim = fabs(re_tmp);
              if (1.0 > bim) {
                b_d = 1.0 + re_tmp * re_tmp;
                b_re = 1.0 / b_d;
                b_im = (0.0 - re_tmp) / b_d;
              } else if (bim == 1.0) {
                b_re = 0.5;
                if (re_tmp > 0.0) {
                  b_re_tmp = 0.5;
                } else {
                  b_re_tmp = -0.5;
                }

                b_im = 0.0 - b_re_tmp;
              } else {
                s = 1.0 / re_tmp;
                b_d = re_tmp + s;
                b_re = s / b_d;
                b_im = -1.0 / b_d;
              }
            }

            d6 = H[i3].re;
            d8 = H[i3].im;
            f_im = d6 * b_im + d8 * b_re;
            d6 = d6 * b_re - d8 * b_im;
            H[i3].re = d6;
            H[i3].im = f_im;
          }

          switch (filter_T_32) {
           case 1:
            /*  Low-pass filter */
            break;

           case 2:
            /*  High-pass filter */
            for (i5 = 0; i5 < NB_SAMPLES; i5++) {
              d2 = H_tmp[i5].re;
              d3 = H_tmp[i5].im;
              d4 = H[i5].im;
              d5 = H[i5].re;
              c_im = d2 * d4 + d3 * d5;
              d5 = d2 * d5 - d3 * d4;
              H[i5].re = d5;
              H[i5].im = c_im;
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
          for (i2 = 0; i2 < NB_SAMPLES; i2++) {
            d = w[i2] / w_0;
            b_H_tmp[i2] = d;
            dcv[i2].re = 0.0;
            dcv[i2].im = d;
          }

          power(dcv, H_tmp);
          a_im = 1.0 / q_0;
          for (i4 = 0; i4 < NB_SAMPLES; i4++) {
            d1 = b_H_tmp[i4];
            br = 1.0 + H_tmp[i4].re;
            bi = a_im * d1 + H_tmp[i4].im;
            if (bi == 0.0) {
              d_re = 1.0 / br;
              e_im = 0.0;
            } else if (br == 0.0) {
              d_re = 0.0;
              e_im = -(1.0 / bi);
            } else {
              brm = fabs(br);
              b_bim = fabs(bi);
              if (brm > b_bim) {
                b_s = bi / br;
                c_d = br + b_s * bi;
                d_re = 1.0 / c_d;
                e_im = (0.0 - b_s) / c_d;
              } else if (b_bim == brm) {
                if (br > 0.0) {
                  b_br = 0.5;
                } else {
                  b_br = -0.5;
                }

                d_re = b_br / brm;
                if (bi > 0.0) {
                  b_bi = 0.5;
                } else {
                  b_bi = -0.5;
                }

                e_im = (0.0 - b_bi) / brm;
              } else {
                b_s = br / bi;
                c_d = bi + b_s * br;
                d_re = b_s / c_d;
                e_im = -1.0 / c_d;
              }
            }

            d16 = H[i4].re;
            d17 = H[i4].im;
            j_im = d16 * e_im + d17 * d_re;
            d16 = d16 * d_re - d17 * e_im;
            H[i4].re = d16;
            H[i4].im = j_im;
          }

          switch (filter_T_32) {
           case 1:
            /*  Low-pass filter */
            break;

           case 2:
            /*  High-pass filter */
            for (i6 = 0; i6 < NB_SAMPLES; i6++) {
              d7 = H_tmp[i6].re;
              d9 = H_tmp[i6].im;
              d10 = H[i6].im;
              d13 = H[i6].re;
              g_im = d7 * d10 + d9 * d13;
              d13 = d7 * d13 - d9 * d10;
              H[i6].re = d13;
              H[i6].im = g_im;
            }
            break;

           case 3:
            /*  Band-pass filter */
            a_im = 1.0 / (2.0 * q_0 * w_0);
            for (i8 = 0; i8 < NB_SAMPLES; i8++) {
              b_a_im = w[i8] * a_im;
              d11 = H[i8].im;
              d14 = H[i8].re;
              h_im = b_a_im * d14;
              d14 = 0.0 - b_a_im * d11;
              H[i8].re = d14;
              H[i8].im = h_im;
            }
            break;

           case 4:
            /*  Band-stop filter */
            for (i7 = 0; i7 < NB_SAMPLES; i7++) {
              c_re = 1.0 + H_tmp[i7].re;
              d_im = H_tmp[i7].im;
              d12 = H[i7].im;
              d15 = H[i7].re;
              i_im = c_re * d12 + d_im * d15;
              d15 = c_re * d15 - d_im * d12;
              H[i7].re = d15;
              H[i7].im = i_im;
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
 * Arguments    : const creal_T a[NB_SAMPLES]
 *                creal_T y[NB_SAMPLES]
 * Return Type  : void
 */
static void power(const creal_T a[NB_SAMPLES], creal_T y[NB_SAMPLES])
{
  double b_im;
  double b_re;
  double d;
  double d1;
  double r;
  double y_im;
  double y_re;
  int k;
  for (k = 0; k < NB_SAMPLES; k++) {
    d = a[k].re;
    d1 = a[k].im;
    if ((d1 == 0.0) && (d >= 0.0)) {
      y[k].re = pow(d, 2.0);
      y[k].im = 0.0;
    } else if (d == 0.0) {
      y[k].re = -pow(d1, 2.0);
      y[k].im = 0.0;
    } else {
      if (d1 == 0.0) {
        if (d < 0.0) {
          b_re = log(fabs(d));
          b_im = 3.1415926535897931;
        } else {
          b_re = log(d);
          b_im = 0.0;
        }
      } else if ((fabs(d) > 8.9884656743115785E+307) || (fabs(d1) >
                  8.9884656743115785E+307)) {
        b_re = log(rt_hypotd(d / 2.0, d1 / 2.0)) + 0.69314718055994529;
        b_im = atan2(d1, d);
      } else {
        b_re = log(rt_hypotd(d, d1));
        b_im = atan2(d1, d);
      }

      y_re = 2.0 * b_re;
      y_im = 2.0 * b_im;
      if (y_im == 0.0) {
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

  static const char BAND_FILTER[5] = "band";
  static const char STOP_FILTER[5] = "stop";
  static const char N_CHAR[2]      = { 'n', '\x00' };

  const double ORDER_LIMS_1[2] = {1,10};
  const double ORDER_LIMS_2[2] = {2,10};
  const double QUAL_LIMS[2]    = {0.1,10};
  const double GAIN_LIMS[2]    = {0.001,1000};
  
  /* Vectors definition */
  static double f[NB_SAMPLES];
  static double H_arg[NB_SAMPLES];
  static double H_mod[NB_SAMPLES];
  static double y[NB_SAMPLES];

  /* Variables declaration */
  char f_t[5]        = "0000";
  char t_word[5]     = "0000";
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

  /*  Definition of the logarithmic frequency range */
  y[99999] = 9.0;
  y[0] = 0.0;
  for (int k = 0; k < 99998; k++) {
    y[k + 1] = ((double)k + 1.0) * 9.0000900009000085E-5;
  }

  for (int b_k = 0; b_k < 100000; b_k++) {
    f[b_k] = pow(10.0, y[b_k]);
  }

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
      name  ("arg(H) [degree]","Y"); // �symbol in unicode:"\u00B0"
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
