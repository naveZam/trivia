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
    public partial class Stats : Form
    {
        public Stats()
        {
            InitializeComponent();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Program.location = this.Location;
            MainMenu menu = new MainMenu();
            this.Hide();
            menu.ShowDialog();
            this.Close();

        }

        private void Stats_Load(object sender, EventArgs e)
        {
            this.Location = Program.location;

            Program.communicator.Send(new Messages(), 11);
            StatsResponse response = Program.communicator.transform(Program.communicator.Receive());
            if (response.totalGames > 0)
            {
                this.label1.Text = "Questions answerd: "+response.totalAnswerCount.ToString();
                this.label2.Text = "Questions answerd correctly: "+response.correctAnswerCount.ToString();
                this.label3.Text = "Average time to answer: "+ response.averageAnswerTime.ToString() + "miliseconds";
                this.label2.Text = "Total games: "+response.totalGames.ToString();
            }


        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
