#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc, char ** argv){
	sigset_t set;

        if(sigfillset(&set) == -1){
		perror("sigfillset failed\n");
		exit(1);
	}
	if(sigdelset(&set, SIGINT) == -1){
	        perror("sigdelset failed\n");
	        exit(1);
	}
	if(sigismember(&set, SIGPIPE)){
	        printf("SIGPIPE is a member\n");
	}
	else{
	        printf("SIGPIPE is not a member\n");
	}
	exit(0);
}

