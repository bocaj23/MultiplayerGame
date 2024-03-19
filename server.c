#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("usage: %s port\n", argv[0]);
		return 1;
	}

	//vars
	int listenfd, connfd;
	struct sockaddr_in servaddr;
	char send_stream[40960];

	//create socket
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0)
	{
		perror("fatal: SOCKET CREATION ERROR");
		return 1;
	}

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	//socket bind
	if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("fatal: SOCKET BIND FAILED");
		return 1;
	}

	//listen
	if(listen(listenfd, 10) < 0)
	{
		perror("fatal: SOCKET LISTENING FAILED");
		return 1;
	}
	
	while(1)
	{
		//accept connections
		connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
		if (connfd < 0)
		{
			perror("fatal: FAILED TO ACCEPT CONNECTION");
			return 1;
		}

		bzero(send_stream, 40960);
		strcpy(send_stream, "Hello Client! \n\r\0");
		write(connfd, send_stream, strlen(send_stream));

	}
	
}
