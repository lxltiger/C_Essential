#include "common.h"


int main(int argc, char const *argv[])
{
	
	if (argc != 3) {
		fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
		exit(0);
    }
    char *host,*port,buf[MAXLINE];
    int clientfd;
    rio_t rio;
    host=argv[1];
    port=argv[2];

    clientfd=Open_clientfd(host,port);
    Rio_readinitb(&rio,clientfd);

    while(Fgets(buf,MAXLINE,stdin)!=NULL){
    	Rio_writen(clientfd,buf,strlen(buf));
    	Rio_readlineb(&rio,buf,MAXLINE);
    	Fputs(buf,stdout);
    }
    Close(clientfd);
    exit(0);

	return 0;
}