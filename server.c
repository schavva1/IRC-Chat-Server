#include<stdio.h>														
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h> 
#include<string.h>
#include <unistd.h>  
#include<arpa/inet.h>
//#define PORT 8080
int main(int argc, char *argv[])
{
											      														
	int server_fd,new_socket,n,portno;
	char buffer[256];
	struct sockaddr_in serv_info;
	if(argc < 2)
	{
		printf("error!! provide port number \n");
		exit(1);
	}
	

	if((server_fd = socket(AF_INET, SOCK_STREAM,0)) < 0)								       //internet address, TCP
	{
		printf("socket cannot be created");
		return 0;
	}
	else 
	{
		printf("-socket created \n");
	}
	memset(&serv_info,'0',sizeof(serv_info)); 
	portno = atoi(argv[1]);
	serv_info.sin_family = AF_INET;
	serv_info.sin_port = htons(portno);            						                             							  		     
 	serv_info.sin_addr.s_addr = htonl(INADDR_ANY);	
 	bind(server_fd,(struct sockaddr *)&serv_info, sizeof(serv_info));
	
	/*if(bind(server_fd,(struct sockaddr *)&serv_info, sizeof(serv_info)) < 0)
	{
		printf("cannot bind \n");
		exit(1);
	}
	else 
	{
		printf("-socket binded to port %s \n",argv[1]);
	}*/

	if(listen(server_fd,5) < 0)											 	// 5:number of clients you can handle	
			{
				printf("listen failed \n");
			}
	else 
			{
				printf("-Listening \n");
			}
		
	new_socket = accept(server_fd,(struct sockaddr *)NULL,NULL);						//change here length
	if(new_socket < 0)
			{
				printf("accept failed \n");
			}
	else
			{
				printf ("-Server Accepted connection to client on port:%d \n",portno);
			}
	while(1)
			{
				bzero(buffer,256);
	
				if(read(new_socket,buffer,255) < 0)
				{
					printf("error reading from socket \n");
				}
				printf("-Message from client: %s",buffer);
				bzero(buffer,256);
				printf("-Write a message to client:");
				fgets(buffer,255,stdin);
	
				n = write(new_socket,buffer,strlen(buffer));	
				if(n < 0)
				{
					printf("Error writing to socket \n");
				}
				//printf("-%s sent to client \n",buffer);
				sleep(1);
		    }
  close(server_fd);
	return 0;	
}
