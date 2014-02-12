namespace ex1
{
    partial class Form1
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
            this.dgvOutput = new System.Windows.Forms.DataGridView();
            this.dgvInput = new System.Windows.Forms.DataGridView();
            this.gbGenetic = new System.Windows.Forms.GroupBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.comboBox2 = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.comboBox3 = new System.Windows.Forms.ComboBox();
            this.comboBox5 = new System.Windows.Forms.ComboBox();
            this.comboBox4 = new System.Windows.Forms.ComboBox();
            this.gbBase = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.nudVarCnt = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.gbControl = new System.Windows.Forms.GroupBox();
            this.btStop = new System.Windows.Forms.Button();
            this.btContinue = new System.Windows.Forms.Button();
            this.btStart = new System.Windows.Forms.Button();
            this.btPause = new System.Windows.Forms.Button();
            this.numericUpDown2 = new System.Windows.Forms.NumericUpDown();
            this.label5 = new System.Windows.Forms.Label();
            this.Value = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dgvOutput)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgvInput)).BeginInit();
            this.gbGenetic.SuspendLayout();
            this.gbBase.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudVarCnt)).BeginInit();
            this.gbControl.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).BeginInit();
            this.SuspendLayout();
            // 
            // dgvOutput
            // 
            this.dgvOutput.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.dgvOutput.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvOutput.Location = new System.Drawing.Point(570, 24);
            this.dgvOutput.Name = "dgvOutput";
            this.dgvOutput.Size = new System.Drawing.Size(307, 385);
            this.dgvOutput.TabIndex = 0;
            // 
            // dgvInput
            // 
            this.dgvInput.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.dgvInput.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvInput.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Value});
            this.dgvInput.Location = new System.Drawing.Point(-1, 24);
            this.dgvInput.Name = "dgvInput";
            this.dgvInput.Size = new System.Drawing.Size(326, 385);
            this.dgvInput.TabIndex = 1;
            this.dgvInput.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvInput_CellContentClick);
            // 
            // gbGenetic
            // 
            this.gbGenetic.Controls.Add(this.comboBox1);
            this.gbGenetic.Controls.Add(this.comboBox2);
            this.gbGenetic.Controls.Add(this.label1);
            this.gbGenetic.Controls.Add(this.comboBox3);
            this.gbGenetic.Controls.Add(this.comboBox5);
            this.gbGenetic.Controls.Add(this.comboBox4);
            this.gbGenetic.Location = new System.Drawing.Point(332, 102);
            this.gbGenetic.Name = "gbGenetic";
            this.gbGenetic.Size = new System.Drawing.Size(233, 188);
            this.gbGenetic.TabIndex = 2;
            this.gbGenetic.TabStop = false;
            this.gbGenetic.Text = "Genetic Settings";
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(22, 26);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(121, 21);
            this.comboBox1.TabIndex = 4;
            // 
            // comboBox2
            // 
            this.comboBox2.FormattingEnabled = true;
            this.comboBox2.Location = new System.Drawing.Point(30, 34);
            this.comboBox2.Name = "comboBox2";
            this.comboBox2.Size = new System.Drawing.Size(121, 21);
            this.comboBox2.TabIndex = 5;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(70, 74);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 10;
            this.label1.Text = "label1";
            // 
            // comboBox3
            // 
            this.comboBox3.FormattingEnabled = true;
            this.comboBox3.Location = new System.Drawing.Point(38, 42);
            this.comboBox3.Name = "comboBox3";
            this.comboBox3.Size = new System.Drawing.Size(121, 21);
            this.comboBox3.TabIndex = 6;
            // 
            // comboBox5
            // 
            this.comboBox5.FormattingEnabled = true;
            this.comboBox5.Location = new System.Drawing.Point(54, 58);
            this.comboBox5.Name = "comboBox5";
            this.comboBox5.Size = new System.Drawing.Size(121, 21);
            this.comboBox5.TabIndex = 8;
            // 
            // comboBox4
            // 
            this.comboBox4.FormattingEnabled = true;
            this.comboBox4.Location = new System.Drawing.Point(46, 50);
            this.comboBox4.Name = "comboBox4";
            this.comboBox4.Size = new System.Drawing.Size(121, 21);
            this.comboBox4.TabIndex = 7;
            // 
            // gbBase
            // 
            this.gbBase.Controls.Add(this.label4);
            this.gbBase.Controls.Add(this.nudVarCnt);
            this.gbBase.Location = new System.Drawing.Point(332, 5);
            this.gbBase.Name = "gbBase";
            this.gbBase.Size = new System.Drawing.Size(233, 91);
            this.gbBase.TabIndex = 3;
            this.gbBase.TabStop = false;
            this.gbBase.Text = "Base Settings";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(37, 24);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(81, 13);
            this.label4.TabIndex = 13;
            this.label4.Text = "Variables Count";
            // 
            // nudVarCnt
            // 
            this.nudVarCnt.Location = new System.Drawing.Point(124, 21);
            this.nudVarCnt.Name = "nudVarCnt";
            this.nudVarCnt.Size = new System.Drawing.Size(78, 20);
            this.nudVarCnt.TabIndex = 9;
            this.nudVarCnt.ValueChanged += new System.EventHandler(this.nudVarCnt_ValueChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(710, 6);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(39, 13);
            this.label2.TabIndex = 11;
            this.label2.Text = "Output";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(124, 5);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(31, 13);
            this.label3.TabIndex = 12;
            this.label3.Text = "Input";
            // 
            // gbControl
            // 
            this.gbControl.Controls.Add(this.btStop);
            this.gbControl.Controls.Add(this.btContinue);
            this.gbControl.Controls.Add(this.btStart);
            this.gbControl.Controls.Add(this.btPause);
            this.gbControl.Controls.Add(this.numericUpDown2);
            this.gbControl.Controls.Add(this.label5);
            this.gbControl.Location = new System.Drawing.Point(332, 297);
            this.gbControl.Name = "gbControl";
            this.gbControl.Size = new System.Drawing.Size(233, 112);
            this.gbControl.TabIndex = 13;
            this.gbControl.TabStop = false;
            this.gbControl.Text = "Control";
            // 
            // btStop
            // 
            this.btStop.Location = new System.Drawing.Point(120, 54);
            this.btStop.Name = "btStop";
            this.btStop.Size = new System.Drawing.Size(103, 23);
            this.btStop.TabIndex = 5;
            this.btStop.Text = "Stop";
            this.btStop.UseVisualStyleBackColor = true;
            this.btStop.Click += new System.EventHandler(this.btStop_Click);
            // 
            // btContinue
            // 
            this.btContinue.Location = new System.Drawing.Point(6, 54);
            this.btContinue.Name = "btContinue";
            this.btContinue.Size = new System.Drawing.Size(103, 23);
            this.btContinue.TabIndex = 4;
            this.btContinue.Text = "Continue";
            this.btContinue.UseVisualStyleBackColor = true;
            this.btContinue.Click += new System.EventHandler(this.btContinue_Click);
            // 
            // btStart
            // 
            this.btStart.Location = new System.Drawing.Point(6, 83);
            this.btStart.Name = "btStart";
            this.btStart.Size = new System.Drawing.Size(103, 23);
            this.btStart.TabIndex = 3;
            this.btStart.Text = "Start";
            this.btStart.UseVisualStyleBackColor = true;
            this.btStart.Click += new System.EventHandler(this.btStart_Click);
            // 
            // btPause
            // 
            this.btPause.Location = new System.Drawing.Point(120, 83);
            this.btPause.Name = "btPause";
            this.btPause.Size = new System.Drawing.Size(103, 23);
            this.btPause.TabIndex = 2;
            this.btPause.Text = "Pause";
            this.btPause.UseVisualStyleBackColor = true;
            this.btPause.Click += new System.EventHandler(this.btPause_Click);
            // 
            // numericUpDown2
            // 
            this.numericUpDown2.Location = new System.Drawing.Point(111, 26);
            this.numericUpDown2.Name = "numericUpDown2";
            this.numericUpDown2.ReadOnly = true;
            this.numericUpDown2.Size = new System.Drawing.Size(116, 20);
            this.numericUpDown2.TabIndex = 1;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(8, 28);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(97, 13);
            this.label5.TabIndex = 0;
            this.label5.Text = "Current generation:";
            // 
            // Value
            // 
            this.Value.HeaderText = "Value";
            this.Value.Name = "Value";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(877, 409);
            this.Controls.Add(this.gbControl);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.gbBase);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.gbGenetic);
            this.Controls.Add(this.dgvInput);
            this.Controls.Add(this.dgvOutput);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dgvOutput)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgvInput)).EndInit();
            this.gbGenetic.ResumeLayout(false);
            this.gbGenetic.PerformLayout();
            this.gbBase.ResumeLayout(false);
            this.gbBase.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudVarCnt)).EndInit();
            this.gbControl.ResumeLayout(false);
            this.gbControl.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dgvOutput;
        private System.Windows.Forms.DataGridView dgvInput;
        private System.Windows.Forms.GroupBox gbGenetic;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.ComboBox comboBox2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox comboBox3;
        private System.Windows.Forms.ComboBox comboBox5;
        private System.Windows.Forms.ComboBox comboBox4;
        private System.Windows.Forms.GroupBox gbBase;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown nudVarCnt;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.GroupBox gbControl;
        private System.Windows.Forms.NumericUpDown numericUpDown2;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button btStop;
        private System.Windows.Forms.Button btContinue;
        private System.Windows.Forms.Button btStart;
        private System.Windows.Forms.Button btPause;
        private System.Windows.Forms.DataGridViewTextBoxColumn Value;
    }
}

