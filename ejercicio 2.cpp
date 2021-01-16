#include<iostream>
#include<sched.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<errno.h>
#include<fcntl.h>
#include<signal.h>
#include<string.h>
#include<fcntl.h>
#include<sys/select.h>
#include<fstream>

using namespace std;
#define SIZE 512
int main(int argc, char *argv[]){
        int h_p[2];
        int p_h[2];
        int readbytes;
        char buffer[SIZE];
        string line;

        char *cmd1[] = {argv[1], argv[2], NULL};
        char *cmd2[] = {argv[4], argv[5],NULL};

        pipe(p_h);
        pipe(h_p);
        pid_t pid = fork();
        if(pid == -1)
                perror("Fork");
         else if (pid >0) {
                close(p_h[0]);
                close(h_p[1]);

                while(readbytes=getline(cmd1,line) > 0)
                        write(1,buffer,readbytes);

                write(p_h[1],buffer,strlen(buffer));
                close(p_h[1]);
	while( (readbytes=getline(h_p[0],line) > 0){
                        write( 1, buffer, readbytes );
                        if(buffer == "l"){
                                cout<<"Llegó la 'l'"<<endl;
                        }
                        else if(buffer == "q") exit(1);
                }
                close( h_p[0]);
        }
	else if(pid==0){
                close(p_h[1]);
                close(h_p[0]);

                while(readbytes=getline(p_h[0],line) >0){
                        write(1,buffer,readbytes);
                        cout<<buffer<<endl;
                        sleep(1);
                }
                for(int i= 0;i<10;i++)
                        write(h_p[1],"l",SIZE);
                write(h_p[1],"q",SIZE);
                close(h_p[1]);
        }
 return 0;
}
