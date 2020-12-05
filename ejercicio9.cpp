#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
	uid_t uid;
        uid = getuid();
        uid_t euid;
        euid = geteuid();
        cout<<"El UID real del usuario es: "<< uid<<endl;
        cout<<"El EUID efectivo del usuario es: "<<euid<<endl;
        cout<<"Si el bit setuid está activo, el EUID se cambia al usuario del f$
        return 1;
}
