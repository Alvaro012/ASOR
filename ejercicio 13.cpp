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
	int file_desc = open("dup.txt", O_WRONLY | O_APPEND);
        int file_error =open("no_exist.txt",O_WRONLY|O_APPEND);
        dup2(file_desc,1);
        dup2(file_error,fileno(stderr));
        cout<<"Esto se verá en dup.txt"<<endl;
        cout<<"Esto también"<<endl;
        if(file_error < 0)
                perror("Error");
	cout<<"No es lo mismo debido al orden de los elementos. Uno dará como resultado 'bash: directorio: Is a directory' mientras que el otro enseñará lo mismo que escribiendo 'ls'.<<endl;

 return 1;

}



