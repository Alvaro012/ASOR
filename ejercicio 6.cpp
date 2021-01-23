
#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<errno.h>
#include<arpa/inet.h>
#include<sys/select.h>
#include<netinet/in.h>
#include<unistd.h>


using namespace std;

int main(int argc, char *argv[]){
        struct addrinfo hints;
        struct addrinfo *resultado;
        struct sockaddr_in addr;
        int sd,clisd,c;
        char *buf[1024];

        memset(&hints,0,sizeof(struct addrinfo));
        hints.ai_flags = AI_PASSIVE;
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;

        int rc= getaddrinfo(argv[1],argv[2],&hints,&resultado);
        sd = socket(resultado->ai_family,resultado->ai_socktype,0);
        bind(sd,(struct sockaddr *) resultado->ai_addr,resultado->ai_addrlen);
        listen(sd,5);

        while(1){
                char host[NI_MAXHOST];
                char serv[NI_MAXSERV];

                struct sockaddr_storage addr;
                socklen_t addrlen = sizeof(addr);

                clisd = accept(sd,(struct sockaddr *) &addr,&addrlen);
                getnameinfo((struct sockaddr *) &addr,addrlen,host,NI_MAXHOST,serv,NI_MAXSERV,NI_NUMERICHOST|NI_NUMERICSERV);
		cout<< "Conexión desde host: "<<host<<" Puerto: "<< serv<<endl;
                while(c=recv(clisd,buf,80,0)){
                        buf[c] = '\0';
			send(clisd,buf,c,0);
                }
                close(clisd);
        }
        return 0;
}



