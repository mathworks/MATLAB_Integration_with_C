function param_p = check_str_input(param_p,text_id)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Function: check_str_input()
% Goal    : Checks string input parameter given by the user
%
% IN      : - text_id: text to display related to the desired parameter
% IN/OUT  : - param_p: parameter to set via the user interface
% OUT     : - 
%
% Copyright 2024 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  %#codegen
  % Constants
  ERROR_MESSAGE = ['Unknown filter type. Please, enter a correct one.',0];
  FILTER        = [['low',0,0];['high',0];['band',0];['stop',0]];
  NB_FILTERS    = int32(4);

  % Initialization
  negate_bool = int32(1);
  char_length = int32(2); % sizeof(char)
  nb_input_types = int32(0); %#ok<NASGU>
  
  % Loop to get and validate user's input
  while(1)
    % Ask the user to enter a filter type
    fprintf('%s',text_id);
    coder.ceval('scanf_s','%4s',coder.wref(param_p),int32(4)*char_length);
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
      fprintf('%s\n',ERROR_MESSAGE);
      % Force the string regular expression in the generated C code for scanf_s
      CLEAR_STDIN = coder.opaque('char *','"%*[^\n]%*1[\n]"');
      % Clear the input buffer
      coder.ceval('scanf_s', CLEAR_STDIN);
    end
  end
end
