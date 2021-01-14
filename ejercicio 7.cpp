#include<iostream>
#include<sched.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
#include<sys/resource.h>

using namespace std;

int main(){
	char *command = "ls";
        char *argv[3] = {"ls","-l",NULL};
        int i = system("date");
        if(i!=-1)
                cout<<"El comando terminó de ejecutarse"<<endl;
        else perror("System");
        int x = execvp(command,argv);
        if (x == -1)
                perror("Execvp");

        cout<<"El programa acabó de ejecutarse"<<endl;
//El cout del execvp no se verá, ya que la función sólo devuelve algo si ha habido error, y ademas finaliza el proceso.
 	return 0;

}
