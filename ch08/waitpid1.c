#include "../code/include/csapp.h"
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#define N 5
int main(){
	int status , i;
	pid_t pid;
	for(i=0;i<N;i++)
		if((pid = Fork())==0)
			exit(100+i);		
	while((pid=waitpid(-1,&status,0))>0){
		if(WIFEXITED(status))
			printf("chile %d terminated normally with exit status %d\n",
					pid,WEXITSTATUS(status));
		else
			printf("child %d terminated abnormally\n",pid);
	}
	if(errno != ECHILD)
		unix_error("waitpid error");
	exit(0);
}
