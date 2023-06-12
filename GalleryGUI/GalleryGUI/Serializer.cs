using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace GalleryGUI
{
    internal class Serializer
    {
        public Serializer() { }
        public byte[] serialize(object message)
        {
            String json = JsonSerializer.Serialize(message);
            byte[] data = Encoding.ASCII.GetBytes(json);
            return data;
        }
    }
}
