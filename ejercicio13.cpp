#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

int main(){
	struct timeval start,end;
        long mtime,seconds,useconds;
        gettimeofday(&start,NULL);
        for(int i=0;i<1000000;i++);
        gettimeofday(&end,NULL);
        seconds = end.tv_sec  - start.tv_sec;
        useconds = end.tv_usec - start.tv_usec;
        mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
        cout<<mtime<<endl;
        return 1;
}




