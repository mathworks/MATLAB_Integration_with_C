function [H_mod,H_arg,err_f] = filter_bode(f,f_0,q_0,g,f_type,f_order)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Function: filter_bode()
% Goal    : Calculates the frequency response of a given filter's type
%
% IN      : - f      : vector of frequency values
%           - f_0    : cutoff frequency of the filter
%           - g      : gain of the filter
%           - q_0    : quality factor of the filter (for 2nd order sections)
%           - f_type : filter's type :'low', 'high', 'band' and 'stop'
%           - f_order: filter's order
% IN/OUT  : -
% OUT     : - H_mod : module of the transfer function in [dB]
%           - H_arg : argument of the transfer function in [°]
%           - err_f : returns execution error related to input parameters
%
% Copyright 2018 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  %#codegen
  % Constants
  TYPE        = [['low',0,0];['high',0];['band',0];['stop',0]];
  NB_FILTERS  = int32(4);
  T_32        = int32(1:NB_FILTERS); % Integer representation of filter's type
  ERROR_TYPE  = int32(1);
  ERROR_ORDER = int32(2);

  % Initializations
  err_f       = int32(0);
  filter_T_32 = int32(0);
  negate_bool = int32(0); %#ok<NASGU>
  n           = int32(0);
  nb_samples  = int32(length(f));
  H     = complex(ones(1,nb_samples),0);
  H_mod = zeros(1,nb_samples);
  H_arg = zeros(1,nb_samples);
  % Pulsation's vectors
  w   = 2*pi*f;
  w_0 = 2*pi*f_0;

  % Set switches to work with integer
  for i=int32(1):1:NB_FILTERS
    negate_bool = coder.ceval('strcmp',f_type,TYPE(i,:));
    if (negate_bool == 0)
      filter_T_32 = i;
    end
  end

  % Test the order of the filter against the filter type
  if (filter_T_32 > T_32(2))
    % For band-pass and stop-band filters odd orders are not feasible
    if mod(f_order,2)
      err_f = ERROR_ORDER;
      return
    end
  end

  % Bode diagram calculation
  while(1)
    if (f_order > 1)
      n_cell_order = 2;
    elseif (f_order == 1)
      n_cell_order = 1;
    else
      % All filter's cells have been calculated
      break;
    end
    f_order = f_order - n_cell_order;
    n = n+1;
    
    % Calculate each filter's cell separately
    if (n_cell_order == 1) % 1st order filter
      % Initialization of the transfer function with the common divider
      H = H.*(1./(1+1i*(w/w_0)));
      switch (filter_T_32)
        case T_32(1)
          % Low-pass filter
          H = 1.*H;
        case T_32(2)
          % High-pass filter
          H = 1i*(w/w_0).*H;
        otherwise
          % Type of filter not supported
          err_f = ERROR_TYPE;
          return
      end
    else % 2nd order filter
      % Initialisation of the transfer function with the common divider
      H = H.*(1./(1+(1/q_0)*1i*(w/w_0)+(1i*(w/w_0)).^2));
      switch (filter_T_32)
        case T_32(1)
          % Low-pass filter
          H = 1.*H;
        case T_32(2)
          % High-pass filter
          H = ((1i*(w/w_0)).^2).*H;
        case T_32(3)
          % Band-pass filter
          H = ((1i/(2*q_0*w_0))*w).*H;
        case T_32(4)
          % Band-stop filter
          H = (1+(1i*(w/w_0)).^2).*H;
        otherwise
          % Type of filter not supported
          err_f = ERROR_TYPE;
          return
      end
    end
  end
  H = g*H; % Apply the filter gain only once

  % Retrieves module and argument of the transfer function H
  if (err_f == 0)
    H_mod = 20*log10(abs(H)); % [dB]
    H_arg = angle(H)*180/pi;  % [°]
    return
  end
end
