function plot_filter(f,H_mod,H_arg,f_type,f_order,fig_id)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Function: plot_filter()
% Goal    : Plots the frequency response of a given filter
%
% IN      : - f       : vector of frequency values
%           - H_mod   : module of the transfer function in [dB]
%           - H_arg   : argument of the transfer function in [°]
%           - f_type  : filter's type :'low', 'high', 'band' and 'stop'
%           - f_order : filter's order
%           - fig_id  : current figure number
% IN/OUT  : -
% OUT     : -
%
% Copyright 2024 The MathWorks, Inc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Functions that are not translated into C code
  coder.extrinsic('num2str');

  % Definition of the logarithmic frequency range
  power_f_min = 0; power_f_max = 9;
  nb_decades  = (power_f_max-power_f_min)+1;
  % Definition of the phase range
  min_phase = -180; max_phase = 180; phase_step = 10;
  % Definition of the amplitude range
  min_amp = -100; max_amp = 100; amp_step = 10;
  % Calculation of the optimal plot ranges
  min_H_mod = max(min(H_mod),min_amp);
  max_H_mod = min(max(H_mod),max_amp);
  min_H_arg = max(min(H_arg),min_phase);
  max_H_arg = min(max(H_arg),max_phase);
  % Definition of graphical parameters
  police = 20; width  = 1.5;

  if (strcmp(f_type,'stop'))
    t_word = 'band';
  else
    t_word = 'pass';
  end
  % Display of results
  h_fig = figure(fig_id);
  set(h_fig,'Units','Normalized','OuterPosition',[0 0 1 1]);
  % Bode of amplitude
  subplot (1,2,1);
  semilogx(f,H_mod,'LineWidth',width,'Color','r'); hold on;
  % Information
  title (['Module of the ',f_type,'-',t_word,' filter of order ',...
          num2str(f_order)],'FontName','Times','FontSize',police);
  xlabel('f [Hz]'  ,'FontName','Times','FontSize',police);
  ylabel('|H| [dB]','FontName','Times','FontSize',police);
  axis  ([min(f) 1e009, min_H_mod-1 max_H_mod+1]);
  set   (findobj(gcf,'Type','text'),'FontName','Times','FontSize',police);
  set   (gca,'FontName','Times','FontSize',police);
  set   (gca,'xtick',logspace(power_f_min,power_f_max,nb_decades));
  set   (gca,'ytick',(min_amp:amp_step:max_amp));
  grid   on;
  set   (gca,'XMinorGrid','off');
  % Bode of phase
  subplot (1,2,2);
  semilogx(f,H_arg,'LineWidth',width,'Color','r'); hold on;
  % Information
  title (['Phase of the ',f_type,'-',t_word,' filter of order ',...
          num2str(f_order)],'FontName','Times','FontSize',police);
  xlabel('f [Hz]'    ,'FontName','Times','FontSize',police);
  ylabel('arg(H) [°]','FontName','Times','FontSize',police);
  axis  ([min(f) 1e009, min_H_arg-1 max_H_arg+1]);
  set   (findobj(gcf,'Type','text'),'FontName','Times','FontSize',police);
  set   (gca,'FontName','Times','FontSize',police);
  set   (gca,'xtick',logspace(power_f_min,power_f_max,nb_decades));
  set   (gca,'ytick',(min_phase:phase_step:max_phase));
  grid   on;
  set   (gca,'XMinorGrid','off');
end
