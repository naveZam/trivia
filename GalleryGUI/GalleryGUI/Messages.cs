using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json.Serialization;
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

        // Deserialization constructor
        [JsonConstructor]
        public StatsResponse(int ID, int correctAnswerCount, int totalAnswerCount, int totalGames, int averageAnswerTime)
            : base(ID)
        {
            this.correctAnswerCount = correctAnswerCount;
            this.totalAnswerCount = totalAnswerCount;
            this.totalGames = totalGames;
            this.averageAnswerTime = averageAnswerTime;
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
    partial class Room
    {
        public int ID { get; set; }
        public string? name { get; set; }
        public int maxPlayers { get; set; }
        public int timePerQuestion { get; set; }
        public int isActive { get; set; }
        public Queue<string>? players { get; set; }
        public Room(int ID, string name, int maxPlayers, int timePerQuestion, int isActive, Queue<string> players)
        {
            this.ID = ID;
            this.name = name;
            this.maxPlayers = maxPlayers;
            this.timePerQuestion = timePerQuestion;
            this.isActive = isActive;
            this.players = players;
        }
        public Room()
        {

        }
    }
}

