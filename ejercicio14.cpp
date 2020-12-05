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
        rawtime = time(0);
        timeinfo = localtime(&rawtime);
        cout<<"Año: "<<timeinfo->tm_year + 1900<<endl;
        return 1;
}
  




