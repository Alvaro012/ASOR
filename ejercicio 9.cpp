
include<iostream>
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
#include<signal.h>

using namespace std;

void sigchld_handler(int s){
        while (wait(NULL) > 0);
}
int main(int argc, char *argv[]){
        struct addrinfo hints;
        struct addrinfo *resultado;
        struct sockaddr_in addr;
        int sd,clisd,c,pid;
        char buf[1024];
        struct sigaction sa;
        sa.sa_handler = sigchld_handler;

        sigemptyset(&sa.sa_mask);
        sa.sa_flags = SA_RESTART;

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
                if((pid = fork()) == -1){
                        close(clisd);
                }
                else if(pid>0){
                        close(clisd);
                        cout<<"Here"<<endl;
                        if(signal(SIGCHLD,sigchld_handler))
                                exit(1);
                }
                else if(pid == 0){
                getnameinfo((struct sockaddr *) &addr,addrlen,host,NI_MAXHOST,serv,NI_MAXSERV,NI_NUMER$
                cout<< "Conexión desde host: "<<host<<" Puerto: "<< serv<<endl;
                while(c=recv(clisd,buf,80,0)){
                             buf[c] = '\0';
                        send(clisd,buf,c,0);
                }
                close(clisd);
                if(signal(SIGCHLD,sigchld_handler))
                         exit(1);
		}
	}
	return 0;
}

