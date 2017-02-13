#include "../code/include/csapp.h"
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#define N 5
int main(){
	int status , i;
	pid_t pid[N],retpid;
	for(i=0;i<N;i++)
		if((pid[i] = Fork())==0)
			exit(100+i);		
	i=0;
	while((retpid=waitpid(pid[i++],&status,0))>0){
		if(WIFEXITED(status))
			printf("chile %d terminated normally with exit status %d\n",
					retpid,WEXITSTATUS(status));
		else
			printf("child %d terminated abnormally\n",retpid);
	}
	if(errno != ECHILD)
		unix_error("waitpid error");
	exit(0);
}
