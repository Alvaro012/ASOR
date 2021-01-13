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
        //int c= system("man chrt");
        //int n= system("man nice");
        //int r=system("man renice");

        int nice_antes= getpriority(PRIO_PROCESS,0);
        cout<<"Nice antes: "<< nice_antes<<endl;
        int nice_nuevo=setpriority(PRIO_PROCESS,0,-10);
        int nice= getpriority(PRIO_PROCESS,0);
        cout<<"Nice ahora: "<<nice<<endl;

        int ret = sched_getparam(0,&param);
        param.sched_priority = 12;
        int s=sched_setparam(0,&param);
        int schd=sched_setscheduler(0,SCHED_FIFO,&param);
        int policy = sched_getscheduler(0);
	    if(schd ==-1)
        perror("sched_setscheduler");
        return 1;
}
