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
	int dir = chdir("/tmp");
        pid_t pid;
        pid = fork();
        setsid();
        switch (pid) {
               case -1:
                perror("Fork");
                exit(1);

               case 0:
                //sleep(3);
                cout<<"Hijo"<<endl;
                cout<<"ID proceso: "<<getpid()<<endl;
                cout<<"ID proceso padre: "<<getppid()<<endl;
                cout<<"ID grupo procesos: "<<getpgid(0)<<endl;
		break;

               default:
                sleep(3);
                cout<<"Padre"<<endl;
                cout<<"ID proceso: "<<getpid()<<endl;
                cout<<"ID proceso padre: "<<getppid()<<endl;
                cout<<"ID grupo procesos: "<<getpgid(0)<<endl;
                cout<<"ID sesión: "<<getsid(0)<<endl;
		break;
        }
	//int i=system("ps -eo pid,stat");
	cout<<"Si el padre termina antes, el PPID del hijo se pone a 1 en vez de al ID del proceso padre. En caso contrario, el proceso hijo se convierte en lider de sesion (Ss con ps)."
        return 0;

}
