#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alarmHandler(int signo);

int main(int args, char **argv){
	int status;
	struct sigaction act;

	act.sa_handler=alarmHandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;

	sigaction(SIGALRM,&act,NULL);

	alarm(3);
	while(1)
		;
}

void alarmHandler(int signo){
	printf("Hi signal %d\n",signo);
	exit(0);
}
