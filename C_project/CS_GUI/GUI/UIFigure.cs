using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using LiveCharts;
using LiveCharts.Wpf;
using LiveCharts.Configurations;
using LiveCharts.Defaults;

namespace GUI
{
    public partial class UIFigure : Form
    {
        // Import of the MATLAB algorithm as an external C DLL
        [DllImport("filter_bode.dll")]
        public static extern void filter_bode_DLL(Double[] f, Double f_0, Double q_0, Double g, string f_t, int n_f, Double[] H_mod, Double[] H_arg, ref Int32 error_flag);

        // Number of points in each data vectors
        public const Int32 NB_POINTS = 100000; // This value is fixed in the DLL, so it must be the same
        // 1 point to display every RATIO
        public const Int32 RATIO = 500;
        // Definition of the smallest log power to use to define the frequency vector
        public const Double MIN_PWR = 0;
        // Definition of the biggest log power to use to define the frequency vector
        public const Double MAX_PWR = 9;
        // Definition of the 2 possible errors the filter function can return
        public const Int32 ERROR_TYPE = 1;
        public const Int32 ERROR_ORDER = 2;
        // Definition of the maximal possible unsigned integers for color coding
        const int UINT8_MAX = 255;
        // Definition of charts constants
        public const Int32 FONT_SIZE = 16;
        public const Double PLOT_OPACITY = 0.2;
        public const Double PLOT_STROKE = 2.5;
        // Declare the filter's type property of type string
        public string f_t = "low";
        // Declare the filter's order property of type int
        public int n_f = 1;
        // Declare the filter's cutoff frequency property of type int
        public Double f_0 = 1.0;
        // Declare the filter's quality factor property of type int
        public Double q_0 = 1.0;
        // Declare the filter's linear gain property of type int
        public Double g = 1.0;
        // Declare the frequency vector
        public Double[] f = new Double[NB_POINTS];
        // Declare the argument vector
        public Double[] H_arg = new Double[NB_POINTS];
        // Declare the amplitude vector
        public Double[] H_mod = new Double[NB_POINTS];
        // Initialize the error code
        public Int32 error_flag = 0;
        // Identifier to recognize the first plot done
        public Boolean first_plot = true;
        // Declare the methods to update the values to displays in both charts
        public ChartValues<ObservablePoint> ValuesMod { get; set; }
        public ChartValues<ObservablePoint> ValuesArg { get; set; }

        public UIFigure()
        {
            InitializeComponent();

            // Definition of the logarithmic frequency range
            logspace(MIN_PWR, MAX_PWR, f);

            // Instantiation of the LiveCharts to create the Module and Argument Bode plots
            cartesianChartMod.Series = new SeriesCollection(Mappers.Xy<ObservablePoint>()
                .X(point => Math.Log10(point.X))
                .Y(point => point.Y))
            {};
            cartesianChartArg.Series = new SeriesCollection(Mappers.Xy<ObservablePoint>()
                .X(point => Math.Log10(point.X))
                .Y(point => point.Y))
            {};

            // The values property that stores the values to display in the Bode plots
            ValuesMod = new ChartValues<ObservablePoint>();
            ValuesArg = new ChartValues<ObservablePoint>();

            // Configuration of the X and Y axes of the Bode plots
            cartesianChartMod.AxisX.Add(new LogarithmicAxis
            {
                Title = "f [Hz]",
                FontSize = FONT_SIZE,
                Labels = new[]
                {
                    "10^0", "10^1", "10^2", "10^3", "10^4", "10^5", "10^6", "10^7", "10^8", "10^9"
                },
                LabelFormatter = value => Math.Pow(10, value).ToString("N"),
                Base = 10, MinValue = MIN_PWR, MaxValue = MAX_PWR,
                Separator = new Separator
                {
                    Stroke = System.Windows.Media.Brushes.LightGray
                }
            });
            cartesianChartMod.AxisY.Add(new Axis
            {
                Title = "|H| [dB]",
                FontSize = FONT_SIZE
            });
            cartesianChartArg.AxisX.Add(new LogarithmicAxis
            {
                Title = "f [Hz]",
                FontSize = FONT_SIZE,
                Labels = new[]
                {
                    "10^0", "10^1", "10^2", "10^3", "10^4", "10^5", "10^6", "10^7", "10^8", "10^9"
                },
                LabelFormatter = value => Math.Pow(10, value).ToString("N"),
                Base = 10, MinValue = MIN_PWR, MaxValue = MAX_PWR,
                Separator = new Separator
                {
                    Stroke = System.Windows.Media.Brushes.LightGray
                }
            });
            cartesianChartArg.AxisY.Add(new Axis
            {
                Title = "arg(H) [°]",
                FontSize = FONT_SIZE
            });
        }

        /* Function to generate a frequency vector using a logarithmic scale */
        private void logspace(Double min_pwr, Double max_pwr, Double[] y)
        {
            Double[] b_y = new Double[NB_POINTS];
            Double delta1;
            Double delta2;
            int k;
            b_y[NB_POINTS - 1] = max_pwr;
            b_y[0] = min_pwr;
            if (((min_pwr < 0.0) != (max_pwr < 0.0)) && ((Math.Abs(min_pwr) > 8.9884656743115785E+307) ||
                 (Math.Abs(max_pwr) > 8.9884656743115785E+307)))
            {
                delta1 = min_pwr / (NB_POINTS - 1);
                delta2 = max_pwr / (NB_POINTS - 1);
                for (k = 0; k < (NB_POINTS - 2); k++)
                {
                    b_y[k + 1] = (min_pwr + delta2 * (1.0 + (double)k)) - delta1 * (1.0 + (double)k);
                }
            }
            else
            {
                delta1 = (max_pwr - min_pwr) / (NB_POINTS - 1);
                for (k = 0; k < (NB_POINTS - 2); k++)
                {
                    b_y[k + 1] = min_pwr + (1.0 + (double)k) * delta1;
                }
            }

            for (k = 0; k < NB_POINTS; k++)
            {
                y[k] = Math.Pow(10.0, b_y[k]);
            }
        }

        /* Function to remove any extra backapaces in a string */
        private static string ProcessBackspaces(string source)
        {
            char[] buffer = new char[source.Length];
            int idx = 0;

            foreach (char c in source)
            {
                if (c != '\b')
                {
                    buffer[idx] = c;
                    idx++;
                }
                else if (idx > 0)
                {
                    idx--;
                }
            }

            return new string(buffer, 0, idx);
        }

        private int checkInputParameters(KeyPressEventArgs e, string text, Double minBoundary, Double maxBoundary)
        {
            Double parameterValue;
            int result = 0;

            // Remove extra backspaces
            text = ProcessBackspaces(text);

            if (e.KeyChar >= '0' && e.KeyChar <= '9' || e.KeyChar == '.')
            {
                // Accept the valid input
                e.Handled = false;
                parameterValue = Double.Parse(text);
                if (parameterValue < minBoundary || parameterValue > maxBoundary)
                {
                    // Display a warning message in the interface
                    LogMessageValue.ForeColor = Color.Orange;
                    LogMessageValue.Text = "Please, enter numbers that belong to this range:" + Environment.NewLine + minBoundary + " to " + maxBoundary;
                    result = 1;
                }

            }
            else
            {
                // Reject the incorrect input
                e.Handled = true;
                // Display an error message in the interface
                LogMessageValue.ForeColor = Color.Red;
                LogMessageValue.Text = "Please, enter numbers [0-9 .] and no letters for the correct processing of parameters.";
                result = 2;
            }
            return result;
        }
        private void FilterTypeText(object sender, EventArgs e)
        {
            // Read the filter's type
            string filter_type = TypeDropDown.Text;

            // Get the type of the desired filter
            switch (filter_type)
            {
                case "Lowpass":
                    f_t = "low";
                    break;
                case "Highpass":
                    f_t = "high";
                    break;
                case "Bandpass":
                    f_t = "band";
                    break;
                case "Stopband":
                    f_t = "stop";
                    break;
                default:
                    f_t = "unknown";
                    break;
            }
        }

        private void OrderKnobValue(object Sender)
        {
            // Read the filter's order
            n_f = OrderKnob.Value;
        }

        private void CutoffFrequencyValue_TextChanged(object sender, KeyPressEventArgs e)
        {
            // Check the data type and value range of the cutoff frequency parameter
            if (checkInputParameters(e, CutoffFrequencyValue.Text, 1, 1000000000) != 0)
            {
                // Reset the text field value
                CutoffFrequencyValue.Text = "1";
            }
            
        }

        private void QualityFactorValue_TextChanged(object sender, KeyPressEventArgs e)
        {
            // Check the data type and value range of the quality factor parameter
            if (checkInputParameters(e, QualityFactorValue.Text, 0.1, 10) != 0)
            {
                // Reset the text field value
                QualityFactorValue.Text = "1";
            }
        }

        private void LinearGainValue_TextChanged(object sender, KeyPressEventArgs e)
        {
            // Check the data type and value range of the gain parameter
            if (checkInputParameters(e, LinearGainValue.Text, 0.001, 1000) != 0)
            {
                // Reset the text field value
                LinearGainValue.Text = "1";
            }
        }

        private void CreateBodesButton_Click(object sender, EventArgs e)
        {
            if (CutoffFrequencyValue.Text.Length != 0 && QualityFactorValue.Text.Length != 0 &&
                LinearGainValue.Text.Length != 0)
            {
                // Read text field filter's parameters
                f_0 = Double.Parse(CutoffFrequencyValue.Text);
                q_0 = Double.Parse(QualityFactorValue.Text);
                g = Double.Parse(LinearGainValue.Text);
                // Will compute the filter based on the MATLAB algorithm used for C codegen
                filter_bode_DLL(f, f_0, q_0, g, f_t, n_f, H_mod, H_arg, ref error_flag);

                // If no error occured the visualization will be allowed
                if (error_flag == 0)
                {
                    ViewBodesButton.Enabled = true;
                    StatusLamp.ForeColor = Color.FromArgb(0, UINT8_MAX, 0);
                    LogMessageValue.ForeColor = Color.FromArgb(0, UINT8_MAX, 0);
                    LogMessageValue.Text = "The Bode plots have been computed successfuly.";
                }
                else
                {
                    ViewBodesButton.Enabled = false;
                    StatusLamp.ForeColor = Color.FromArgb(UINT8_MAX, 0, 0);
                    LogMessageValue.ForeColor = Color.FromArgb(UINT8_MAX, 0, 0);
                    // Output the error that avoid computing the filter's data
                    if (error_flag == ERROR_TYPE)
                    {                        
                        LogMessageValue.Text = "This type of filter is not supported.";
                    }
                    else if (error_flag == ERROR_ORDER)
                    {
                        LogMessageValue.Text = "This order value is not supported for such filters" + Environment.NewLine + "It must be an even value.";
                    }
                    else
                    {
                        LogMessageValue.Text = "An unexpected error occured.";
                    }
                }
            }
            else
            {
                StatusLamp.ForeColor = Color.FromArgb(UINT8_MAX, 0, 0);
                LogMessageValue.ForeColor = Color.FromArgb(UINT8_MAX, 0, 0);
                LogMessageValue.Text = "Do not let empty parameters fields." + Environment.NewLine +
                                       "As a result, the text fields are reset." + Environment.NewLine +
                                       "Please, enter numbers [0-9 .]";
                // Reset all text field value
                CutoffFrequencyValue.Text = "1";
                QualityFactorValue.Text = "1";
                LinearGainValue.Text = "1";
                ViewBodesButton.Enabled = false;
            }
        }

        private void ViewBodesButton_Click(object sender, EventArgs e)
        {
            // If the current plot is the first one there is no need to clear the values series
            if (first_plot == false)
            {
                cartesianChartMod.Series[0].Values.Clear();
                cartesianChartArg.Series[0].Values.Clear();
            }
            // Addi new data points to the existing series
            cartesianChartMod.Series.Add(new LineSeries
            {
                Values = ValuesMod,
                Stroke = System.Windows.Media.Brushes.Blue,
                StrokeThickness = PLOT_STROKE,
                Fill = new System.Windows.Media.SolidColorBrush
                {
                    Color = System.Windows.Media.Color.FromRgb(128, 128, 255),
                    Opacity = PLOT_OPACITY
                },
                PointGeometry = null
            });
            cartesianChartArg.Series.Add(new LineSeries
            {
                Values = ValuesArg,
                Stroke = System.Windows.Media.Brushes.Blue,
                StrokeThickness = PLOT_STROKE,
                Fill = new System.Windows.Media.SolidColorBrush
                {
                    Color = System.Windows.Media.Color.FromRgb(128, 128, 255),
                    Opacity = PLOT_OPACITY
                },
                PointGeometry = null
            });

            // Display the results in the LiveCharts
            int j = 0;
            for (int i = 0; i < NB_POINTS/RATIO; i++)
            {
                cartesianChartMod.Series[0].Values.Insert(j, new ObservablePoint(f[i*RATIO], H_mod[i*RATIO]));
                cartesianChartArg.Series[0].Values.Insert(j, new ObservablePoint(f[i*RATIO], H_arg[i*RATIO]));
                j++;
            }
            first_plot = false;
            // Clear the Status lamp
            StatusLamp.ForeColor = Color.FromArgb(227, 227, 227);
            ;
        }
    }
}
