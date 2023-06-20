namespace GalleryGUI
{
    partial class Lobby
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
            label5 = new Label();
            label6 = new Label();
            button1 = new Button();
            SuspendLayout();
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label5.ForeColor = Color.FromArgb(87, 87, 87);
            label5.Location = new Point(12, 9);
            label5.Name = "label5";
            label5.Size = new Size(110, 32);
            label5.TabIndex = 17;
            label5.Text = "Players: ";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Segoe UI", 15F, FontStyle.Bold, GraphicsUnit.Point);
            label6.ForeColor = Color.FromArgb(87, 87, 87);
            label6.Location = new Point(146, 9);
            label6.Name = "label6";
            label6.Size = new Size(72, 41);
            label6.TabIndex = 18;
            label6.Text = "null";
            // 
            // button1
            // 
            button1.BackColor = Color.FromArgb(35, 35, 35);
            button1.FlatStyle = FlatStyle.Flat;
            button1.ForeColor = Color.FromArgb(87, 87, 87);
            button1.Location = new Point(322, 362);
            button1.Name = "button1";
            button1.Size = new Size(150, 55);
            button1.TabIndex = 19;
            button1.Text = "Leave Room";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // Lobby
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(17, 17, 17);
            ClientSize = new Size(800, 450);
            Controls.Add(button1);
            Controls.Add(label6);
            Controls.Add(label5);
            Name = "Lobby";
            Text = "Lobby";
            Load += Lobby_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Label label5;
        private Label label6;
        private Button button1;
    }
}