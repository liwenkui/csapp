#include <unistd.h>
#include <stdio.h>
unsigned int snooze(unsigned int secs){
	unsigned int rem;
	rem=sleep(secs);
	printf("Slept for %u of %u secs.\n",secs-rem,secs);
	return rem;
}
