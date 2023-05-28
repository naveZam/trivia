import socket
import time

# config
PORT = 42069
HOST = 'localhost'
MAX_SIZE = 1024
UTF = 'utf-8'
#config end


def main():
    signup = '{"username": "user1", "password": "1234", "mail": "user1@gmail.com"}'
    login = '{"username": "user1", "password": "1234"}'
    login2 = '{"username": "user2", "password": "1234"}'

    #get the len of the signup and make it 5 bytes and in binary fill with 0 to the left
    SignupLen = str(len(signup))
    SignupLen = SignupLen.zfill(5)


    #get the len of the binLogin and make it 5 bytes and in binary
    LoginLen = str(len(login))
    LoginLen = LoginLen.zfill(5)
    
    #get the len of the binLogin and make it 5 bytes and in binary
    LoginLen2 = str(len(login2))
    LoginLen2 = LoginLen2.zfill(5)
    

    signupmsg = '2' + SignupLen + signup
    loginmsg = '1' + LoginLen + login
    loginmsg2 = '1' + LoginLen2 + login2
    
    print(signupmsg)

    #two login message same convo
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))
    s.sendall(signupmsg.encode())
    data = s.recv(MAX_SIZE)
    print('Received', repr(data))
    s.sendall(loginmsg.encode())
    data = s.recv(MAX_SIZE)
    print('Received', repr(data))
    s.close()
    
    #try two times same login
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)   
    s.connect((HOST, PORT))
    s.sendall(signupmsg.encode())
    data = s.recv(MAX_SIZE)
    print('Received', repr(data))
    s.close()
    
    #non-existent user
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)   
    s.connect((HOST, PORT))
    s.sendall(loginmsg2.encode())
    data = s.recv(MAX_SIZE)
    print('Received', repr(data))
    s.close()



if __name__ == "__main__":
    main()
