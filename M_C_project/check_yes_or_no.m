function param_p = check_yes_or_no(param_p,text_id)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Function: check_yes_or_no()
% Goal    : Checks if the given parameter is either 'yes' or 'no'
%
% IN      : - text_id: text to display related to the desired parameter
% IN/OUT  : - param_p: parameter to set via the user interface 
% OUT     : -
%
% Copyright 2018 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  %#codegen
  % Constants
  NEW_LINE = char(10); %#ok<CHARTEN>
  ERROR_MESSAGE = ['Please, enter [y,Y] for YES or [n,N] for NO.',NEW_LINE,0];
  N_CHAR = ['n',0];
  Y_CHAR = ['y',0];

  % Initialization
  negate_bool = int32(ones(1,2));

  % Loop to get and validate user's input
  while(1)
    % Ask the user to enter a selection
    coder.ceval('printf',coder.rref(text_id));
    coder.ceval('scanf','%s', coder.wref(param_p));
    % Compare the entry to the available types
    negate_bool(1) = coder.ceval('strcmpi',param_p,N_CHAR);
    negate_bool(2) = coder.ceval('strcmpi',param_p,Y_CHAR);
    if (negate_bool(1) == 0 || negate_bool(2) == 0)
      % Handle graphical windows in C
      break;
    else
      coder.ceval('printf',ERROR_MESSAGE);
    end
  end
end
