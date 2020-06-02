#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char **argv){
	sigset_t set1, set2;

	sigfillset(&set1);
	sigemptyset(&set2);

	sigaddset(&set2,SIGINT);

	sigprocmask(SIG_BLOCK,&set1,NULL);
	printf("block start\n");
	sleep(10);
	sigprocmask(SIG_UNBLOCK,&set2,NULL);
	printf("SIGINT unblock\n");

	while(1){
		printf("Hello World\n");
		sleep(2);
		}
}

