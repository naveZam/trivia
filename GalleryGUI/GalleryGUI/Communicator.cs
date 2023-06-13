using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Text.Json;
using System.Text.Json.Serialization;
namespace GalleryGUI
{
    internal class Communicator
    {
        public Communicator()
        {
            socket = new Socket(SocketType.Stream, ProtocolType.Tcp);
            socket.Connect(ip, port);
            deserializer = new Deserializer();
            serializer = new Serializer();
        }
        private Socket socket;
        private string ip = "127.0.0.1";
        private int port = 42069;
        private Deserializer deserializer;
        private Serializer serializer;
        public Response Receive()
        {
            byte[] buffer = new byte[1024];
            //wait for data
            int received;
            do
            {
            } while ((received = socket.Receive(buffer)) == 0);

            byte[] data = new byte[received];
            Array.Copy(buffer, data, received);
            int ID = data[0];
            byte[] length = new byte[5];
            Array.Copy(data, 1, length, 0, 5);
            int len = BitConverter.ToInt32(length, 0);
            byte[] message = new byte[len];
            Array.Copy(data, 6, message, 0, len);
            string str = deserializer.deserialize(message);
            Response response = new Response(str, ID);
            return response;
        }
        public void Send(Messages message, int ID)
        {
            byte[] data = serializer.serialize(message);
            byte[] length = new byte[5];
            byte[] temp = BitConverter.GetBytes(data.Length);
            Array.Copy(temp, length, temp.Length);
            byte[] SendData = new byte[data.Length + 6];
            SendData[0] = (byte)ID;
            Array.Copy(length, 0, SendData, 1, 5);
            Array.Copy(data, 0, SendData, 6, data.Length);
            socket.Send(SendData);
        }
    }
    
}
