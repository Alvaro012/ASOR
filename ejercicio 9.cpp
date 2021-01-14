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
	int man = system("man kill");
        int pman= system("man pkill");
	return 0;

}
