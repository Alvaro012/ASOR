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
	size_t size = 1024;
        char buffer[size];
        int pid=fork();
        if (pid == 0){
        cout<<"ID proceso: "<<getpid()<<endl;
        cout<<"ID proceso padre: "<<getppid()<<endl;
        cout<<"ID grupo procesos: "<<getpgid(0)<<endl;
        cout<<"ID sesión: "<<getsid(0)<<endl;
        }
	int numficheros = system("cat /proc/sys/fs/file-max");
        cout<< getcwd(buffer,size)<<endl;
        return 1;

}
