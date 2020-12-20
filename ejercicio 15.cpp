#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
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
        strftime (buffer,80,"%A,%d de %B de %Y, %H:%M",timeinfo);
  	cout<<"Fecha es: "<<buffer<<endl;
        return 1;
}

