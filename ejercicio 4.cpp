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
        int fd = 0;
        if((fd = open("/root/fifo.txt",O_WRONLY)) < 0)
                cout <<"error"<<endl;
        else write(fd,"Hello World!",12);
        return 0;
}


