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
       int main(int argc, char *argv[]){
        int status;
        status=mkfifo("/root/fifo2.txt",S_IRWXU | S_IRWXG | S_IROTH);
        char buffer[256];
        timeval timeout;

        timeout.tv_sec = 2;
        timeout.tv_usec = 0;

        int fd = open("/root/fifo2.txt",O_WRONLY| O_NONBLOCK);
        fd_set fds;

        FD_ZERO(&fds);
        FD_SET(fd,&fds);

        int cambios = select(1,&fds,NULL,NULL,&timeout);
        if (cambios==-1)
                perror("select()");
        else if(cambios){
                read(0,buffer,80);
                close(status);
                open("/root/fifo2.txt",O_WRONLY| O_NONBLOCK);
                cout<<"Datos nuevos: "<<buffer<<endl;
        }
        else  cout<<"Ningún dato nuevo"<<endl;
        return 0;
}




