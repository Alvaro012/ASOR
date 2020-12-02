#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

using namespace std;

int main(){

	cout<<pathconf("ejercicio1.cpp",_PC_LINK_MAX)<<endl;
        cout<<pathconf("ejercicio1.cpp",_PC_PATH_MAX)<<endl;
        cout<<pathconf("ejercicio1.cpp",_PC_NAME_MAX)<<endl;
        return 1;
}
