#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char **argv){
	kill(atoi(argv[1]),SIGKILL);
	
}

