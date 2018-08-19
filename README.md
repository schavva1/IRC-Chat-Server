# IRC-Chat-Server
  Steps to run the code:

Server Side:
	1.Compile the program -> gcc -o server server.c
	2.Run the program by giving port number in command line -> ./server 4020
	3.Example output:
		schavva1@remote04:~/CS528$ gcc -o server server.c
		schavva1@remote04:~/CS528$ ./server 4020
		-socket created
		-Listening
		-Accepted connection to client port:4020
		-Message from client: hi
		-Write a message to client:
			hello
		-Message from client: how r u
		-Write a message to client:
			good




		
	
	
Client Side:
	1.Compile the program-> gcc -o client client.c
	2.Run the program by giving IP address and port number in command line -> ./client 128.226.180.166 4020
	3.Example output:
		schavva1@remote06:~/CS528$ gcc -o client client.c
		schavva1@remote06:~/CS528$ ./client 128.226.180.166 4020
		-socket created
		-client connected with IPADDRESS and PORT:128.226.180.166  4020
		-Write a message:hi
	 	 Message being sent
		-Message from server: hello

		-Write a message:how r u
	  	Message being sent
		-Message from server: good

		-Write a message:
