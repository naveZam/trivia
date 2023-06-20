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
    public partial class CreateRoom : Form
    {
        public CreateRoom()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Program.location = this.Location;
            MainMenu menu = new MainMenu();
            this.Hide();
            menu.ShowDialog();
            this.Close();
        }

        private void CreateRoom_Load(object sender, EventArgs e)
        {
            this.Location = Program.location;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            createRoom room = new createRoom(textBox1.Text, uint.Parse(textBox2.Text), uint.Parse(textBox3.Text), uint.Parse(textBox4.Text));
            Program.communicator.Send(room, 13);
            GenericResponse genericResponse = Program.communicator.Receive();
            if(genericResponse.ID != 1)
            {
                throw new Exception("Error creating room");
            }
            Lobby menu = new Lobby();
            this.Hide();
            menu.ShowDialog();
            this.Close();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }
}
