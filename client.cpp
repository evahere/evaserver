#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 100


int main()
{

	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(9999);

	char buffer[BUF_SIZE] = {0};

	while(1)
	{

		int sock = socket(AF_INET, SOCK_STREAM, 0);
		connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
		printf("Input a string: ");
		fgets(buffer, BUF_SIZE, stdin);
		write(sock, buffer, strlen(buffer));

		read(sock, buffer, BUF_SIZE);
		printf("Message from server: %s\n", buffer);
		memset(buffer, 0, BUF_SIZE);

		close(sock);
	}

	return 0;


}



