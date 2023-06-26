using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace GalleryGUI
{
    public partial class MainMenu : Form
    {
        public MainMenu()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }
        //on load of main menu
        private void MainMenu_Load(object sender, EventArgs e)
        {
            this.Location = Program.location;

            this.label1.Text = "Welcome " + Program.name;
        }
        //on enter of the create room menu
        private void button1_Click_1(object sender, EventArgs e)
        {
            Program.location = this.Location;
            CreateRoom CreateRoom = new CreateRoom();
            this.Hide();
            CreateRoom.ShowDialog();
            this.Close();
        }
        //on enter of the join room menu
        private void button2_Click(object sender, EventArgs e)
        {
            Program.location = this.Location;
            JoinRoom joinRoom = new JoinRoom();
            this.Hide();
            joinRoom.ShowDialog();
            this.Close();
        }
        //on enter of the stats menu
        private void button3_Click(object sender, EventArgs e)
        {
            Program.location = this.Location;
            Stats stats = new Stats();
            this.Hide();
            stats.ShowDialog();
            this.Close();
        }
        //on exit of the main menu
        private void button4_Click(object sender, EventArgs e)
        {
            Program.communicator.Send(new Messages(), 8);
            this.Close();
        }
        private static bool isSongLoaded = false;
        private static System.Media.SoundPlayer player = new System.Media.SoundPlayer();
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (comboBox1.SelectedIndex)
            {
                case 1:
                    player.Load();
                    return;

            }
        }
    }
}
