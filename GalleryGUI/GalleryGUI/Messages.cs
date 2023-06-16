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
        public int ID { get; set; }
        public Response(int ID)
        {
            this.ID = ID;
        }
    }
    partial class StatsResponse : Response
    {
        public int correctAnswerCount { get; set; }
        public int totalAnswerCount { get; set; }
        public int totalGames { get; set; }
        public int averageAnswerTime { get; set; }

        public StatsResponse(int ID, int correct, int total, int games, int time) : base(ID)
        {
            this.correctAnswerCount = correct;
            this.totalAnswerCount = total;
            this.totalGames = games;
            this.averageAnswerTime = time;
        }
    }
    partial class GenericResponse : Response
    {
        public string message { get; set; }
        public GenericResponse(int ID, string message) : base(ID)
        {
            this.message = message;
        }
    }
}

