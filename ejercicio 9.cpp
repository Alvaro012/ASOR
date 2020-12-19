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
        int major = major(sb.st_dev);
        int minor = minor(sb.st_dev);
        cout<<"Major number: "<<major<<endl;
        cout <<"Minor number: "<<minor<<endl;
        cout<<"I-node Number: "<<sb.st_ino<<endl;
        cout <<"Mode: " << sb.st_mode<<endl;
	cout<<"Time last access: "<<sb.st_atime<<endl;
        cout<<"Diferencias: st_mtime es el tiempo de la última modificación. st_ctime es el tiempo del último cambio de status, como cambiar la información de inode."<<endl;
        return 1;
}
