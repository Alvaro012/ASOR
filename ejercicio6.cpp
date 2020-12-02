#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

using namespace std;

int main(){
	cout<<sysconf(_SC_ARG_MAX)<<endl;
        cout<<sysconf(_SC_CHILD_MAX)<<endl;
        cout<<sysconf(_SC_OPEN_MAX)<<endl;
        return 1;
}
