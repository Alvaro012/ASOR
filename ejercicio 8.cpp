#include<iostream>
#include<sched.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
#include<sys/resource.h>

using namespace std;

int main(){
	char *command = "ls";
        char *arg[3] = {"ls","-l",NULL};
        pid_t pid;
        pid = fork();
        int x;
        setsid();
        int file_desc = open("/tmp/daemon.err",O_WRONLY | O_APPEND);
        int file_desc2 = open("/tmp/daemon.out",O_WRONLY | O_APPEND);
         switch (pid) {
               case -1:
                perror("Fork");
                dup2(file_desc,1);
                exit(1);
                break;
		case 0:
                x = execvp(command,arg);
                if (x == -1){
                perror("Execvp");
                return 1;
                 }
                else cout<<"Antes de ejecutar execpv"<<endl;
                dup2(file_desc2,1);
                exit(1);
                break;

                default:
                break;
	}
	return 0;

}
