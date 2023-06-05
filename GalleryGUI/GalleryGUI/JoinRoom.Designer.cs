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
            textBox1 = new TextBox();
            label1 = new Label();
            button1 = new Button();
            SuspendLayout();
            // 
            // button2
            // 
            button2.BackColor = Color.FromArgb(35, 35, 35);
            button2.FlatStyle = FlatStyle.Flat;
            button2.ForeColor = Color.FromArgb(87, 87, 87);
            button2.Location = new Point(325, 214);
            button2.Name = "button2";
            button2.Size = new Size(150, 55);
            button2.TabIndex = 9;
            button2.Text = "Join room";
            button2.UseVisualStyleBackColor = false;
            // 
            // textBox1
            // 
            textBox1.BackColor = Color.FromArgb(52, 52, 52);
            textBox1.BorderStyle = BorderStyle.FixedSingle;
            textBox1.Cursor = Cursors.Hand;
            textBox1.Font = new Font("Segoe UI", 15F, FontStyle.Regular, GraphicsUnit.Point);
            textBox1.Location = new Point(325, 134);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(141, 47);
            textBox1.TabIndex = 10;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.FromArgb(87, 87, 87);
            label1.Location = new Point(188, 143);
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
            // JoinRoom
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(17, 17, 17);
            ClientSize = new Size(800, 450);
            Controls.Add(button1);
            Controls.Add(label1);
            Controls.Add(textBox1);
            Controls.Add(button2);
            Name = "JoinRoom";
            Text = "JoinRoom";
            Load += JoinRoom_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button2;
        private TextBox textBox1;
        private Label label1;
        private Button button1;
    }
}