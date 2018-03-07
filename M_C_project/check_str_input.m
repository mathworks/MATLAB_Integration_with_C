function param_p = check_str_input(param_p,text_id)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Function: check_str_input()
% Goal    : Checks string input parameter given by the user
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
  ERROR_MESSAGE = ['Unknown filter type. Please, enter a correct one.',...
                   NEW_LINE,0];
  FILTER        = [['low',0,0];['high',0];['band',0];['stop',0]];
  NB_FILTERS    = int32(4);

  % Initialization
  negate_bool = int32(1);

  % Loop to get and validate user's input
  while(1)
    % Ask the user to enter a filter type
    coder.ceval('printf',coder.rref(text_id));
    coder.ceval('scanf' ,'%s',coder.wref(param_p));
    % Compare the entry to the available types
    for i=int32(1):1:NB_FILTERS
      negate_bool = coder.ceval('strcmp',param_p,FILTER(i,:));
      if (negate_bool == 0)
        break; % No need to go on with the FOR loop
      end
    end
    if (negate_bool == 0)
      break; % Leave the WHILE loop because one type matches the entry
    else
      % No right type selected
      coder.ceval('printf',ERROR_MESSAGE);
    end
  end
end
