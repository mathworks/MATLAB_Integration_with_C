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
  SEPARATOR    = '--------------------------------------------------------------------------------';
  TITLE        = '--------------------------- FILTER DESIGN AND VIEWER ---------------------------';
  FILTER_TYPE  = 'Type of filter [low][high][band][stop]: ';
  FILTER_ORDER = 'Order of the filter: ';
  CUTOFF_FREQ  = 'Cutoff frequency: ';
  QUALITY_FAC  = 'Quality factor: ';
  LINEAR_GAIN  = 'Linear gain of the filter: ';
  BAND_FILTER  = 'band';
  STOP_FILTER  = 'stop';
  N_CHAR       = 'n';
  PREV_BODES   = 'Do you want to keep the previous Bodes [y,n]? ';
  OTHER_BODES  = 'Do you want to see Bodes of another filter [y,n]? ';
  ERROR_TEXT   = 'Bodes cannot be maid due to a misconfiguration of parameters.';
  ERROR_T_TEXT = 'This type of filter is not supported.';
  ERROR_N_TEXT = 'This order value is not supported for such filters. It must be an even value.';
  ERROR_U_TEXT = 'Unknown error. Please re-submit filter''s parameters.';
  ERROR_TYPE   = int32(1);
  ERROR_ORDER  = int32(2);

  % Initialization
  error_flag = int32(0);
  f_t = char(zeros(1,4)); %#ok<NASGU>
  n_f = 0;
  f_0 = 0;
  q_0 = 0;
  g   = 1;
  fig_id = 0;

  % Definition of the logarithmic frequency range till 1 Giga Hertz
  power_f_min = 0; power_f_max = 9; nb_pts = 1e005;
  f = logspace(power_f_min,power_f_max,nb_pts);
  % Program title
  disp(SEPARATOR);
  disp(TITLE);
  disp(SEPARATOR);
  % Forever loop
  while(1)
    % Ask for filter's parameters
    f_t = check_str_input(FILTER_TYPE);
    if (strcmp(f_t,BAND_FILTER) || strcmp(f_t,STOP_FILTER))
      n_f = check_num_input(n_f,[2 10],FILTER_ORDER);
    else
      n_f = check_num_input(n_f,[1 10],FILTER_ORDER);
    end
    f_0 = check_num_input(f_0,[10^power_f_min,10^power_f_max],CUTOFF_FREQ);
    if (n_f > 1)
      q_0 = check_num_input(q_0,[0.1 10],QUALITY_FAC);
    end
    g = check_num_input(g,[0.001,1000],LINEAR_GAIN);

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
    keep_bodes = check_yes_or_no(PREV_BODES);
    if (strcmpi(keep_bodes,N_CHAR))
      close all;
    end
    % Ask the user if he wants to see other filter's Bodes
    new_bodes = check_yes_or_no(OTHER_BODES);
    if (strcmpi(new_bodes,N_CHAR))
      break;
    end
    disp(SEPARATOR);
  end
end
