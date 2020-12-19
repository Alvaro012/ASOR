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
        open("home/cursoredes/direct",umask);
        int i= system("ls direct");
        return 1;
}
