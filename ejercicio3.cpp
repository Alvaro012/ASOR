#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <errno.h>

using namespace std;

int main(){
	for (errno=0;errno<=255;errno++){
        cout<< "Error "<< *strerror(errno)<<": "<<strerror(errno)<< endl;
        }
	return 1;
}
