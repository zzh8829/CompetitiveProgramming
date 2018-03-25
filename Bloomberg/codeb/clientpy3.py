import socket
import sys

def run(user, password, *commands):
    HOST, PORT = "codebb.cloudapp.net", 17429

    
    data=user + " " + password + "\n" + "\n".join(commands) + "\nCLOSE_CONNECTION\n"

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:

        sock.connect((HOST, PORT))
        sock.sendall(bytes(data, "utf-8"))
        sfile = sock.makefile()
        rline = sfile.readline()
        while rline:
            print(rline.strip())
            rline = sfile.readline()

def run1(user, password, command):
	HOST, PORT = "codebb.cloudapp.net", 17429
	data = user = " " + password + "\n" + command + "\nCLOSE_CONNECTION\n"


def subscribe(user, password):
    HOST, PORT = "codebb.cloudapp.net", 17429
    
    data=user + " " + password + "\nSUBSCRIBE\n"

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:

        sock.connect((HOST, PORT))
        sock.sendall(bytes(data, "utf-8"))
        sfile = sock.makefile()
        rline = sfile.readline()
        while rline:
            print(rline.strip())
            rline = sfile.readline()

if __name__ == '__main__':
	while(True):
		a = input()
		if a == "Q":
			break
		else if a == "S":
			run("AlgoHouse","azmczz",a)
