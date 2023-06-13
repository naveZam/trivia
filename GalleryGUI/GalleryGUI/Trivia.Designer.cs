namespace GalleryGUI
{
    partial class Trivia
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
            button2 = new Button();
            button1 = new Button();
            button3 = new Button();
            button4 = new Button();
            label1 = new Label();
            SuspendLayout();
            // 
            // button2
            // 
            button2.BackColor = Color.FromArgb(35, 35, 35);
            button2.FlatStyle = FlatStyle.Flat;
            button2.Font = new Font("Segoe UI Black", 9F, FontStyle.Regular, GraphicsUnit.Point);
            button2.ForeColor = Color.FromArgb(87, 87, 87);
            button2.Location = new Point(51, 330);
            button2.Name = "button2";
            button2.Size = new Size(319, 66);
            button2.TabIndex = 9;
            button2.Text = "Loading answer";
            button2.UseVisualStyleBackColor = false;
            // 
            // button1
            // 
            button1.BackColor = Color.FromArgb(35, 35, 35);
            button1.FlatStyle = FlatStyle.Flat;
            button1.Font = new Font("Segoe UI Black", 9F, FontStyle.Regular, GraphicsUnit.Point);
            button1.ForeColor = Color.FromArgb(87, 87, 87);
            button1.Location = new Point(438, 330);
            button1.Name = "button1";
            button1.Size = new Size(319, 66);
            button1.TabIndex = 10;
            button1.Text = "Loading answer";
            button1.UseVisualStyleBackColor = false;
            // 
            // button3
            // 
            button3.BackColor = Color.FromArgb(35, 35, 35);
            button3.FlatStyle = FlatStyle.Flat;
            button3.Font = new Font("Segoe UI Black", 9F, FontStyle.Regular, GraphicsUnit.Point);
            button3.ForeColor = Color.FromArgb(87, 87, 87);
            button3.Location = new Point(51, 229);
            button3.Name = "button3";
            button3.Size = new Size(319, 66);
            button3.TabIndex = 11;
            button3.Text = "Loading answer";
            button3.UseVisualStyleBackColor = false;
            // 
            // button4
            // 
            button4.BackColor = Color.FromArgb(35, 35, 35);
            button4.FlatStyle = FlatStyle.Flat;
            button4.Font = new Font("Segoe UI Black", 9F, FontStyle.Regular, GraphicsUnit.Point);
            button4.ForeColor = Color.FromArgb(87, 87, 87);
            button4.Location = new Point(438, 229);
            button4.Name = "button4";
            button4.Size = new Size(319, 66);
            button4.TabIndex = 12;
            button4.Text = "Loading answer";
            button4.UseVisualStyleBackColor = false;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 19F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.FromArgb(87, 87, 87);
            label1.Location = new Point(228, 43);
            label1.Name = "label1";
            label1.Size = new Size(333, 51);
            label1.TabIndex = 13;
            label1.Text = "Loading question\r\n";
            // 
            // Trivia
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(17, 17, 17);
            ClientSize = new Size(800, 450);
            Controls.Add(label1);
            Controls.Add(button4);
            Controls.Add(button3);
            Controls.Add(button1);
            Controls.Add(button2);
            Name = "Trivia";
            Text = "Trivia";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button2;
        private Button button1;
        private Button button3;
        private Button button4;
        private Label label1;
    }
}