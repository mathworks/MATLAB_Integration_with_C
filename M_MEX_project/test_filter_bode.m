%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Goal    : Test of the filter_bode() and filter_bode_mex() functions
% Copyright 2018 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear variables; close all; clc;

% Filters definitions
f     = (1:10:1e006);
f_0   = [1e003,1e003,1e003,1e003,1e003,1e003,1e003,1e003];
q_0   = [0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5];
g     = [1,10,10,100,1,1,10,100];
type  = char('low','high','low','high','band','stop','test','band');
order = int32([1,1,2,2,2,2,1,3]);
% Initializations
nb_filter = length(order);
nb_frequs = length(f);
H_mod = zeros(nb_filter,nb_frequs);
H_mod_mex = zeros(nb_filter,nb_frequs);
H_arg = zeros(nb_filter,nb_frequs);
H_arg_mex = zeros(nb_filter,nb_frequs);
error_flag = zeros(1,nb_filter);
error_flag_mex = zeros(1,nb_filter);
disp('Initialization done.');

% Define the configuration object for the MEX file to generate
cfg = coder.config('mex');
cfg.FilePartitionMethod = 'SingleFile';
% MEX file generation
codegen filter_bode -launchreport -config cfg -args {zeros(1,1e005),0,0,0,char(zeros(1,4)),int32(0)}
disp('MEX generated successfully.');

% Bodes calculation
for i=1:1:nb_filter
  [H_mod(i,:),H_arg(i,:),error_flag(i)] = ...
    filter_bode(f,f_0(i),q_0(i),g(i),char(type(i,:)),order(i));
  [H_mod_mex(i,:),H_arg_mex(i,:),error_flag_mex(i)] = ...
    filter_bode_mex(f,f_0(i),q_0(i),g(i),char(type(i,:)),order(i));
end
disp('Bodes calculation done.');

% Display of results in reverse order to have the first filter at first
for i=nb_filter:-1:1
  if (error_flag(i) == 0)
    plot_filter(f,H_mod(i,:),H_arg(i,:),char(type(i,:)),order(i),i);
  else
    disp(['MAT, the following error occured: ' num2str(error_flag(i))]);
  end
  if (error_flag_mex(i) == 0)
    plot_filter(f,H_mod_mex(i,:),H_arg_mex(i,:),char(type(i,:)),order(i),i);
  else
    disp(['MEX, the following error occured: ' num2str(error_flag_mex(i))]);
  end
end
disp('Bodes plots done.');

% Check if differences exist between the MATLAB and MEX vectors
diff_mod = sum(abs(H_mod - H_mod_mex),2);
diff_arg = sum(abs(H_arg - H_arg_mex),2);
disp('Differences between the MATLAB and MEX Bodes:');
disp(['Module => ' num2str(diff_mod')]);
disp(['Angle  => ' num2str(diff_arg')]);
