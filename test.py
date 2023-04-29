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
    s.send(b'Hello, world!')
    msg = s.recv(MAX_SIZE)
    print(msg.decode(UTF))

if __name__ == "__main__":
    main()

