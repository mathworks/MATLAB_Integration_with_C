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
% Copyright 2018 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  %#codegen 
  %#ok<*NASGU>

  % Constants
  NEW_LINE = char(10); %#ok<CHARTEN>
  WRONG_TYPE_IN = coder.const(['Input not recognised as an integer, ',...
                               'please try again.',NEW_LINE,0]);
  ERROR_MESSAGE = coder.const(['For this filter, the parameter should ',...
                               'be between %.3f and %.3f.',NEW_LINE,...
                               'Please, enter a correct value.',NEW_LINE,0]);
  % String not supported for codegen: to replace with "%*[^\n]%*1[\n]";
  CLEAR_STDIN = coder.opaque('char','0');

  % Initialization
  nb_params   = int32(0);
  negate_bool = int32(1);

  % Check user's input
  while(1)
    % Ask the user to enter a number 
    coder.ceval('printf',coder.rref(text_id));
    nb_params = coder.ceval('scanf',coder.rref(c_param),coder.wref(param_p));
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
      coder.ceval('printf',WRONG_TYPE_IN);
      coder.ceval('scanf' ,CLEAR_STDIN); % Clear of stdin buffer
    else
      % Compare the entry to the possible data range
      if (param_p >= limits(1) && param_p <= limits(2))
        % The parameter stands into the correct range
        break;
      else
        coder.ceval('printf',ERROR_MESSAGE,limits(1),limits(2));
      end
	  end
  end
end
