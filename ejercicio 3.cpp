#include <sys/types.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

using namespace std;

int main(){
	//chmod 540 fichero
	chmod("home/cursoredes/fichero",S_IRUSR| S_IXUSR|S_IRGRP);
	//chmod u+rx,g+r-wx,o-wxr fichero
	chmod("home/cursoredes/fichero",S_IRUSR| S_IXUSR|S_IWGRP| S_IXGRP| S_IROTH|S_IWOTH|S_IXOTH);
        return 1;
}

