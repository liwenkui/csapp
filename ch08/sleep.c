#include <unistd.h>
#include <stdio.h>
unsigned int snooze(unsigned int);
int main(){
	unsigned int ret;
	ret=snooze(5);
	_exit(0);
}
