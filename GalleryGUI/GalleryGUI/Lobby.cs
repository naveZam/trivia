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
    public partial class Lobby : Form
    {
        public Lobby()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Program.location = this.Location;
            MainMenu menu = new MainMenu();
            Program.communicator.Send(new Messages(), 6);
            GenericResponse response = Program.communicator.Receive();
            this.Hide();
            menu.ShowDialog();
            this.Close();
        }

        private void Lobby_Load(object sender, EventArgs e)
        {
            this.Location = Program.location;
            Program.communicator.Send(new Messages(), 5);
            roomStateResponse response = Program.communicator.transformState(Program.communicator.Receive());
            this.label6.Text = response.players;
        }
        private Thread thread;
        private void updateThread()
        {
            Program.communicator.Send(new Messages(), 5);
            roomStateResponse response = Program.communicator.transformState(Program.communicator.Receive());
            this.label6.Text = response.players;
            if (response.status == 0)
            {
                MainMenu menu = new MainMenu();
                this.Hide();
                menu.ShowDialog();
                this.Close();
            }
        }
    }
}
