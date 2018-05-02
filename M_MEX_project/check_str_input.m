function param = check_str_input(text_id)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Function: check_str_input()
% Goal    : Checks string input parameter given by the user
%
% IN      : - text_id : text to display related to the desired parameter
% IN/OUT  : -
% OUT     : -
%
% Copyright 2018 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  %#codegen
  % Functions that are not translated into C code
  coder.extrinsic('input');

  ERROR_MESSAGE = 'Unknown filter type. Please, enter a correct one.';
  FILTER        = ['low ';'high';'band';'stop'];
  NB_FILTERS    = 4;
  % Initialization
  boolean = false;

  % Loop to get and validate user's input
  while(1)
    param_str = input(text_id,'s');
    % Handling of special strings
    if (strcmp(param_str,'low'))
      param_str = [param_str,' ']; %#ok<AGROW>
    end
    % Compare the entry to the available types
    for i=1:1:NB_FILTERS
      boolean = strcmp(param_str,FILTER(i,:));
      if (boolean == true)
        break; % No need to go on with the FOR loop
      end
    end
    if (boolean == true)
      break; % Leave the WHILE loop because one type matches the entry
    else
      % No right type selected
      disp(ERROR_MESSAGE);
    end
  end
  param = param_str;
end
