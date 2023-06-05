using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GalleryGUI
{
    public partial class Signup : Form
    {
        public Signup()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Program.location = this.Location;
            Program.name = this.textBox1.Text;
            MainMenu menu = new MainMenu();
            this.Hide();
            menu.ShowDialog();
            this.Close();

        }

        private void Signup_Load(object sender, EventArgs e)
        {
            this.Location = Program.location;
        }
    }
}
