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

        int nice_antes= getpriority(PRIO_PROCESS,0);
        cout<<"Nice antes: "<< nice_antes<<endl;
        int nice_nuevo=setpriority(PRIO_PROCESS,0,-10);
        int nice= getpriority(PRIO_PROCESS,0);
        cout<<"Nice ahora: "<<nice<<endl;

        int ret = sched_getparam(0,&param);
        param.sched_priority = 12;
        int s=sched_setparam(0,&param);
        int schd=sched_setscheduler(0,SCHED_FIFO,&param);
     	
	int policy=sched_getscheduler(0);
        switch(policy) {
         case SCHED_OTHER: cout<<"SCHED_OTHER"<<endl; break;
         case SCHED_RR:    cout<<"SCHED_RR"<<endl; break;
         case SCHED_FIFO:  cout<<"SCHED_FIFO"<<endl; break;
        default:   cout<<"Unknown..."<<endl;
          }
	cout << sched_get_priority_min(policy)<<endl;
        cout << sched_get_priority_max(policy)<<endl;

        return 1;
}
