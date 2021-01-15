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
	struct sigaction accion;
        int secs = putenv("SLEEP_SECS");
        sigset_t blk_set;
        sigemptyset(&blk_set);

        sigaddset(&blk_set,SIGINT);
        sigaddset(&blk_set, SIGTSTP);
        sigprocmask(SIG_BLOCK,&blk_set, NULL); //bloquea las señales
        sleep(secs);

        if(sigaction (SIGINT, NULL, &accion)!= -1 || sigaction (SIGTSTP, NULL, $
                sigprocmask(SIG_UNBLOCK,&blk_set,NULL);
                cout<<"Señales desbloqueadas"<<endl;
  	}
	else cout<<"Señales no desbloqueadas"<<endl;

        return 0;
}
