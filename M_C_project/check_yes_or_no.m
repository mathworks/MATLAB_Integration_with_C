function param_p = check_yes_or_no(param_p,text_id)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Function: check_yes_or_no()
% Goal    : Checks if the given parameter is either 'yes' or 'no'
%
% IN      : - text_id: text to display related to the desired parameter
% IN/OUT  : - param_p: parameter to set via the user interface 
% OUT     : -
%
% Copyright 2024 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  %#codegen
  % Constants
  NEW_LINE = char(10); %#ok<CHARTEN>
  ERROR_MESSAGE = ['Please, enter [y,Y] for YES or [n,N] for NO.',NEW_LINE,0];
  N_CHAR = ['n',0];
  Y_CHAR = ['y',0];

  % Initialization
  negate_bool = int32(ones(1,2));
  char_length = int32(2); % sizeof(char)

  % Loop to get and validate user's input
  while(1)
    % Ask the user to enter a selection
    fprintf('%s',text_id);
    coder.ceval('scanf_s','%s',coder.wref(param_p),char_length);
    % Compare the entry to the available types
    negate_bool(1) = coder.ceval('_strcmpi',param_p,N_CHAR);
    negate_bool(2) = coder.ceval('_strcmpi',param_p,Y_CHAR);
    if (negate_bool(1) == 0 || negate_bool(2) == 0)
      % Handle graphical windows in C
      break;
    else
      fprintf('%s\n',ERROR_MESSAGE);
      % Force the string regular expression in the generated C code for scanf_s
      CLEAR_STDIN = coder.opaque('char *','"%*[^\n]%*1[\n]"');
      % Clear the input buffer
      coder.ceval('scanf_s', CLEAR_STDIN);
    end
  end
end
