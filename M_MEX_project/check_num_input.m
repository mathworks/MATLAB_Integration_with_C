function param = check_num_input(param,limits,text_id)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Function: check_num_input()
% Goal    : Checks a numerical input parameter given by the user
%
% IN      : - limits : boundaries allowed for the desired parameter
%           - text_id: text to display related to the desired parameter
% IN/OUT  : - param  : parameter to set via the user interface
% OUT     : -
%
% Copyright 2018 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  %#codegen
  % Functions that are not translated into C code
  coder.extrinsic('input','num2str');

  ERROR_MESSAGE_1 = 'For this filter, the parameter should be between ';
  ERROR_MESSAGE_2 = 'The value provided is not of the right data type.';
  ERROR_MESSAGE_3 = 'Please, enter a correct value.';

  % Loop to get and validate user's input
  while(1)
    param_str = input(text_id,'s');
    param = str2double(param_str);
    if ~isnan(param)
      if (param >= limits(1) && param <= limits(2))
        % The parameter stands into the correct range
        break;
      else
        disp([ERROR_MESSAGE_1,num2str(limits(1)),' and ',num2str(limits(2)),'. ']);
        disp(ERROR_MESSAGE_3);
      end
    else
      disp(ERROR_MESSAGE_2);
      disp(ERROR_MESSAGE_3);
    end
  end
end
