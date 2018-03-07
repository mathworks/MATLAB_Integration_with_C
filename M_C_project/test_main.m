%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Goal    : Test of the main_mex() function
% Copyright 2018 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear variables; close all; clc;

% Test the MEX file if set to '1'
TEST_MEX = 1;
if (TEST_MEX ~= 1)
  % Call of the standard MATLAB code
  error('The coder.ceval function is not supported in MATLAB. Generate the MEX file.');
else
  error('The MEX file has been generated successfully, but it cannot be tested due to IOs console access.');
end
