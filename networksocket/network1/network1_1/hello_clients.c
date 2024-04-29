#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
void error_handling(char *message);
int main(int argc,char*argv[])
{
	int sock;
	struct sockaddr_in serv_addr;
	int str_len;

	if(argc!=3) {
		printf("Usage:%s <IP><port>\n",argv[0]);
		exit(1);
	}
	sock=socket(PF_INET,SOCK_STREAM,0);
	if(sock ==-1)
		error_handling("socket()error");

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));

	if(connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
		error_handling("connect()error!");
	char buffer[32] = {0};
	char message[32] = {0};
	int count = 0;
	while(count < 10) {
		printf("1\n");
		count++;
		memset(buffer,0,32);
		printf("2\n");
		sprintf(buffer,"message:%d",count);
		printf("3\n");
		write(sock,buffer,sizeof(buffer));
		printf("4\n");
		usleep(1000*500);
		printf("5\n");
		memset(message,0,32);
		printf("6\n");
		str_len=read(sock,message,32);
		if(str_len==-1) {
			error_handling("read()error!");
		}
		printf("Message from server:%s \n",message);
	}
	close(sock);
	return 0;
}
void error_handling(char *message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}
