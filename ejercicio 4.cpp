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
	int man = system("man ps");
        int a = system("ps -l");
        int b = system("ps -eo pid,pgrp,session,stat,args");
        cout<<"El id grupo al crear un nuevo proceso es 3361. Los id que comparten la shell y los programas que se ejecutan son 1,460,481... Menores que 3361"<<endl; 
        return 1;
}
