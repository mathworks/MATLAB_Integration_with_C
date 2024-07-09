%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Goal    : Test of the main_mex() function
% Copyright 2024 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear variables; close all; clc;

% Test the MEX file if set to '1'
TEST_MEX = 0;
if (TEST_MEX == 0)
  % Call of the standard MATLAB code
  error('The coder.ceval function is not supported in MATLAB. Generate the MEX file.');
else
  % Call of the MEX function
  error('The write access to the console via scanf() or scanf_s() is not supported in MATLAB.');
end
