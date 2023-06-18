﻿using System;
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
    public partial class JoinRoom : Form
    {
        public JoinRoom()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Program.location = this.Location;
            MainMenu menu = new MainMenu();
            this.Hide();
            menu.ShowDialog();
            this.Close();
        }

        private void JoinRoom_Load(object sender, EventArgs e)
        {
            this.Location = Program.location;
            Program.communicator.Send(new Messages(), 9);
            this.rooms = Program.communicator.transform(Program.communicator.Receive());
            foreach (Room room in this.rooms)
            {
                Program.communicator.Send(new PlayersMessage(room.ID), 10);
                Queue<string> playerQueue = Program.communicator.transformPlayers(Program.communicator.Receive());
                room.players = playerQueue;
            }
            Room tempRoom = this.rooms.Dequeue();
            this.label1.Text = tempRoom.ID.ToString();
            this.label2.Text = tempRoom.name;
            string players = "";
            foreach (string player in tempRoom.players)
            {
                players += player + ",";
            }
            this.label3.Text = players;
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
        private Queue<Room>? rooms;

        private void button3_Click(object sender, EventArgs e)
        {

        }
    }
}
