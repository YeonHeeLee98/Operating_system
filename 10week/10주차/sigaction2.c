#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void signal_handler(int signo){
	printf("start handler\n");
	sleep(3);
	printf("end handler\n");
}

int main(int argc, char ** argv){
	struct sigaction act;
        act.sa_handler=signal_handler;
        sigfillset(&act.sa_mask);
        act.sa_flags=0;
        sigaction(SIGINT, &act,NULL);
	printf("call sigaction\n");

        while(1){
               sleep(5);
											        }       
}       


