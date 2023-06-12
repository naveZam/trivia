using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GalleryGUI
{
    internal class Messages
    {
        
    }

    partial class LoginMessage : Messages
    {
        public string username { get; set; }
        public string password { get; set; }
        public LoginMessage(string username, string password)
        {
            this.username = username;
            this.password = password;
        }
    }
    partial class SignupMessage : Messages
    {
        public string username { get; set; }
        public string password { get; set; }
        public string email { get; set; }
        public SignupMessage(string username, string password, string email)
        {
            this.username = username;
            this.password = password;
            this.email = email;
        }
    }
    partial class Response
    {
        public string data;
        public int ID;
        public Response(string data, int ID)
        {
            this.data = data;
            this.ID = ID;
        }
    }
}
