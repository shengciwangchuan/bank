

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <time.h>
#include <fcntl.h>
#include <stdbool.h>
#include <pthread.h>
#define rtsp_setsocknonblock(s) \
{	\
	int __opts; \
	__opts = fcntl((int)s, F_GETFL); \
	__opts = (__opts | O_NONBLOCK); \
	fcntl((int)s, F_SETFL, __opts); \
}
void error_handling(char *message);

int main(int argc, char *argv[])
{	int serv_sock;
	int clnt_sock;
	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;
	int str_len;
	

	if(argc!=2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	serv_sock=socket(PF_INET,SOCK_STREAM,0);
	if(serv_sock ==-1)
		error_handling("socket()error");

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(atoi(argv[1]));
	if(bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
		error_handling("bind()error");

	if(listen(serv_sock,5)==-1)
		error_handling("listen()error");

	rtsp_setsocknonblock(serv_sock);

	char message[32]={0};
	while(1) {
		clnt_addr_size=sizeof(clnt_addr);
		memset(&clnt_addr,0,sizeof(clnt_addr));
		usleep(1000*200);
		clnt_sock=accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_addr_size);
		if(clnt_sock <0){
			continue;
		}
		printf("clnt_sock:%d\n",clnt_sock);

		memset(message,0,32);
		str_len=read(clnt_sock,message,32);
		if(str_len==-1) {
			error_handling("read()error!");
		}
		write(clnt_sock,message,sizeof(message));
	}
	close(clnt_sock);
	close(serv_sock);
	return 0;
}
void error_handling(char *message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);

}