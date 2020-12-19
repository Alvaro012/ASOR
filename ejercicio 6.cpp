#include <sys/types.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main(){
	mode_t umask(750);
        int i=system("touch ficej6");
        mkdir("direj6",umask);
        int l= system("ls -ld ficej6");
        int s= system("ls -ld direj6");
        return 1;
}