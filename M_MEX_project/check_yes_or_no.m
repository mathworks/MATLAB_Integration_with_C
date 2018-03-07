function param = check_yes_or_no(text_id)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Function: check_yes_or_no()
% Goal    : Checks if the given parameter is either 'yes' or 'no'
%
% IN      : - text_id: text to display related to the desired parameter
% IN/OUT  : -
% OUT     : - param  : parameter to set via the user interface
%
% Copyright 2018 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  %#codegen
  % Functions that are not translated into C code
  coder.extrinsic('input');

  ERROR_MESSAGE = 'Please, enter [y,Y] for YES or [n,N] for NO.';
  N_CHAR = 'n';
  Y_CHAR = 'y';
  % Loop to get and validate user's input
  while(1)
    % Ask the user to enter a selection
    param = input(text_id,'s');
    if (strcmpi(param,Y_CHAR) || strcmpi(param,N_CHAR))
      break;
    else
      disp(ERROR_MESSAGE);
    end
  end
end
