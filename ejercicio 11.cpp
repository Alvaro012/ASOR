#include <sys/types.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <iostream>

using namespace std;

int main(){
	int fd =open("fichero",O_RDONLY);
        int fd1=open("fichero10",O_RDONLY);
        if (fd!=0 && fd1!=0){
        link("fichero","fichero.hard");
        symlink("fichero10","fichero10.sym");
        }
 return 1;

}

