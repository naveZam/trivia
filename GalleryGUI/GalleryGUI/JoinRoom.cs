using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
namespace GalleryGUI
{
    public partial class JoinRoom : Form
    {
        public JoinRoom()
        {
            InitializeComponent();
        }
        //on exit of the menu
        private void button1_Click(object sender, EventArgs e)
        {
            Program.location = this.Location;
            MainMenu menu = new MainMenu();
            this.Hide();
            menu.ShowDialog();
            this.Close();
        }
        //on load of the menu
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
            if(this.rooms.Count() == 0)
            {
                this.label5.Text = "No rooms";
                return; 
            }
            Room tempRoom = this.rooms.Dequeue();
            rooms.Enqueue(tempRoom);
            this.label2.Text = tempRoom.ID.ToString();
            this.label5.Text = tempRoom.name;
            string players = "";
            foreach (string player in tempRoom.players)
            {
                players += player + ",";
            }
            this.label6.Text = players;
            thread = new Thread(updateThread);
            thread.Start();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
        private Queue<Room>? rooms;
        //on cycling a room
        private void button3_Click(object sender, EventArgs e)
        {
            Room tempRoom = this.rooms.Dequeue();
            rooms.Enqueue(tempRoom);
            this.label2.Text = tempRoom.ID.ToString();
            this.label5.Text = tempRoom.name;
            string players = "";
            foreach (string player in tempRoom.players)
            {
                players += player + ",";
            }
            this.label6.Text = players;
        }
        //on joining a room
        private void button2_Click(object sender, EventArgs e)
        {
            update = false;
            thread.Join();
            Program.communicator.Send(new joinRoomMessage(int.Parse(this.label2.Text)), 12);
            GenericResponse response = Program.communicator.Receive();
            if (response.ID != 1)
            {
                throw new Exception("Error joining room");
            }
            Lobby menu = new Lobby();
            this.Hide();
            menu.ShowDialog();
            this.Close();
        }
        static private bool update = true;
        private Thread? thread;
        private void updateThread()
        {
            
            while(JoinRoom.update)
            {
                Thread.Sleep(3000);
                Program.communicator.Send(new Messages(), 9);
                this.rooms = Program.communicator.transform(Program.communicator.Receive());
                foreach (Room room in this.rooms)
                {
                    Program.communicator.Send(new PlayersMessage(room.ID), 10);
                    Queue<string> playerQueue = Program.communicator.transformPlayers(Program.communicator.Receive());
                    room.players = playerQueue;
                }
                Room tempRoom = this.rooms.Dequeue();
                rooms.Enqueue(tempRoom);
                
                string players = "";
                foreach (string player in tempRoom.players)
                {
                    players += player + ",";
                }
                if(!JoinRoom.update)
                {
                    break;
                }
                this.Invoke((MethodInvoker)delegate
                {
                    this.label2.Text = tempRoom.ID.ToString();
                    this.label5.Text = tempRoom.name;
                    this.label6.Text = players;
                });
            }
        }
    }
}
