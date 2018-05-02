%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Parse_files
% Automatically modify the generated C and header files.
%
% Copyright 2018 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Parsing of the main.h file
clear variables; close all; clc;
disp('Starting the parsing of the header file...');
% Constants declarations
% Text files containing HMM definitions
FILE_READ  = '.\main_original.h';
FILE_WRITE = '.\main.h';
% Key words to recognize in the generated files
KEY_TAGS   = {'__cplusplus' 'main(void)'...
               'main_initialize' 'main_terminate' 'File trailer'};
% Text to add at the end of the file
LINE_FEED  = newline;
DIRECTIVES = {'/* Constants definition */'
              '#define NB_SAMPLES 100000'
              '#define FREQ_STEP  10'
              '#define Y_AXS_STEP 20'
              '#define ERROR_TYPE  1'
              '#define ERROR_ORDER 2'
              '/* Macros definition */'
              '#define min_data(a,b) (a<=b?a:b)'
              '#define max_data(a,b) (a>=b?a:b)'
             };

% Backup of the original generated file
copyfile(FILE_WRITE,FILE_READ);

% Open text files and get their handler
file_read_ID  = fopen(FILE_READ,'r');
file_write_ID = fopen(FILE_WRITE,'wt');

% Read all lines of the text file separately
while(1)
  % Read the current line
  line_data = fgets(file_read_ID);
  % Look for any tag in the current line
  tags_present = cellfun(@(s) contains(line_data,s),KEY_TAGS);
  if any(tags_present)
    % Get the index of the identified tag
    tag_idx = find(tags_present);
    % Retrieve needed data based on tags identification
    switch (tag_idx)
      case {1}
        % Increase the line index to avoid copying unwanted text lines
        for i=1:5
          line_data = fgets(file_read_ID);
        end
      case {2}
        fprintf(file_write_ID,'%s',line_data(1:end-1));
        % Write pre-compilation directives needed for the C code
        for i=1:length(DIRECTIVES)
          fprintf(file_write_ID,'%s',[LINE_FEED DIRECTIVES{i,1}]);
        end
        fprintf(file_write_ID,'%s',LINE_FEED);
      case {3,4}
        line_data = fgets(file_read_ID);
        fprintf(file_write_ID,'%s','');
      case {5}
        % Copy the trailer comment
        fprintf(file_write_ID,'%s',line_data(1:end-1));
        line_data = fgets(file_read_ID);
        fprintf(file_write_ID,'%s',line_data(1:end-1));
      otherwise
        disp('Tagging error in file');
    end
  else
    fprintf(file_write_ID,'%s',line_data(1:end-1));
  end
  
  % Leave the loop if the end of file has been reached
  if (feof(file_read_ID))
    break;
  end
end
% Close text files
fclose(file_read_ID);
fclose(file_write_ID);
disp('Parsing of the header file done.');

%% Parsing of the main.c file
clear variables; close all; clc;
disp('Starting the parsing of the C file...');
% Constants declarations
% Text files containing HMM definitions
FILE_READ  = '.\main_original.c';
FILE_WRITE = '.\main.c';
% Key words to recognize in the generated files
KEY_TAGS   = {'angle' '100000U' '100000'  '99999.0' '99998.0' '99999' '99998'};
% Text to add at the beginning of the file
LINE_FEED  = newline;
INCLUDES   = {'#include <float.h>'
              '#include <math.h>'
              '#include "dislin.h" /* Added of the graphical library */'};

% Text to add at the end of the file
file_ID = fopen('.\min_and_max.txt','r');
k = 0;
while(1)
  k = k+1;
  min_and_max{k,1} = fgets(file_ID); %#ok<SAGROW>
  if (feof(file_ID))
    break;
  end
end
file_ID = fopen('.\main.txt','r');
k = 0;
while(1)
  k = k+1;
  main{k,1} = fgets(file_ID); %#ok<SAGROW>
  if (feof(file_ID))
    break;
  end
end

% Backup of the original generated file
copyfile(FILE_WRITE,FILE_READ);
% Open text files and get their handler
file_read_ID  = fopen(FILE_READ,'r');
file_write_ID = fopen(FILE_WRITE,'wt');

% Read all lines of the text file separately
counter = 0;
do_not_copy = 0;
while(1)
  % Read the current line
  line_data = fgets(file_read_ID);
  % Look for any tag in the current line
  tags_present = cellfun(@(s) contains(line_data,s),KEY_TAGS);
  if any(tags_present)
    % Correct the name of the angle function that already exists in math.h
    line_data = regexprep(line_data,KEY_TAGS(1),'angle_tf');
    % Add of the pre-defined directives for constant values
    line_data = regexprep(line_data,KEY_TAGS(2),'NB_SAMPLES');
    line_data = regexprep(line_data,KEY_TAGS(3),'NB_SAMPLES');
    line_data = regexprep(line_data,KEY_TAGS(4),'(NB_SAMPLES-1.0)');
    line_data = regexprep(line_data,KEY_TAGS(5),'(NB_SAMPLES-2.0)');
    line_data = regexprep(line_data,KEY_TAGS(6),'NB_SAMPLES-1');
    line_data = regexprep(line_data,KEY_TAGS(end),'NB_SAMPLES-2');
  elseif regexp(line_data,'"main.h"')
    % Write includes needed for the main C file
    for i=1:length(INCLUDES)
      fprintf(file_write_ID,'%s',[INCLUDES{i,1} LINE_FEED]);
    end
  elseif regexp(line_data,'Function: main\(\)')
    % Added of the min_and_max function
    for i=1:length(min_and_max)
      line_to_write = min_and_max{i,1};
      fprintf(file_write_ID,'%s',line_to_write(1:end-1));
    end
  elseif regexp(line_data,'int main\(void\)')
    % Added of the main function with the graphical interface
    for i=1:length(main)
      line_to_write = main{i,1};
      fprintf(file_write_ID,'%s',line_to_write(1:end-1));
    end
    do_not_copy = 1;
  elseif regexp(line_data,'* Arguments    : void')
    if (counter > 0)
      for i=1:17
        line_data = fgets(file_read_ID);
        fprintf(file_write_ID,'%s','');
      end
    end
    counter = counter+1;
  end
  
  if (do_not_copy == 0)
    fprintf(file_write_ID,'%s',line_data(1:end-1));
  end
  
  % Leave the loop if the end of file has been reached
  if feof(file_read_ID)
    break;
  end
end

% Close text files
fclose(file_read_ID);
fclose(file_write_ID);
disp('Parsing of the C file done.');
