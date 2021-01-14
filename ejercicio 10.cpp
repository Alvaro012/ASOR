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
	pid_t pid;
        pid=fork();
        cout<<getpid()<<endl;
        sleep(600);
        cout<<"El proceso responde a las llamadas de kill desde la otra terminal. P.ej, se termina si ejecuto :kill 'pid' 3"<<endl; 
        return 0;
}
