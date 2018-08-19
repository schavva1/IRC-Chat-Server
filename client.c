#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<string.h>									
#include<netinet/in.h> 
#include<netdb.h>     
#include <unistd.h>     
#include <arpa/inet.h>           					  		

int main(int argc, char *argv[])                                                  		
{
	int fd,msg_read,portno;
	char buffer[256];
	struct sockaddr_in serv_info;
	//struct hostent *server;
	//socklen_t client_length;
	if(argc < 3)								       		//./clientout localhost(or IP addr) portnumber
	{
		printf("-error!! provide IPaddress and port number \n");
		exit(1);
	}
	portno = atoi(argv[2]);
	memset(buffer, '0',sizeof(buffer));      									  		
	fd = socket(AF_INET, SOCK_STREAM,0);
 	if(fd < 0)
	{
		perror("socket cannot be created \n");
		return 0;
		
	}
	else 
	{
		printf("-socket created \n");
	}
	//server = gethostbyname(argv[1]);
	//printf(" ssss is %d \n",server);
	/*if(server == NULL)
	{
		printf("cannot get server name");
	}*/
	
	memset(&serv_info,'0',sizeof(serv_info));              			 
	serv_info.sin_family = AF_INET;
	serv_info.sin_port = htons(portno);                     			 		//htons converts a short integer (e.g. port) to a network representation 
	//serv_info.sin_addr.s_addr = htonl(argv[1]);	
	if (inet_pton(AF_INET,argv[1], &serv_info.sin_addr) <= 0)
	{
		printf("error occured \n");
		exit(1);
	}
	
	//memcopy((void *)&serv_info.sin_addr, server->h_addr_list[0], server->length);
	//memcpy((char *)server->h_addr,(char *)&serv_info.sin_addr.s_addr,server->h_length);
	
	if(connect(fd,(struct sockaddr *)&serv_info, sizeof(serv_info)) < 0)
			{
				printf("connection failed to server at PORT: %d \n",portno);
				return 0;
			}
	else
			{
				printf("- client connected with IPADDRESS and PORT:%s  %d \n",argv[1],portno);
			}
			
	
	while(1)
			{
				printf("-Write a message:");
				bzero(buffer,256);
				fgets(buffer,255,stdin);
	
				if(send(fd, buffer,strlen(buffer),0) < 0)
				{
					printf("error sending message \n");
				}
				else
				{
					printf("  Message being sent \n");
				}
				bzero(buffer,256);
				msg_read = read(fd,buffer,255);
				if(msg_read < 0)
				{
					printf("error reading from socket");
				}
				printf("-Message from server: %s \n",buffer);
			//close(fd);  
	      }
  close(fd);
	return 0;
}

