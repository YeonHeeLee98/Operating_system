#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc, char ** argv){
	sigset_t set;

	if(sigemptyset(&set) == -1){
		perror("sigemptyset failed\n");
		exit(1);
	}
	if(sigaddset(&set, SIGINT) == -1){
	        perror("sigaddset failed\n");
		exit(1);
	}
	if(sigismember(&set, SIGINT)){
		printf("SIGINT is a member\n");
	}
	else{
		printf("SIGINT is not a member\n");
	}
	exit(0);
}

