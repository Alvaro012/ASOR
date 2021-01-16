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

using namespace std;

void borrarfichero(int);
void time_handler(int);
int main(){
        borrarfichero(5);
        return 0;
}
void time_handler(int signum){
        cout<<"Entró"<<endl;
}

void borrarfichero(int segundos){
        sigset_t sigset;
        struct itimerval itv;

        struct sigaction sa;
        memset(&sa,0,sizeof(sa));
        sa.sa_handler = &time_handler;
        if(sigaction (SIGUSR1,&sa,NULL)){
		sigsuspend(&sigset);
	}
        kill(0,SIGUSR1);
        itv.it_value.tv_sec  = 10;
        itv.it_value.tv_usec = 0;
        itv.it_interval.tv_sec  = segundos;
        itv.it_interval.tv_usec = 0;
        setitimer(ITIMER_REAL,&itv,NULL);
        while(1);
        int i= system("rm ejercicio.cpp");
}

