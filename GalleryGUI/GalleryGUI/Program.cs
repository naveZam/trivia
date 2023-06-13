using System.Net.Sockets;

namespace GalleryGUI
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            communicator = new Communicator();
            ApplicationConfiguration.Initialize();
            Application.Run(new Login());
        }
        public static string? name;
        public static Point location;
        public static Communicator? communicator;
    }
}