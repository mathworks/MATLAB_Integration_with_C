function param_p = check_num_input(param_p,limits,text_id,c_param)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Function: check_num_input()
% Goal    : Checks a numerical input parameter given by the user
%
% IN      : - limits : boundaries allowed for the desired parameter
%           - text_id: text to display related to the desired parameter
%           - c_param: type of C data
% IN/OUT  : - param_p: parameter to set via the user interface
% OUT     : - 
%
% Copyright 2024 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  %#codegen 
  %#ok<*NASGU>

  % Constant
  % Force the string regular expression in the generated C code for scanf_s
  CLEAR_STDIN = coder.opaque('char *','"%*[^\n]%*1[\n]"');

  % Initialization
  nb_params   = int32(0);
  negate_bool = int32(1);

  % Check user's input
  while(1)
    % Ask the user to enter a number 
    fprintf('%s',text_id);
    nb_params = coder.ceval('scanf_s',c_param,coder.wref(param_p),int32(1));
    % Check if a number or some chars have been entered
    if (nb_params == 1)
      % One entry => this is a number
      negate_bool = int32(0);
    else
      % Multiple entries => this is an array of chars
      negate_bool = int32(1);
    end
    % Post process the keyboard input buffer data
    if (negate_bool == 1)
      fprintf('The value provided is not of the right data type.\n');
      fprintf('Please, enter a correct value.\n');
      % Clear the input buffer
      coder.ceval('scanf_s',CLEAR_STDIN);
    else
      % Compare the entry to the possible data range
      if (param_p >= limits(1) && param_p <= limits(2))
        % The parameter stands into the correct range
        break;
      else
        fprintf('For this filter, the parameter should be between %.3f and %.3f.\n',...
                limits(1),limits(2));
        fprintf('Please, enter a correct value.\n');
      end
    end
  end
end
