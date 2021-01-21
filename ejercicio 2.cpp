
#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<errno.h>
#include<arpa/inet.h>

using namespace std;

int main(int argc, char *argv[]){
        struct addrinfo hints;
        struct addrinfo *resultado;
        struct sockaddr_in addr;
        int sd,c;
        char buf[1024];

        memset(&hints,0,sizeof(struct addrinfo));
        hints.ai_flags = AI_PASSIVE;
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;

        int rc = getaddrinfo(argv[1],argv[2],&hints,&resultado);
        if((sd = socket(resultado->ai_family,resultado->ai_socktype,0)< 0)){
                perror("socket creation failed");
                exit(EXIT_FAILURE);
        }
	if(bind(sd,(struct sockaddr *) resultado->ai_addr,resultado->ai_addrlen) < 0){
                perror("bind failed");
                exit(EXIT_FAILURE);
        }

	while(1){
                char host[NI_MAXHOST];
                char serv[NI_MAXSERV];

                struct sockaddr_storage addr;
                socklen_t addrlen = sizeof(addr);

                c = recvfrom(sd,buf,80,0,(struct sockaddr *) &addr,&addrlen);
                buf[c] = '\0';
                getnameinfo((struct sockaddr *) &addr,addrlen,host,NI_MAXHOST,serv,NI_MAXSERV,NI_NUMERICHOST|NI_NUMERICSERV);
                cout<<"Host: "<<host<<"Server: "<<serv<<"Buf: "<<buf<<endl;
                sendto(sd,buf,c,0,(struct sockaddr *) &addr,addrlen);
        }
	freeaddrinfo(resultado);
        return 0;
}





