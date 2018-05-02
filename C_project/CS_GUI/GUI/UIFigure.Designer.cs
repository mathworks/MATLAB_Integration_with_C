namespace GUI
{
    partial class UIFigure
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
      System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(UIFigure));
      this.TabGroup = new System.Windows.Forms.TabControl();
      this.Tab_inputs = new System.Windows.Forms.TabPage();
      this.tableLayoutInputs = new System.Windows.Forms.TableLayoutPanel();
      this.tableLayoutLeft = new System.Windows.Forms.TableLayoutPanel();
      this.tableLayoutFiltersData = new System.Windows.Forms.TableLayoutPanel();
      this.ViewBodesButton = new System.Windows.Forms.Button();
      this.tableLayoutStatus = new System.Windows.Forms.TableLayoutPanel();
      this.FilterStatus = new System.Windows.Forms.Label();
      this.StatusLamp = new Lamp.LampControl();
      this.CreateBodesButton = new System.Windows.Forms.Button();
      this.tableLayoutLeftTop = new System.Windows.Forms.TableLayoutPanel();
      this.ComputeFiltersDataLabel = new System.Windows.Forms.Label();
      this.tableLayoutKnob = new System.Windows.Forms.TableLayoutPanel();
      this.OrderKnob = new KnobControl.KnobControl();
      this.tableLayoutOrder = new System.Windows.Forms.TableLayoutPanel();
      this.FilterOrder = new System.Windows.Forms.Label();
      this.tableLayoutType = new System.Windows.Forms.TableLayoutPanel();
      this.TypeDropDown = new System.Windows.Forms.ComboBox();
      this.FilterType = new System.Windows.Forms.Label();
      this.FiltersparametersLabel = new System.Windows.Forms.Label();
      this.tableLayoutInputsRight = new System.Windows.Forms.TableLayoutPanel();
      this.tableLayoutRightTop = new System.Windows.Forms.TableLayoutPanel();
      this.CutoffFrequencyValue = new System.Windows.Forms.TextBox();
      this.QualityFactorValue = new System.Windows.Forms.TextBox();
      this.LinearGainValue = new System.Windows.Forms.TextBox();
      this.tableLayoutRightBottom = new System.Windows.Forms.TableLayoutPanel();
      this.LogMessageValue = new System.Windows.Forms.TextBox();
      this.tableLayoutMiddle = new System.Windows.Forms.TableLayoutPanel();
      this.tableLayoutMiddleTop = new System.Windows.Forms.TableLayoutPanel();
      this.CutoffFrequencyLabel = new System.Windows.Forms.Label();
      this.QualityFactorLabel = new System.Windows.Forms.Label();
      this.LinearGainLabel = new System.Windows.Forms.Label();
      this.tableLayoutMiddleBottom = new System.Windows.Forms.TableLayoutPanel();
      this.LogMessageLabel = new System.Windows.Forms.Label();
      this.Tab_outputs = new System.Windows.Forms.TabPage();
      this.tableLayoutOutputs = new System.Windows.Forms.TableLayoutPanel();
      this.cartesianChartMod = new LiveCharts.WinForms.CartesianChart();
      this.cartesianChartArg = new LiveCharts.WinForms.CartesianChart();
      this.TitelLabel = new System.Windows.Forms.Label();
      this.TabGroup.SuspendLayout();
      this.Tab_inputs.SuspendLayout();
      this.tableLayoutInputs.SuspendLayout();
      this.tableLayoutLeft.SuspendLayout();
      this.tableLayoutFiltersData.SuspendLayout();
      this.tableLayoutStatus.SuspendLayout();
      this.tableLayoutLeftTop.SuspendLayout();
      this.tableLayoutKnob.SuspendLayout();
      this.tableLayoutOrder.SuspendLayout();
      this.tableLayoutType.SuspendLayout();
      this.tableLayoutInputsRight.SuspendLayout();
      this.tableLayoutRightTop.SuspendLayout();
      this.tableLayoutRightBottom.SuspendLayout();
      this.tableLayoutMiddle.SuspendLayout();
      this.tableLayoutMiddleTop.SuspendLayout();
      this.tableLayoutMiddleBottom.SuspendLayout();
      this.Tab_outputs.SuspendLayout();
      this.tableLayoutOutputs.SuspendLayout();
      this.SuspendLayout();
      // 
      // TabGroup
      // 
      this.TabGroup.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
      this.TabGroup.Controls.Add(this.Tab_inputs);
      this.TabGroup.Controls.Add(this.Tab_outputs);
      this.TabGroup.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.TabGroup.Location = new System.Drawing.Point(0, 36);
      this.TabGroup.Name = "TabGroup";
      this.TabGroup.SelectedIndex = 0;
      this.TabGroup.Size = new System.Drawing.Size(640, 446);
      this.TabGroup.TabIndex = 0;
      // 
      // Tab_inputs
      // 
      this.Tab_inputs.BackColor = System.Drawing.Color.WhiteSmoke;
      this.Tab_inputs.Controls.Add(this.tableLayoutInputs);
      this.Tab_inputs.Location = new System.Drawing.Point(4, 24);
      this.Tab_inputs.Margin = new System.Windows.Forms.Padding(0);
      this.Tab_inputs.Name = "Tab_inputs";
      this.Tab_inputs.Padding = new System.Windows.Forms.Padding(3);
      this.Tab_inputs.Size = new System.Drawing.Size(632, 418);
      this.Tab_inputs.TabIndex = 0;
      this.Tab_inputs.Text = "Inputs";
      // 
      // tableLayoutInputs
      // 
      this.tableLayoutInputs.ColumnCount = 3;
      this.tableLayoutInputs.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 30F));
      this.tableLayoutInputs.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
      this.tableLayoutInputs.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
      this.tableLayoutInputs.Controls.Add(this.tableLayoutLeft, 0, 0);
      this.tableLayoutInputs.Controls.Add(this.tableLayoutInputsRight, 2, 0);
      this.tableLayoutInputs.Controls.Add(this.tableLayoutMiddle, 1, 0);
      this.tableLayoutInputs.Dock = System.Windows.Forms.DockStyle.Fill;
      this.tableLayoutInputs.Location = new System.Drawing.Point(3, 3);
      this.tableLayoutInputs.Margin = new System.Windows.Forms.Padding(0);
      this.tableLayoutInputs.Name = "tableLayoutInputs";
      this.tableLayoutInputs.RowCount = 1;
      this.tableLayoutInputs.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
      this.tableLayoutInputs.Size = new System.Drawing.Size(626, 412);
      this.tableLayoutInputs.TabIndex = 17;
      // 
      // tableLayoutLeft
      // 
      this.tableLayoutLeft.ColumnCount = 1;
      this.tableLayoutLeft.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
      this.tableLayoutLeft.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 20F));
      this.tableLayoutLeft.Controls.Add(this.tableLayoutFiltersData, 0, 1);
      this.tableLayoutLeft.Controls.Add(this.tableLayoutLeftTop, 0, 0);
      this.tableLayoutLeft.Dock = System.Windows.Forms.DockStyle.Fill;
      this.tableLayoutLeft.Location = new System.Drawing.Point(0, 0);
      this.tableLayoutLeft.Margin = new System.Windows.Forms.Padding(0);
      this.tableLayoutLeft.Name = "tableLayoutLeft";
      this.tableLayoutLeft.RowCount = 2;
      this.tableLayoutLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
      this.tableLayoutLeft.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
      this.tableLayoutLeft.Size = new System.Drawing.Size(187, 412);
      this.tableLayoutLeft.TabIndex = 1;
      // 
      // tableLayoutFiltersData
      // 
      this.tableLayoutFiltersData.ColumnCount = 3;
      this.tableLayoutFiltersData.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 30F));
      this.tableLayoutFiltersData.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 45F));
      this.tableLayoutFiltersData.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
      this.tableLayoutFiltersData.Controls.Add(this.ViewBodesButton, 1, 3);
      this.tableLayoutFiltersData.Controls.Add(this.tableLayoutStatus, 1, 2);
      this.tableLayoutFiltersData.Controls.Add(this.CreateBodesButton, 1, 1);
      this.tableLayoutFiltersData.Dock = System.Windows.Forms.DockStyle.Fill;
      this.tableLayoutFiltersData.Location = new System.Drawing.Point(0, 206);
      this.tableLayoutFiltersData.Margin = new System.Windows.Forms.Padding(0);
      this.tableLayoutFiltersData.Name = "tableLayoutFiltersData";
      this.tableLayoutFiltersData.RowCount = 5;
      this.tableLayoutFiltersData.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 6F));
      this.tableLayoutFiltersData.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11F));
      this.tableLayoutFiltersData.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 15F));
      this.tableLayoutFiltersData.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11F));
      this.tableLayoutFiltersData.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 57F));
      this.tableLayoutFiltersData.Size = new System.Drawing.Size(187, 206);
      this.tableLayoutFiltersData.TabIndex = 0;
      // 
      // ViewBodesButton
      // 
      this.ViewBodesButton.BackColor = System.Drawing.Color.White;
      this.ViewBodesButton.Cursor = System.Windows.Forms.Cursors.Hand;
      this.ViewBodesButton.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.ViewBodesButton.Enabled = false;
      this.ViewBodesButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
      this.ViewBodesButton.Font = new System.Drawing.Font("Arial", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.ViewBodesButton.Location = new System.Drawing.Point(56, 64);
      this.ViewBodesButton.Margin = new System.Windows.Forms.Padding(0);
      this.ViewBodesButton.Name = "ViewBodesButton";
      this.ViewBodesButton.Size = new System.Drawing.Size(84, 22);
      this.ViewBodesButton.TabIndex = 7;
      this.ViewBodesButton.Text = "View Bodes";
      this.ViewBodesButton.UseVisualStyleBackColor = false;
      this.ViewBodesButton.Click += new System.EventHandler(this.ViewBodesButton_Click);
      // 
      // tableLayoutStatus
      // 
      this.tableLayoutStatus.ColumnCount = 3;
      this.tableLayoutStatus.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 55F));
      this.tableLayoutStatus.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 5F));
      this.tableLayoutStatus.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 40F));
      this.tableLayoutStatus.Controls.Add(this.FilterStatus, 0, 0);
      this.tableLayoutStatus.Controls.Add(this.StatusLamp, 2, 0);
      this.tableLayoutStatus.Dock = System.Windows.Forms.DockStyle.Fill;
      this.tableLayoutStatus.Location = new System.Drawing.Point(56, 34);
      this.tableLayoutStatus.Margin = new System.Windows.Forms.Padding(0);
      this.tableLayoutStatus.Name = "tableLayoutStatus";
      this.tableLayoutStatus.RowCount = 1;
      this.tableLayoutStatus.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
      this.tableLayoutStatus.Size = new System.Drawing.Size(84, 30);
      this.tableLayoutStatus.TabIndex = 10;
      // 
      // FilterStatus
      // 
      this.FilterStatus.AutoSize = true;
      this.FilterStatus.Dock = System.Windows.Forms.DockStyle.Right;
      this.FilterStatus.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.FilterStatus.Location = new System.Drawing.Point(4, 0);
      this.FilterStatus.Margin = new System.Windows.Forms.Padding(0);
      this.FilterStatus.Name = "FilterStatus";
      this.FilterStatus.Size = new System.Drawing.Size(42, 30);
      this.FilterStatus.TabIndex = 8;
      this.FilterStatus.Text = "Status";
      this.FilterStatus.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
      // 
      // StatusLamp
      // 
      this.StatusLamp.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
      this.StatusLamp.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
      this.StatusLamp.ForeColor = System.Drawing.SystemColors.ControlLight;
      this.StatusLamp.Location = new System.Drawing.Point(50, 0);
      this.StatusLamp.Margin = new System.Windows.Forms.Padding(0);
      this.StatusLamp.Name = "StatusLamp";
      this.StatusLamp.Size = new System.Drawing.Size(34, 30);
      this.StatusLamp.TabIndex = 9;
      // 
      // CreateBodesButton
      // 
      this.CreateBodesButton.BackColor = System.Drawing.Color.White;
      this.CreateBodesButton.Cursor = System.Windows.Forms.Cursors.Hand;
      this.CreateBodesButton.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.CreateBodesButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
      this.CreateBodesButton.Font = new System.Drawing.Font("Arial", 8.25F);
      this.CreateBodesButton.Location = new System.Drawing.Point(56, 12);
      this.CreateBodesButton.Margin = new System.Windows.Forms.Padding(0);
      this.CreateBodesButton.Name = "CreateBodesButton";
      this.CreateBodesButton.RightToLeft = System.Windows.Forms.RightToLeft.No;
      this.CreateBodesButton.Size = new System.Drawing.Size(84, 22);
      this.CreateBodesButton.TabIndex = 6;
      this.CreateBodesButton.Text = "Create Bodes";
      this.CreateBodesButton.UseVisualStyleBackColor = false;
      this.CreateBodesButton.Click += new System.EventHandler(this.CreateBodesButton_Click);
      // 
      // tableLayoutLeftTop
      // 
      this.tableLayoutLeftTop.ColumnCount = 1;
      this.tableLayoutLeftTop.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
      this.tableLayoutLeftTop.Controls.Add(this.ComputeFiltersDataLabel, 0, 4);
      this.tableLayoutLeftTop.Controls.Add(this.tableLayoutKnob, 0, 3);
      this.tableLayoutLeftTop.Controls.Add(this.tableLayoutType, 0, 1);
      this.tableLayoutLeftTop.Controls.Add(this.FiltersparametersLabel, 0, 0);
      this.tableLayoutLeftTop.Dock = System.Windows.Forms.DockStyle.Fill;
      this.tableLayoutLeftTop.Location = new System.Drawing.Point(0, 0);
      this.tableLayoutLeftTop.Margin = new System.Windows.Forms.Padding(0);
      this.tableLayoutLeftTop.Name = "tableLayoutLeftTop";
      this.tableLayoutLeftTop.RowCount = 5;
      this.tableLayoutLeftTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 14.5F));
      this.tableLayoutLeftTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 14.5F));
      this.tableLayoutLeftTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 5.5F));
      this.tableLayoutLeftTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 52.5F));
      this.tableLayoutLeftTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 13F));
      this.tableLayoutLeftTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
      this.tableLayoutLeftTop.Size = new System.Drawing.Size(187, 206);
      this.tableLayoutLeftTop.TabIndex = 1;
      // 
      // ComputeFiltersDataLabel
      // 
      this.ComputeFiltersDataLabel.AutoSize = true;
      this.ComputeFiltersDataLabel.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.ComputeFiltersDataLabel.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.ComputeFiltersDataLabel.Location = new System.Drawing.Point(0, 187);
      this.ComputeFiltersDataLabel.Margin = new System.Windows.Forms.Padding(0);
      this.ComputeFiltersDataLabel.Name = "ComputeFiltersDataLabel";
      this.ComputeFiltersDataLabel.Size = new System.Drawing.Size(187, 19);
      this.ComputeFiltersDataLabel.TabIndex = 5;
      this.ComputeFiltersDataLabel.Text = "Compute Filter\'s Data";
      // 
      // tableLayoutKnob
      // 
      this.tableLayoutKnob.ColumnCount = 3;
      this.tableLayoutKnob.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
      this.tableLayoutKnob.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 55F));
      this.tableLayoutKnob.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
      this.tableLayoutKnob.Controls.Add(this.OrderKnob, 1, 0);
      this.tableLayoutKnob.Controls.Add(this.tableLayoutOrder, 0, 0);
      this.tableLayoutKnob.Location = new System.Drawing.Point(0, 69);
      this.tableLayoutKnob.Margin = new System.Windows.Forms.Padding(0);
      this.tableLayoutKnob.Name = "tableLayoutKnob";
      this.tableLayoutKnob.RowCount = 1;
      this.tableLayoutKnob.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
      this.tableLayoutKnob.Size = new System.Drawing.Size(187, 100);
      this.tableLayoutKnob.TabIndex = 6;
      // 
      // OrderKnob
      // 
      this.OrderKnob.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
      this.OrderKnob.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
      this.OrderKnob.Cursor = System.Windows.Forms.Cursors.Hand;
      this.OrderKnob.EndAngle = 405F;
      this.OrderKnob.ImeMode = System.Windows.Forms.ImeMode.On;
      this.OrderKnob.knobBackColor = System.Drawing.Color.White;
      this.OrderKnob.KnobPointerStyle = KnobControl.KnobControl.knobPointerStyle.line;
      this.OrderKnob.LargeChange = 5;
      this.OrderKnob.Location = new System.Drawing.Point(46, 0);
      this.OrderKnob.Margin = new System.Windows.Forms.Padding(0);
      this.OrderKnob.Maximum = 10;
      this.OrderKnob.Minimum = 1;
      this.OrderKnob.Name = "OrderKnob";
      this.OrderKnob.PointerColor = System.Drawing.Color.Red;
      this.OrderKnob.ScaleColor = System.Drawing.Color.Black;
      this.OrderKnob.ScaleDivisions = 10;
      this.OrderKnob.ScaleSubDivisions = 0;
      this.OrderKnob.ShowLargeScale = true;
      this.OrderKnob.ShowSmallScale = false;
      this.OrderKnob.Size = new System.Drawing.Size(102, 102);
      this.OrderKnob.SmallChange = 1;
      this.OrderKnob.StartAngle = 135F;
      this.OrderKnob.TabIndex = 3;
      this.OrderKnob.Value = 1;
      this.OrderKnob.ValueChanged += new KnobControl.ValueChangedEventHandler(this.OrderKnobValue);
      // 
      // tableLayoutOrder
      // 
      this.tableLayoutOrder.ColumnCount = 1;
      this.tableLayoutOrder.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
      this.tableLayoutOrder.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 20F));
      this.tableLayoutOrder.Controls.Add(this.FilterOrder, 0, 1);
      this.tableLayoutOrder.Location = new System.Drawing.Point(0, 0);
      this.tableLayoutOrder.Margin = new System.Windows.Forms.Padding(0);
      this.tableLayoutOrder.Name = "tableLayoutOrder";
      this.tableLayoutOrder.RowCount = 3;
      this.tableLayoutOrder.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 33.3F));
      this.tableLayoutOrder.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 33.4F));
      this.tableLayoutOrder.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 33.3F));
      this.tableLayoutOrder.Size = new System.Drawing.Size(46, 100);
      this.tableLayoutOrder.TabIndex = 4;
      // 
      // FilterOrder
      // 
      this.FilterOrder.AutoSize = true;
      this.FilterOrder.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.FilterOrder.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.FilterOrder.Location = new System.Drawing.Point(0, 51);
      this.FilterOrder.Margin = new System.Windows.Forms.Padding(0);
      this.FilterOrder.Name = "FilterOrder";
      this.FilterOrder.Size = new System.Drawing.Size(46, 15);
      this.FilterOrder.TabIndex = 4;
      this.FilterOrder.Text = "Order:";
      // 
      // tableLayoutType
      // 
      this.tableLayoutType.ColumnCount = 3;
      this.tableLayoutType.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
      this.tableLayoutType.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 55F));
      this.tableLayoutType.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
      this.tableLayoutType.Controls.Add(this.TypeDropDown, 1, 0);
      this.tableLayoutType.Controls.Add(this.FilterType, 0, 0);
      this.tableLayoutType.Location = new System.Drawing.Point(0, 29);
      this.tableLayoutType.Margin = new System.Windows.Forms.Padding(0);
      this.tableLayoutType.Name = "tableLayoutType";
      this.tableLayoutType.RowCount = 1;
      this.tableLayoutType.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
      this.tableLayoutType.Size = new System.Drawing.Size(187, 29);
      this.tableLayoutType.TabIndex = 7;
      // 
      // TypeDropDown
      // 
      this.TypeDropDown.AllowDrop = true;
      this.TypeDropDown.DisplayMember = "1";
      this.TypeDropDown.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.TypeDropDown.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
      this.TypeDropDown.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.TypeDropDown.FormattingEnabled = true;
      this.TypeDropDown.Items.AddRange(new object[] {
            "Lowpass",
            "Highpass",
            "Bandpass",
            "Stopband"});
      this.TypeDropDown.Location = new System.Drawing.Point(49, 3);
      this.TypeDropDown.MaxDropDownItems = 4;
      this.TypeDropDown.Name = "TypeDropDown";
      this.TypeDropDown.Size = new System.Drawing.Size(96, 23);
      this.TypeDropDown.TabIndex = 1;
      this.TypeDropDown.Text = "Lowpass";
      this.TypeDropDown.SelectedIndexChanged += new System.EventHandler(this.FilterTypeText);
      // 
      // FilterType
      // 
      this.FilterType.AutoSize = true;
      this.FilterType.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.FilterType.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.FilterType.Location = new System.Drawing.Point(3, 14);
      this.FilterType.Name = "FilterType";
      this.FilterType.Size = new System.Drawing.Size(40, 15);
      this.FilterType.TabIndex = 2;
      this.FilterType.Text = "Type:";
      // 
      // FiltersparametersLabel
      // 
      this.FiltersparametersLabel.AutoSize = true;
      this.FiltersparametersLabel.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.FiltersparametersLabel.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.FiltersparametersLabel.Location = new System.Drawing.Point(3, 10);
      this.FiltersparametersLabel.Name = "FiltersparametersLabel";
      this.FiltersparametersLabel.Size = new System.Drawing.Size(181, 19);
      this.FiltersparametersLabel.TabIndex = 0;
      this.FiltersparametersLabel.Text = "Filter\'s parameters";
      // 
      // tableLayoutInputsRight
      // 
      this.tableLayoutInputsRight.ColumnCount = 1;
      this.tableLayoutInputsRight.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
      this.tableLayoutInputsRight.Controls.Add(this.tableLayoutRightTop, 0, 0);
      this.tableLayoutInputsRight.Controls.Add(this.tableLayoutRightBottom, 0, 1);
      this.tableLayoutInputsRight.Dock = System.Windows.Forms.DockStyle.Fill;
      this.tableLayoutInputsRight.Location = new System.Drawing.Point(312, 0);
      this.tableLayoutInputsRight.Margin = new System.Windows.Forms.Padding(0);
      this.tableLayoutInputsRight.Name = "tableLayoutInputsRight";
      this.tableLayoutInputsRight.RowCount = 2;
      this.tableLayoutInputsRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
      this.tableLayoutInputsRight.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
      this.tableLayoutInputsRight.Size = new System.Drawing.Size(314, 412);
      this.tableLayoutInputsRight.TabIndex = 0;
      // 
      // tableLayoutRightTop
      // 
      this.tableLayoutRightTop.ColumnCount = 2;
      this.tableLayoutRightTop.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.3F));
      this.tableLayoutRightTop.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 66.7F));
      this.tableLayoutRightTop.Controls.Add(this.CutoffFrequencyValue, 0, 1);
      this.tableLayoutRightTop.Controls.Add(this.QualityFactorValue, 0, 3);
      this.tableLayoutRightTop.Controls.Add(this.LinearGainValue, 0, 5);
      this.tableLayoutRightTop.Dock = System.Windows.Forms.DockStyle.Fill;
      this.tableLayoutRightTop.Location = new System.Drawing.Point(0, 0);
      this.tableLayoutRightTop.Margin = new System.Windows.Forms.Padding(0);
      this.tableLayoutRightTop.Name = "tableLayoutRightTop";
      this.tableLayoutRightTop.RowCount = 7;
      this.tableLayoutRightTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 18F));
      this.tableLayoutRightTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.5F));
      this.tableLayoutRightTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 18F));
      this.tableLayoutRightTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.5F));
      this.tableLayoutRightTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 18F));
      this.tableLayoutRightTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.5F));
      this.tableLayoutRightTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.5F));
      this.tableLayoutRightTop.Size = new System.Drawing.Size(314, 206);
      this.tableLayoutRightTop.TabIndex = 0;
      // 
      // CutoffFrequencyValue
      // 
      this.CutoffFrequencyValue.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
      this.CutoffFrequencyValue.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.CutoffFrequencyValue.Location = new System.Drawing.Point(0, 37);
      this.CutoffFrequencyValue.Margin = new System.Windows.Forms.Padding(0);
      this.CutoffFrequencyValue.Name = "CutoffFrequencyValue";
      this.CutoffFrequencyValue.Size = new System.Drawing.Size(104, 21);
      this.CutoffFrequencyValue.TabIndex = 10;
      this.CutoffFrequencyValue.Text = "1";
      this.CutoffFrequencyValue.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
      this.CutoffFrequencyValue.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.CutoffFrequencyValue_TextChanged);
      // 
      // QualityFactorValue
      // 
      this.QualityFactorValue.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
      this.QualityFactorValue.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.QualityFactorValue.Location = new System.Drawing.Point(0, 97);
      this.QualityFactorValue.Margin = new System.Windows.Forms.Padding(0);
      this.QualityFactorValue.Name = "QualityFactorValue";
      this.QualityFactorValue.Size = new System.Drawing.Size(104, 21);
      this.QualityFactorValue.TabIndex = 12;
      this.QualityFactorValue.Text = "1";
      this.QualityFactorValue.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
      this.QualityFactorValue.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.QualityFactorValue_TextChanged);
      // 
      // LinearGainValue
      // 
      this.LinearGainValue.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
      this.LinearGainValue.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.LinearGainValue.Location = new System.Drawing.Point(0, 157);
      this.LinearGainValue.Margin = new System.Windows.Forms.Padding(0);
      this.LinearGainValue.Name = "LinearGainValue";
      this.LinearGainValue.Size = new System.Drawing.Size(104, 21);
      this.LinearGainValue.TabIndex = 14;
      this.LinearGainValue.Text = "1";
      this.LinearGainValue.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
      this.LinearGainValue.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.LinearGainValue_TextChanged);
      // 
      // tableLayoutRightBottom
      // 
      this.tableLayoutRightBottom.ColumnCount = 2;
      this.tableLayoutRightBottom.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 96F));
      this.tableLayoutRightBottom.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 4F));
      this.tableLayoutRightBottom.Controls.Add(this.LogMessageValue, 0, 1);
      this.tableLayoutRightBottom.Dock = System.Windows.Forms.DockStyle.Fill;
      this.tableLayoutRightBottom.Location = new System.Drawing.Point(0, 206);
      this.tableLayoutRightBottom.Margin = new System.Windows.Forms.Padding(0);
      this.tableLayoutRightBottom.Name = "tableLayoutRightBottom";
      this.tableLayoutRightBottom.RowCount = 3;
      this.tableLayoutRightBottom.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 5F));
      this.tableLayoutRightBottom.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 70F));
      this.tableLayoutRightBottom.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
      this.tableLayoutRightBottom.Size = new System.Drawing.Size(314, 206);
      this.tableLayoutRightBottom.TabIndex = 1;
      // 
      // LogMessageValue
      // 
      this.LogMessageValue.Dock = System.Windows.Forms.DockStyle.Fill;
      this.LogMessageValue.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.LogMessageValue.ForeColor = System.Drawing.Color.Lime;
      this.LogMessageValue.Location = new System.Drawing.Point(0, 10);
      this.LogMessageValue.Margin = new System.Windows.Forms.Padding(0);
      this.LogMessageValue.Multiline = true;
      this.LogMessageValue.Name = "LogMessageValue";
      this.LogMessageValue.RightToLeft = System.Windows.Forms.RightToLeft.No;
      this.LogMessageValue.Size = new System.Drawing.Size(301, 144);
      this.LogMessageValue.TabIndex = 16;
      // 
      // tableLayoutMiddle
      // 
      this.tableLayoutMiddle.ColumnCount = 1;
      this.tableLayoutMiddle.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
      this.tableLayoutMiddle.Controls.Add(this.tableLayoutMiddleTop, 0, 0);
      this.tableLayoutMiddle.Controls.Add(this.tableLayoutMiddleBottom, 0, 1);
      this.tableLayoutMiddle.Dock = System.Windows.Forms.DockStyle.Fill;
      this.tableLayoutMiddle.Location = new System.Drawing.Point(187, 0);
      this.tableLayoutMiddle.Margin = new System.Windows.Forms.Padding(0);
      this.tableLayoutMiddle.Name = "tableLayoutMiddle";
      this.tableLayoutMiddle.RowCount = 2;
      this.tableLayoutMiddle.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
      this.tableLayoutMiddle.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
      this.tableLayoutMiddle.Size = new System.Drawing.Size(125, 412);
      this.tableLayoutMiddle.TabIndex = 2;
      // 
      // tableLayoutMiddleTop
      // 
      this.tableLayoutMiddleTop.ColumnCount = 1;
      this.tableLayoutMiddleTop.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
      this.tableLayoutMiddleTop.Controls.Add(this.CutoffFrequencyLabel, 0, 1);
      this.tableLayoutMiddleTop.Controls.Add(this.QualityFactorLabel, 0, 3);
      this.tableLayoutMiddleTop.Controls.Add(this.LinearGainLabel, 0, 5);
      this.tableLayoutMiddleTop.Dock = System.Windows.Forms.DockStyle.Fill;
      this.tableLayoutMiddleTop.Location = new System.Drawing.Point(0, 0);
      this.tableLayoutMiddleTop.Margin = new System.Windows.Forms.Padding(0);
      this.tableLayoutMiddleTop.Name = "tableLayoutMiddleTop";
      this.tableLayoutMiddleTop.RowCount = 7;
      this.tableLayoutMiddleTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 18F));
      this.tableLayoutMiddleTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.5F));
      this.tableLayoutMiddleTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 18F));
      this.tableLayoutMiddleTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.5F));
      this.tableLayoutMiddleTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 18F));
      this.tableLayoutMiddleTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.5F));
      this.tableLayoutMiddleTop.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.5F));
      this.tableLayoutMiddleTop.Size = new System.Drawing.Size(125, 206);
      this.tableLayoutMiddleTop.TabIndex = 0;
      // 
      // CutoffFrequencyLabel
      // 
      this.CutoffFrequencyLabel.AutoSize = true;
      this.CutoffFrequencyLabel.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.CutoffFrequencyLabel.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.CutoffFrequencyLabel.Location = new System.Drawing.Point(0, 44);
      this.CutoffFrequencyLabel.Margin = new System.Windows.Forms.Padding(0);
      this.CutoffFrequencyLabel.Name = "CutoffFrequencyLabel";
      this.CutoffFrequencyLabel.Size = new System.Drawing.Size(125, 16);
      this.CutoffFrequencyLabel.TabIndex = 9;
      this.CutoffFrequencyLabel.Text = "  Cutoff Frequency:";
      // 
      // QualityFactorLabel
      // 
      this.QualityFactorLabel.AutoSize = true;
      this.QualityFactorLabel.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.QualityFactorLabel.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.QualityFactorLabel.Location = new System.Drawing.Point(0, 104);
      this.QualityFactorLabel.Margin = new System.Windows.Forms.Padding(0);
      this.QualityFactorLabel.Name = "QualityFactorLabel";
      this.QualityFactorLabel.Size = new System.Drawing.Size(125, 16);
      this.QualityFactorLabel.TabIndex = 11;
      this.QualityFactorLabel.Text = "       Quality Factor:";
      // 
      // LinearGainLabel
      // 
      this.LinearGainLabel.AutoSize = true;
      this.LinearGainLabel.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.LinearGainLabel.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.LinearGainLabel.Location = new System.Drawing.Point(0, 164);
      this.LinearGainLabel.Margin = new System.Windows.Forms.Padding(0);
      this.LinearGainLabel.Name = "LinearGainLabel";
      this.LinearGainLabel.Size = new System.Drawing.Size(125, 16);
      this.LinearGainLabel.TabIndex = 13;
      this.LinearGainLabel.Text = "           Linear Gain:";
      // 
      // tableLayoutMiddleBottom
      // 
      this.tableLayoutMiddleBottom.ColumnCount = 1;
      this.tableLayoutMiddleBottom.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 28F));
      this.tableLayoutMiddleBottom.Controls.Add(this.LogMessageLabel, 0, 0);
      this.tableLayoutMiddleBottom.Dock = System.Windows.Forms.DockStyle.Fill;
      this.tableLayoutMiddleBottom.Location = new System.Drawing.Point(0, 206);
      this.tableLayoutMiddleBottom.Margin = new System.Windows.Forms.Padding(0);
      this.tableLayoutMiddleBottom.Name = "tableLayoutMiddleBottom";
      this.tableLayoutMiddleBottom.RowCount = 2;
      this.tableLayoutMiddleBottom.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.5F));
      this.tableLayoutMiddleBottom.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 88.5F));
      this.tableLayoutMiddleBottom.Size = new System.Drawing.Size(125, 206);
      this.tableLayoutMiddleBottom.TabIndex = 1;
      // 
      // LogMessageLabel
      // 
      this.LogMessageLabel.AutoSize = true;
      this.LogMessageLabel.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.LogMessageLabel.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.LogMessageLabel.Location = new System.Drawing.Point(0, 7);
      this.LogMessageLabel.Margin = new System.Windows.Forms.Padding(0);
      this.LogMessageLabel.Name = "LogMessageLabel";
      this.LogMessageLabel.Size = new System.Drawing.Size(125, 16);
      this.LogMessageLabel.TabIndex = 15;
      this.LogMessageLabel.Text = "        Log Message:";
      // 
      // Tab_outputs
      // 
      this.Tab_outputs.BackColor = System.Drawing.Color.WhiteSmoke;
      this.Tab_outputs.Controls.Add(this.tableLayoutOutputs);
      this.Tab_outputs.Location = new System.Drawing.Point(4, 24);
      this.Tab_outputs.Name = "Tab_outputs";
      this.Tab_outputs.Padding = new System.Windows.Forms.Padding(3);
      this.Tab_outputs.Size = new System.Drawing.Size(632, 418);
      this.Tab_outputs.TabIndex = 1;
      this.Tab_outputs.Text = "Outputs";
      // 
      // tableLayoutOutputs
      // 
      this.tableLayoutOutputs.ColumnCount = 1;
      this.tableLayoutOutputs.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
      this.tableLayoutOutputs.Controls.Add(this.cartesianChartMod, 0, 0);
      this.tableLayoutOutputs.Controls.Add(this.cartesianChartArg, 0, 1);
      this.tableLayoutOutputs.Dock = System.Windows.Forms.DockStyle.Fill;
      this.tableLayoutOutputs.Location = new System.Drawing.Point(3, 3);
      this.tableLayoutOutputs.Name = "tableLayoutOutputs";
      this.tableLayoutOutputs.RowCount = 2;
      this.tableLayoutOutputs.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
      this.tableLayoutOutputs.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
      this.tableLayoutOutputs.Size = new System.Drawing.Size(626, 412);
      this.tableLayoutOutputs.TabIndex = 2;
      // 
      // cartesianChartMod
      // 
      this.cartesianChartMod.Dock = System.Windows.Forms.DockStyle.Fill;
      this.cartesianChartMod.Location = new System.Drawing.Point(0, 0);
      this.cartesianChartMod.Margin = new System.Windows.Forms.Padding(0);
      this.cartesianChartMod.Name = "cartesianChartMod";
      this.cartesianChartMod.Size = new System.Drawing.Size(626, 206);
      this.cartesianChartMod.TabIndex = 0;
      this.cartesianChartMod.Text = "cartesianChart1";
      // 
      // cartesianChartArg
      // 
      this.cartesianChartArg.Dock = System.Windows.Forms.DockStyle.Fill;
      this.cartesianChartArg.Location = new System.Drawing.Point(0, 206);
      this.cartesianChartArg.Margin = new System.Windows.Forms.Padding(0);
      this.cartesianChartArg.Name = "cartesianChartArg";
      this.cartesianChartArg.Size = new System.Drawing.Size(626, 206);
      this.cartesianChartArg.TabIndex = 1;
      this.cartesianChartArg.Text = "cartesianChart2";
      // 
      // TitelLabel
      // 
      this.TitelLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
      this.TitelLabel.AutoSize = true;
      this.TitelLabel.Font = new System.Drawing.Font("Arial", 15F, System.Drawing.FontStyle.Bold);
      this.TitelLabel.Location = new System.Drawing.Point(175, 8);
      this.TitelLabel.Name = "TitelLabel";
      this.TitelLabel.Size = new System.Drawing.Size(288, 24);
      this.TitelLabel.TabIndex = 1;
      this.TitelLabel.Text = "FILTER DESIGN AND VIEWER";
      this.TitelLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
      // 
      // UIFigure
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.BackColor = System.Drawing.SystemColors.ScrollBar;
      this.ClientSize = new System.Drawing.Size(639, 481);
      this.Controls.Add(this.TitelLabel);
      this.Controls.Add(this.TabGroup);
      this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
      this.Name = "UIFigure";
      this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
      this.Text = "UI Figure";
      this.TabGroup.ResumeLayout(false);
      this.Tab_inputs.ResumeLayout(false);
      this.tableLayoutInputs.ResumeLayout(false);
      this.tableLayoutLeft.ResumeLayout(false);
      this.tableLayoutFiltersData.ResumeLayout(false);
      this.tableLayoutStatus.ResumeLayout(false);
      this.tableLayoutStatus.PerformLayout();
      this.tableLayoutLeftTop.ResumeLayout(false);
      this.tableLayoutLeftTop.PerformLayout();
      this.tableLayoutKnob.ResumeLayout(false);
      this.tableLayoutOrder.ResumeLayout(false);
      this.tableLayoutOrder.PerformLayout();
      this.tableLayoutType.ResumeLayout(false);
      this.tableLayoutType.PerformLayout();
      this.tableLayoutInputsRight.ResumeLayout(false);
      this.tableLayoutRightTop.ResumeLayout(false);
      this.tableLayoutRightTop.PerformLayout();
      this.tableLayoutRightBottom.ResumeLayout(false);
      this.tableLayoutRightBottom.PerformLayout();
      this.tableLayoutMiddle.ResumeLayout(false);
      this.tableLayoutMiddleTop.ResumeLayout(false);
      this.tableLayoutMiddleTop.PerformLayout();
      this.tableLayoutMiddleBottom.ResumeLayout(false);
      this.tableLayoutMiddleBottom.PerformLayout();
      this.Tab_outputs.ResumeLayout(false);
      this.tableLayoutOutputs.ResumeLayout(false);
      this.ResumeLayout(false);
      this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TabControl TabGroup;
        private System.Windows.Forms.TabPage Tab_inputs;
        private System.Windows.Forms.TabPage Tab_outputs;
        private System.Windows.Forms.Label TitelLabel;
        private System.Windows.Forms.Label FiltersparametersLabel;
        private System.Windows.Forms.ComboBox TypeDropDown;
        private System.Windows.Forms.Label FilterType;
        private KnobControl.KnobControl OrderKnob;
        private System.Windows.Forms.Label FilterOrder;
        private System.Windows.Forms.Label ComputeFiltersDataLabel;
        private System.Windows.Forms.Button CreateBodesButton;
        private System.Windows.Forms.Button ViewBodesButton;
        private System.Windows.Forms.TextBox CutoffFrequencyValue;
        private System.Windows.Forms.Label CutoffFrequencyLabel;
        private System.Windows.Forms.TextBox LinearGainValue;
        private System.Windows.Forms.Label LinearGainLabel;
        private System.Windows.Forms.TextBox QualityFactorValue;
        private System.Windows.Forms.Label QualityFactorLabel;
        private System.Windows.Forms.TextBox LogMessageValue;
        private System.Windows.Forms.Label LogMessageLabel;
        private LiveCharts.WinForms.CartesianChart cartesianChartMod;
        private LiveCharts.WinForms.CartesianChart cartesianChartArg;
        private System.Windows.Forms.TableLayoutPanel tableLayoutOutputs;
        private System.Windows.Forms.TableLayoutPanel tableLayoutInputs;
        private System.Windows.Forms.TableLayoutPanel tableLayoutInputsRight;
        private System.Windows.Forms.TableLayoutPanel tableLayoutRightTop;
        private System.Windows.Forms.TableLayoutPanel tableLayoutRightBottom;
        private System.Windows.Forms.TableLayoutPanel tableLayoutLeft;
        private System.Windows.Forms.TableLayoutPanel tableLayoutFiltersData;
        private System.Windows.Forms.TableLayoutPanel tableLayoutLeftTop;
        private System.Windows.Forms.TableLayoutPanel tableLayoutMiddleTop;
        private System.Windows.Forms.TableLayoutPanel tableLayoutMiddle;
        private System.Windows.Forms.TableLayoutPanel tableLayoutMiddleBottom;
        private System.Windows.Forms.TableLayoutPanel tableLayoutKnob;
        private System.Windows.Forms.TableLayoutPanel tableLayoutOrder;
        private System.Windows.Forms.TableLayoutPanel tableLayoutType;
        private System.Windows.Forms.Label FilterStatus;
        private Lamp.LampControl StatusLamp;
        private System.Windows.Forms.TableLayoutPanel tableLayoutStatus;
    }
}

