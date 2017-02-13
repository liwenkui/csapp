#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(){
	pid_t id=getpid();
	printf("id = %d",id);
	return 0;
}
