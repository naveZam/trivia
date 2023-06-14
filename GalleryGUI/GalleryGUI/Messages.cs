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
        public int NumOfCorrectAnswers { get; set; }
        public int NumOfTotalAnswers { get; set; }
        public int getNumOfPlayerGames { get; set; }
        
        public StatsResponse(int ID, int correct, int total, int games) : base(ID)
        {
            this.NumOfCorrectAnswers = correct;
            this.NumOfTotalAnswers = total;
            this.getNumOfPlayerGames = games;
        }
    }
}
