namespace GalleryGUI
{
    partial class MainMenu
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
            label1 = new Label();
            button1 = new Button();
            button2 = new Button();
            button3 = new Button();
            button4 = new Button();
            comboBox1 = new ComboBox();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.FromArgb(87, 87, 87);
            label1.Location = new Point(335, 53);
            label1.Name = "label1";
            label1.Size = new Size(106, 32);
            label1.TabIndex = 0;
            label1.Text = "Loading";
            // 
            // button1
            // 
            button1.BackColor = Color.FromArgb(35, 35, 35);
            button1.FlatStyle = FlatStyle.Flat;
            button1.ForeColor = Color.FromArgb(87, 87, 87);
            button1.Location = new Point(220, 122);
            button1.Name = "button1";
            button1.Size = new Size(150, 55);
            button1.TabIndex = 7;
            button1.Text = "Create room";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click_1;
            // 
            // button2
            // 
            button2.BackColor = Color.FromArgb(35, 35, 35);
            button2.FlatStyle = FlatStyle.Flat;
            button2.ForeColor = Color.FromArgb(87, 87, 87);
            button2.Location = new Point(432, 122);
            button2.Name = "button2";
            button2.Size = new Size(150, 55);
            button2.TabIndex = 8;
            button2.Text = "Join room";
            button2.UseVisualStyleBackColor = false;
            button2.Click += button2_Click;
            // 
            // button3
            // 
            button3.BackColor = Color.FromArgb(35, 35, 35);
            button3.FlatStyle = FlatStyle.Flat;
            button3.ForeColor = Color.FromArgb(87, 87, 87);
            button3.Location = new Point(325, 199);
            button3.Name = "button3";
            button3.Size = new Size(150, 55);
            button3.TabIndex = 9;
            button3.Text = "Show stats";
            button3.UseVisualStyleBackColor = false;
            button3.Click += button3_Click;
            // 
            // button4
            // 
            button4.BackColor = Color.FromArgb(35, 35, 35);
            button4.FlatStyle = FlatStyle.Flat;
            button4.ForeColor = Color.FromArgb(87, 87, 87);
            button4.Location = new Point(325, 340);
            button4.Name = "button4";
            button4.Size = new Size(150, 55);
            button4.TabIndex = 10;
            button4.Text = "Exit";
            button4.UseVisualStyleBackColor = false;
            button4.Click += button4_Click;
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Location = new Point(606, 12);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(182, 33);
            comboBox1.TabIndex = 11;
            comboBox1.SelectedIndexChanged += comboBox1_SelectedIndexChanged;
            // 
            // MainMenu
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(17, 17, 17);
            ClientSize = new Size(800, 450);
            Controls.Add(comboBox1);
            Controls.Add(button4);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(button1);
            Controls.Add(label1);
            Name = "MainMenu";
            Text = "MainMenu";
            Load += MainMenu_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Button button1;
        private Button button2;
        private Button button3;
        private Button button4;
        private ComboBox comboBox1;
    }
}