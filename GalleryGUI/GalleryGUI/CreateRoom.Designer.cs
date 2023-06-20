namespace GalleryGUI
{
    partial class CreateRoom
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
            button1 = new Button();
            textBox1 = new TextBox();
            label1 = new Label();
            button2 = new Button();
            label2 = new Label();
            textBox2 = new TextBox();
            label3 = new Label();
            textBox3 = new TextBox();
            label4 = new Label();
            textBox4 = new TextBox();
            SuspendLayout();
            // 
            // button1
            // 
            button1.BackColor = Color.FromArgb(35, 35, 35);
            button1.FlatStyle = FlatStyle.Flat;
            button1.ForeColor = Color.FromArgb(87, 87, 87);
            button1.Location = new Point(328, 306);
            button1.Name = "button1";
            button1.Size = new Size(150, 55);
            button1.TabIndex = 8;
            button1.Text = "Create room";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // textBox1
            // 
            textBox1.BackColor = Color.FromArgb(52, 52, 52);
            textBox1.BorderStyle = BorderStyle.FixedSingle;
            textBox1.Cursor = Cursors.Hand;
            textBox1.Font = new Font("Segoe UI", 15F, FontStyle.Regular, GraphicsUnit.Point);
            textBox1.Location = new Point(308, 49);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(195, 47);
            textBox1.TabIndex = 11;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.FromArgb(87, 87, 87);
            label1.Location = new Point(140, 49);
            label1.Name = "label1";
            label1.Size = new Size(162, 32);
            label1.TabIndex = 12;
            label1.Text = "Room Name:";
            label1.Click += label1_Click;
            // 
            // button2
            // 
            button2.BackColor = Color.FromArgb(35, 35, 35);
            button2.FlatStyle = FlatStyle.Flat;
            button2.ForeColor = Color.FromArgb(87, 87, 87);
            button2.Location = new Point(328, 383);
            button2.Name = "button2";
            button2.Size = new Size(150, 55);
            button2.TabIndex = 13;
            button2.Text = "Return";
            button2.UseVisualStyleBackColor = false;
            button2.Click += button2_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label2.ForeColor = Color.FromArgb(87, 87, 87);
            label2.Location = new Point(105, 114);
            label2.Name = "label2";
            label2.Size = new Size(197, 32);
            label2.TabIndex = 15;
            label2.Text = "Question count:";
            label2.Click += label2_Click;
            // 
            // textBox2
            // 
            textBox2.BackColor = Color.FromArgb(52, 52, 52);
            textBox2.BorderStyle = BorderStyle.FixedSingle;
            textBox2.Cursor = Cursors.Hand;
            textBox2.Font = new Font("Segoe UI", 15F, FontStyle.Regular, GraphicsUnit.Point);
            textBox2.Location = new Point(308, 114);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(195, 47);
            textBox2.TabIndex = 14;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label3.ForeColor = Color.FromArgb(87, 87, 87);
            label3.Location = new Point(94, 182);
            label3.Name = "label3";
            label3.Size = new Size(208, 32);
            label3.TabIndex = 17;
            label3.Text = "Answer Timeout:";
            // 
            // textBox3
            // 
            textBox3.BackColor = Color.FromArgb(52, 52, 52);
            textBox3.BorderStyle = BorderStyle.FixedSingle;
            textBox3.Cursor = Cursors.Hand;
            textBox3.Font = new Font("Segoe UI", 15F, FontStyle.Regular, GraphicsUnit.Point);
            textBox3.Location = new Point(308, 182);
            textBox3.Name = "textBox3";
            textBox3.Size = new Size(195, 47);
            textBox3.TabIndex = 16;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label4.ForeColor = Color.FromArgb(87, 87, 87);
            label4.Location = new Point(165, 253);
            label4.Name = "label4";
            label4.Size = new Size(137, 32);
            label4.TabIndex = 19;
            label4.Text = "Max users:";
            // 
            // textBox4
            // 
            textBox4.BackColor = Color.FromArgb(52, 52, 52);
            textBox4.BorderStyle = BorderStyle.FixedSingle;
            textBox4.Cursor = Cursors.Hand;
            textBox4.Font = new Font("Segoe UI", 15F, FontStyle.Regular, GraphicsUnit.Point);
            textBox4.Location = new Point(308, 253);
            textBox4.Name = "textBox4";
            textBox4.Size = new Size(195, 47);
            textBox4.TabIndex = 18;
            // 
            // CreateRoom
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(17, 17, 17);
            ClientSize = new Size(800, 450);
            Controls.Add(label4);
            Controls.Add(textBox4);
            Controls.Add(label3);
            Controls.Add(textBox3);
            Controls.Add(label2);
            Controls.Add(textBox2);
            Controls.Add(button2);
            Controls.Add(label1);
            Controls.Add(textBox1);
            Controls.Add(button1);
            Name = "CreateRoom";
            Text = "CreateRoom";
            Load += CreateRoom_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button1;
        private TextBox textBox1;
        private Label label1;
        private Button button2;
        private Label label2;
        private TextBox textBox2;
        private Label label3;
        private TextBox textBox3;
        private Label label4;
        private TextBox textBox4;
    }
}