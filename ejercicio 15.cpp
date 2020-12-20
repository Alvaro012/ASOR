#include <sys/types.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>

using namespace std;

int main(){
	time_t rawtime;
        struct tm *timeinfo;
        char buffer [80];
        rawtime = time(0);
	timeinfo = localtime(&rawtime);
        setlocale(LC_ALL,NULL);
        strftime (buffer,80," %r",timeinfo);
        int fd = open("fichero",O_WRONLY | O_APPEND);
        if (lockf(fd,F_ULOCK,0)== -1){
                cout<<"Fichero no está lock"<<endl;
                lockf(fd,F_LOCK,0);
                cout<<buffer<<endl;
                sleep(30);
                lockf(fd,F_ULOCK,0);	
}
else{
     	cout<<"Fichero está lock"<<endl;
}
 return 1;
}


