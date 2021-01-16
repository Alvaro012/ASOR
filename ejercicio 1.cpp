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

using namespace std;

int main(int argc, char *argv[]){
        if (argc < 6){
                cout<<"Uso: comando1 argumento1 | comando2 argumento2"<<endl;
                exit(EXIT_FAILURE);
        }
	int fd[2]; //fd[0] es lectura, fd[1] es escritura
        int res1,res2;
        char *cmd1[] = {argv[1], argv[2], NULL};
        char *cmd2[] = {argv[4], argv[5],NULL};

        pipe(fd);
        pid_t pid = fork();
        if(pid == -1)
                perror("Fork");
        else if (pid >0) {
                close(fd[1]);
                dup2(fd[0],0);
                res1 = execvp(cmd1[0],cmd1);
                if(res1==-1)perror ("execvpPadre");
        }
	else if(pid==0){
                close(fd[0]);
                dup2(fd[1],1);
                res2 = execvp(cmd2[0],cmd2);
                if (res2==-1) perror("execvpHijo");
        }
	return 0;
}

