#include "common.h"

void echo(int connfd);

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
    }

    int listenfd,connfd;
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;/*可以容纳任何类型地址*/
    char client_hostname[MAXLINE],client_port[MAXLINE];

    listenfd=Open_listenfd(argv[1]);
    while(1){
    	clientlen=sizeof(struct sockaddr_storage);
    	connfd=Accept(listenfd,(SA *)&clientaddr,&clientlen);
    	Getnameinfo((SA *)&clientaddr,clientlen,client_hostname,MAXLINE,client_port,MAXLINE,0);
        printf("Connected to (%s, %s)\n", client_hostname, client_port);
        echo(connfd);
        Close(connfd);
    }
	exit(0);
}