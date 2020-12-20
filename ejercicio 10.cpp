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
	struct stat sb;
        stat("fichero10",&sb);
        cout << "I-nodo fichero10: " <<sb.st_ino<<endl;
        stat("directorio10",&sb);
        cout << "I-nodo directorio10: " <<sb.st_ino<<endl;
        system("ln -s directorio10");
	system("ln -s fichero10");
	system("ls -l");
        system("ls -i");
        link ("directorio10", "fichero10");
	system("ls -i");
        cout<< "Borrar el enlace rigido borrara el enlace origen y destino. Borrar uno simbolico no."<<endl;
        return 1;
}
