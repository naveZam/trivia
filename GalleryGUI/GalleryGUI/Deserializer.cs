using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GalleryGUI
{
    internal class Deserializer
    {
        public Deserializer() { }
        public string deserialize(byte[] data)
        {
            string str = Encoding.ASCII.GetString(data);
            return str;
            
        }
    }
}
