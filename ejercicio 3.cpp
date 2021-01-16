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
#include<fcntl.h>
#include<sys/select.h>
#include<fstream>
#include<sys/stat.h>

using namespace std;

int main(int argc, char *argv[]){
        int status;
        status=mkfifo("/root/fifo.txt",S_IRWXU | S_IRWXG | S_IROTH);
        int stat=system("stat fifo.txt");
        return 0;
}


