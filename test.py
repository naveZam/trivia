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
    #convert the signup and login to binary with 8 bits per byte
    binSignup = ''.join('{0:08b}'.format(ord(x), 'b') for x in signup)
    binLogin = ''.join('{0:08b}'.format(ord(x), 'b') for x in login)
    binLogin2 = ''.join('{0:08b}'.format(ord(x), 'b') for x in login2)

    #get the len of the binSignup and make it 5 bytes and in binary fill with 0 to the left
    binSignupLen = len(binSignup)
    binSignupLen = bin(binSignupLen)
    binSignupLen = binSignupLen[2:]
    binSignupLen = binSignupLen.zfill(5 * 8)


    #get the len of the binLogin and make it 5 bytes and in binary
    binLoginLen = len(binLogin)
    binLoginLen = bin(binLoginLen)
    binLoginLen = binLoginLen[2:]
    binLoginLen = binLoginLen.zfill(5 * 8)
    
    #get the len of the binLogin and make it 5 bytes and in binary
    binLoginLen2 = len(binLogin2)
    binLoginLen2 = bin(binLoginLen2)
    binLoginLen2 = binLoginLen2[2:]
    binLoginLen2 = binLoginLen2.zfill(5 * 8)



    loginmsg = '00000001'+binLoginLen + binLogin
    signupmsg = '00000010'+binSignupLen + binSignup
    loginmsg2 = '00000001'+binLoginLen2 + binLogin2


    #two login message same convo
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))
    s.sendall(bytes(signupmsg, UTF))
    data = s.recv(MAX_SIZE)
    print('Received', repr(data))
    s.sendall(bytes(loginmsg, UTF))
    data = s.recv(MAX_SIZE)
    print('Received', repr(data))
    s.close()
    
    #try two times same signup
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)   
    s.connect((HOST, PORT))
    s.sendall(bytes(signupmsg, UTF))
    data = s.recv(MAX_SIZE)
    print('Received', repr(data))
    s.close()
    
    #non-existent user
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)   
    s.connect((HOST, PORT))
    s.sendall(bytes(signupmsg, UTF))
    data = s.recv(MAX_SIZE)
    print('Received', repr(data))
    s.close()



if __name__ == "__main__":
    main()