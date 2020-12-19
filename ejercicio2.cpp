#include <sys/types.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
	int p = system("ls -ld practica2.2.c");
        int m = system("mkdir directorio1");
        int i=system("ls -ld practica2.2.c");
        int j=system("ls -ld directorio");
        return 1;
}
