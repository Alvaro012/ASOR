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
        int i= system("man stat");
        cout<<"I-node number: "<<sb.st_ino<<endl;
        return 1;
}
