function error_flag = main()
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Function: main()
% Goal    : Main C function of the executable
%
% IN      : -
% IN/OUT  : -
% OUT     : -
%
% Copyright 2018 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  %#codegen
  % Functions that are not translated into C code
  coder.extrinsic('plot_filter');

  % Constants
  SEPARATOR    = ['-------------------------------------------------------------------------------',0];
  TITLE        = ['--------------------------- FILTER DESIGN AND VIEWER --------------------------',0];
  FILTER_TYPE  = ['Type of filter [low][high][band][stop]: ',0];
  FILTER_ORDER = ['Order of the filter: ',0];
  CUTOFF_FREQ  = ['Cutoff frequency: ',0];
  QUALITY_FAC  = ['Quality factor: ',0];
  LINEAR_GAIN  = ['Linear gain of the filter: ',0];
  BAND_FILTER  = ['band',0];
  STOP_FILTER  = ['stop',0];
  N_CHAR       = ['n',0];
  PREV_BODES   = ['Do you want to keep the previous Bodes [y,n]? ',0];
  OTHER_BODES  = ['Do you want to see Bodes of another filter [y,n]? ',0];
  ERROR_TEXT   = ['Bodes cannot be maid due to a misconfiguration of parameters.',0];
  ERROR_T_TEXT = ['This type of filter is not supported.',0];
  ERROR_N_TEXT = ['This order value is not supported for such filters. It must be an even value.',0];
  ERROR_U_TEXT = ['Unknown error. Please re-submit filter''s parameters.',0];
  ERROR_TYPE   = int32(1);
  ERROR_ORDER  = int32(2);
  POWER_F_MIN  = 0;
  POWER_F_MAX  = 9;
  NB_PTS       = 1e005;
  ORDER_LIMS_1 = [1 10];
  ORDER_LIMS_2 = [2 10];
  QUAL_LIMS    = [0.1 10];
  GAIN_LIMS    = [0.001 1000];
  INTEGER      = coder.opaque('char *','"%d"');
  LONG_DOUBLE  = coder.opaque('char *','"%lf"');

  % Initialization
  error_flag = int32(0);
  f_0 = double(0);
  q_0 = double(0);
  g   = double(1);
  n_f = int32(0);
  f_t = ['0000',0];
  negate_bool   = int32(1); %#ok<*NASGU>
  neg_band_bool = int32(1);
  neg_stop_bool = int32(1);
  fig_id        = int32(0);
  keep_bodes    = ['0',0];
  new_bodes     = ['0',0];

  % Definition of the logarithmic frequency range
  f = logspace(POWER_F_MIN,POWER_F_MAX,NB_PTS);
  frequency_range = 10.^[POWER_F_MIN,POWER_F_MAX];
  
  % Program title
  fprintf('%s\n',SEPARATOR);
  fprintf('%s\n',TITLE);
  fprintf('%s\n',SEPARATOR);

  % Forever loop
  while(1)
    % Ask for filter's parameters
    f_t = check_str_input(f_t,FILTER_TYPE);
    neg_band_bool = coder.ceval('strcmp',coder.rref(f_t),BAND_FILTER);
    neg_stop_bool = coder.ceval('strcmp',coder.rref(f_t),STOP_FILTER);
    if (neg_band_bool == 0 || neg_stop_bool == 0)
      n_f = check_num_input(n_f,ORDER_LIMS_2,FILTER_ORDER,INTEGER);
    else
      n_f = check_num_input(n_f,ORDER_LIMS_1,FILTER_ORDER,INTEGER);
    end
    f_0 = check_num_input(f_0,frequency_range,CUTOFF_FREQ,LONG_DOUBLE);
    if (n_f > 1)
      q_0 = check_num_input(q_0,QUAL_LIMS,QUALITY_FAC,LONG_DOUBLE);
    end
    g = check_num_input(g,GAIN_LIMS,LINEAR_GAIN,LONG_DOUBLE);

    % Bodes calculation
    [H_mod,H_arg,error_flag] = filter_bode(f,f_0,q_0,g,f_t,n_f);
    % Display of results (target dependent)
    if (error_flag == 0)
      fig_id = fig_id+1;
      plot_filter(f,H_mod,H_arg,f_t,n_f,fig_id);
    else % An error occured and bodes cannot be plotted
      disp(ERROR_TEXT);
      switch (error_flag)
        case ERROR_TYPE
          disp(ERROR_T_TEXT);
        case ERROR_ORDER
          disp(ERROR_N_TEXT);
        otherwise
          disp(ERROR_U_TEXT);
      end
    end

    % Ask the user if he wants to keep the previous graphs
    keep_bodes = check_yes_or_no(keep_bodes,PREV_BODES);
    negate_bool = coder.ceval('_strcmpi',coder.rref(keep_bodes),N_CHAR);
    if (negate_bool == 0)
      fig_id = fig_id-1;
      % C implementation in order to close the previous windows
    end
    % Ask the user if he wants to see other filter's Bodes
    new_bodes = check_yes_or_no(new_bodes,OTHER_BODES);
    negate_bool = coder.ceval('_strcmpi',coder.rref(new_bodes),N_CHAR);
    if (negate_bool == 0)
      break;
      % C implementation in order to quit the console
    end
    fprintf('%s\n',SEPARATOR);
  end
end
