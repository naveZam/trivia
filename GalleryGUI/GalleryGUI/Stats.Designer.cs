namespace GalleryGUI
{
    partial class Stats
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
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            button4 = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 15F, FontStyle.Regular, GraphicsUnit.Point);
            label1.ForeColor = Color.FromArgb(87, 87, 87);
            label1.Location = new Point(12, 9);
            label1.Name = "label1";
            label1.Size = new Size(373, 41);
            label1.TabIndex = 0;
            label1.Text = "Questions answered: NULL";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 15F, FontStyle.Regular, GraphicsUnit.Point);
            label2.ForeColor = Color.FromArgb(87, 87, 87);
            label2.Location = new Point(12, 66);
            label2.Name = "label2";
            label2.Size = new Size(482, 41);
            label2.TabIndex = 1;
            label2.Text = "Question answered correctly: NULL";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 15F, FontStyle.Regular, GraphicsUnit.Point);
            label3.ForeColor = Color.FromArgb(87, 87, 87);
            label3.Location = new Point(12, 133);
            label3.Name = "label3";
            label3.Size = new Size(415, 41);
            label3.TabIndex = 2;
            label3.Text = "Average time to answer: NULL";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 15F, FontStyle.Regular, GraphicsUnit.Point);
            label4.ForeColor = Color.FromArgb(87, 87, 87);
            label4.Location = new Point(12, 199);
            label4.Name = "label4";
            label4.Size = new Size(360, 41);
            label4.TabIndex = 3;
            label4.Text = "Total games played: NULL";
            // 
            // button4
            // 
            button4.BackColor = Color.FromArgb(35, 35, 35);
            button4.FlatStyle = FlatStyle.Flat;
            button4.ForeColor = Color.FromArgb(87, 87, 87);
            button4.Location = new Point(310, 357);
            button4.Name = "button4";
            button4.Size = new Size(150, 55);
            button4.TabIndex = 11;
            button4.Text = "Back";
            button4.UseVisualStyleBackColor = false;
            button4.Click += button4_Click;
            // 
            // Stats
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(17, 17, 17);
            ClientSize = new Size(800, 450);
            Controls.Add(button4);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Name = "Stats";
            Text = "Stats";
            Load += Stats_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Button button4;
    }
}