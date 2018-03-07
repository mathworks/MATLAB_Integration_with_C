%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Script: C_codegen
% Goal  : Generates C code out of the following filter function:
%         [H_mod,H_arg,error_flag] = filter_bode(f,f_0,q_0,g,f_type,f_order)
%
% IN      : - f      : 1x1e005 double; vector of frequency values 
%           - f_0    :     1x1 double; cutoff frequency
%           - g      :     1x1 double; gain
%           - q_0    :     1x1 double; quality factor (for 2nd order sections)
%           - f_type :     1x1  int32; type: 'low', 'high', 'band' and 'stop'
%           - f_order:     1x1  int32; order
%
% Copyright 2018 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear variables; clc;

% Constants
BUILD_FOLDER   = 'Artifacts';
ZIP_FILE       = 'MATLAB.zip';
ZIP_FILE_PATH  = [BUILD_FOLDER '\' ZIP_FILE ];
VS20XY_PROJECT = '..\GUI';

% Fully remove previous generated folder and files
if exist(BUILD_FOLDER,'dir')
  rmdir(BUILD_FOLDER, 's');
end
% Create an empty directory for the build
mkdir(BUILD_FOLDER);
disp('Build folder cleaned successfully.');

% Define the configuration object for the C code to generate
cfg = coder.config('dll');
cfg.FilePartitionMethod = 'SingleFile';
% Generate C code only
codegen filter_bode -config cfg -c -d '.\Artifacts' -args {zeros(1,1e005),0,0,0,char(zeros(1,4)),int32(0)}
disp('C code generated successfully.');
% Package the artifacts
load([BUILD_FOLDER '\buildinfo.mat']);
packNGo(buildInfo,'fileName',ZIP_FILE_PATH);
disp('ZIP file created successfully.');
% Generate DLL
setenv('VSCMD_START_DIR','%CD%');
codegen filter_bode_DLL -config cfg -d '.\Artifacts' -o filter_bode_ML -args {zeros(1,1e005),0,0,0,char(zeros(1,4)),int32(0)}
disp('DLL generated successfully.');

% Move the artifacts to Visual Studio SLN project location
copyfile([BUILD_FOLDER '\filter_bode_ML.dll'],VS20XY_PROJECT);
disp('DLL copied successfully to VS20XY.');
copyfile(ZIP_FILE_PATH,VS20XY_PROJECT);
unzip([VS20XY_PROJECT '\' ZIP_FILE],[VS20XY_PROJECT '\MatlabDLL\C_Codegen']);
disp('C files extracted successfully in VS20XY.');
delete([VS20XY_PROJECT '\' ZIP_FILE]);
rmdir(BUILD_FOLDER, 's');
delete('buildInfo.mat');
disp('Build folder removed successfully.');
