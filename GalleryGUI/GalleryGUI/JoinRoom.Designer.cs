namespace GalleryGUI
{
    partial class JoinRoom
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
            label1 = new Label();
            button1 = new Button();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            label6 = new Label();
            button3 = new Button();
            SuspendLayout();
            // 
            // button2
            // 
            button2.BackColor = Color.FromArgb(35, 35, 35);
            button2.FlatStyle = FlatStyle.Flat;
            button2.ForeColor = Color.FromArgb(87, 87, 87);
            button2.Location = new Point(248, 238);
            button2.Name = "button2";
            button2.Size = new Size(150, 55);
            button2.TabIndex = 9;
            button2.Text = "Join room";
            button2.UseVisualStyleBackColor = false;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.FromArgb(87, 87, 87);
            label1.Location = new Point(184, 40);
            label1.Name = "label1";
            label1.Size = new Size(121, 32);
            label1.TabIndex = 11;
            label1.Text = "Room ID:";
            // 
            // button1
            // 
            button1.BackColor = Color.FromArgb(35, 35, 35);
            button1.FlatStyle = FlatStyle.Flat;
            button1.ForeColor = Color.FromArgb(87, 87, 87);
            button1.Location = new Point(325, 383);
            button1.Name = "button1";
            button1.Size = new Size(150, 55);
            button1.TabIndex = 12;
            button1.Text = "Return";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label2.ForeColor = Color.FromArgb(87, 87, 87);
            label2.Location = new Point(340, 40);
            label2.Name = "label2";
            label2.Size = new Size(58, 32);
            label2.TabIndex = 13;
            label2.Text = "null";
            label2.Click += label2_Click;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label3.ForeColor = Color.FromArgb(87, 87, 87);
            label3.Location = new Point(184, 81);
            label3.Name = "label3";
            label3.Size = new Size(162, 32);
            label3.TabIndex = 14;
            label3.Text = "Room Name:";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label4.ForeColor = Color.FromArgb(87, 87, 87);
            label4.Location = new Point(184, 135);
            label4.Name = "label4";
            label4.Size = new Size(110, 32);
            label4.TabIndex = 15;
            label4.Text = "Players: ";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label5.ForeColor = Color.FromArgb(87, 87, 87);
            label5.Location = new Point(361, 81);
            label5.Name = "label5";
            label5.Size = new Size(58, 32);
            label5.TabIndex = 16;
            label5.Text = "null";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label6.ForeColor = Color.FromArgb(87, 87, 87);
            label6.Location = new Point(325, 135);
            label6.Name = "label6";
            label6.Size = new Size(58, 32);
            label6.TabIndex = 17;
            label6.Text = "null";
            // 
            // button3
            // 
            button3.BackColor = Color.FromArgb(35, 35, 35);
            button3.FlatStyle = FlatStyle.Flat;
            button3.ForeColor = Color.FromArgb(87, 87, 87);
            button3.Location = new Point(452, 238);
            button3.Name = "button3";
            button3.Size = new Size(103, 55);
            button3.TabIndex = 18;
            button3.Text = "Next";
            button3.UseVisualStyleBackColor = false;
            button3.Click += button3_Click;
            // 
            // JoinRoom
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(17, 17, 17);
            ClientSize = new Size(800, 450);
            Controls.Add(button3);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(button1);
            Controls.Add(label1);
            Controls.Add(button2);
            Name = "JoinRoom";
            Text = "JoinRoom";
            Load += JoinRoom_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button2;
        private Label label1;
        private Button button1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label5;
        private Label label6;
        private Button button3;
    }
}