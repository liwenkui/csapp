#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "../code/include/csapp.h"
int main(){
	pid_t pid,pid_1;
	int statusp;
	int x=1;
	pid=Fork();
	if(pid==0){
		printf("child : x=%d\n",++x);
		exit(0);
	}
	printf("parent : x=%d\n",--x);
	pid_1=waitpid(pid,&statusp,WUNTRACED);
	printf("child %d terminated normally",pid);
	exit(0);
	return 0;
}
