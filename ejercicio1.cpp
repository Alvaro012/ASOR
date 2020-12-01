#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <errno.h>

using namespace std;

int main() {
	if (setuid(2) == -1) {
		cout << "Error:" << strerror(errno) << endl;
	}
	return 1;
}