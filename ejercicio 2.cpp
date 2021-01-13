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
