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
	struct sched_param param;

        int ret = sched_getparam(0,&param);
        param.sched_priority = 12;
        int s=sched_setparam(0,&param);
        int schd=sched_setscheduler(0,SCHED_FIFO,&param);

     	int nice= getpriority(PRIO_PROCESS,0);
        cout<<"Nice: "<< nice<<" Es la prioridad más alta(la mas baja por valor numérico) del proceso. No se heredan los atributos de planificación."<<endl;
        return 1;
}
