import socket


# config
PORT = 42069
HOST = 'localhost'
MAX_SIZE = 1024
UTF = 'utf-8'
#config end


def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))
    m = b'00000001' + b'0000000000000000000000000000000000101000'
    
    s.send(m + b'0100100001100101011011000110110001101111')
    msg = s.recv(MAX_SIZE)
    print(msg.decode(UTF))

if __name__ == "__main__":
    main()

