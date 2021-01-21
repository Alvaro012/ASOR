
#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<errno.h>

using namespace std;

int main(int argc, char *argv[]){
        struct addrinfo hints;
        struct addrinfo *resultado;

        memset(&hints,0,sizeof(struct addrinfo));
        hints.ai_flags = AI_PASSIVE;
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;

        int status = getaddrinfo(argv[1],argv[2],&hints,&resultado);
        if (status != 0){
                perror("getaddrinfo");
        }
	for (struct addrinfo * i = resultado; i!=NULL;i=i->ai_next) {
                char host[NI_MAXHOST];
                char serv[NI_MAXSERV];

                getnameinfo(i->ai_addr,i->ai_addrlen,host,NI_MAXHOST,serv,NI_MAXSERV,NI_NUMERICHOST | NI_NUMERICSERV);
                cout<<host<<" "<<i->ai_family<<" "<<i->ai_socktype <<endl;
        }
	freeaddrinfo(resultado);
        return 0;
}



