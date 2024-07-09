%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Goal    : Test of the main() and main_mex() functions
% Copyright 2024 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear variables; close all; clc;

% Test the MEX file if set to '1'
TEST_MEX = 0;
if (TEST_MEX == 0)
  % Call of the standard MATLAB code
  error_flag = main();
else
  % Generate the MEX function of the main file
  disp('Building the MEX file, please wait...');
  codegen('main');
  disp('The MEX file has been built successfully.');
  % Call of the MEX function
  error_flag = main_mex();
end

% Execution status
disp(['The system has returned with the error status: ',num2str(error_flag)]);
