#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "src/packet.h"

int main (int argc, char *argv[])
{

	if (argc != 3)
	{
		printf("Usage: %s server_ip port", argv[0]);
		return 1;
	}

	int sockfd;
	struct sockaddr_in servaddr;
	char recv_stream[40960];
	
	//create socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		perror("fatal: SOCKET CREATION FAILED");
		return 1;
	}

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));

	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
	{
		perror("fatal: INVALID IP ADDRESS OR SERVER IS NOT RUNNING");
		return 1;
	}

	if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("fatal: SOCKET CONNECTION FAILED");
		return 1;
	}
	/*else
	{
		printf("Connection established. Pinging server...");

		
		 * Create ping packet
		 * create timer
		 * send ping packet
		 * recieve returning ping packet
		 * print out the time taken
		

		Packet init_pkt = pkt_create(PING);	

		printf("[PING][CLIENT_ID] time_taken_in_ms");
	}*/

	
	int n;
	while(n = read(sockfd, recv_stream, sizeof(recv_stream)) > 0)
	{
		printf("%s", recv_stream);
	} 


}
