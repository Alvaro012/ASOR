#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

using namespace std;

int main(){
	struct utsname buffer;
        errno = 0;
        if (uname(&buffer) != 0) {
                 perror("uname");
                 exit(EXIT_FAILURE);
         }
	cout<<buffer.sysname<<endl;
        cout<<buffer.nodename<<endl;
	cout<<buffer.release<<endl;
        cout<<buffer.version<<endl;
        cout<<buffer.machine<<endl;
        cout<<buffer.domainname<<endl;
        return 1;
}

