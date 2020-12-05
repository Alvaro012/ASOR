#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
	time_t hora = time(NULL);
        cout<<"Hora en segundos: "<< hora<<endl;
        return 1;
}




