#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char **argv){
	int count=0;

	while(1){
		printf("Hello World\n");
		count++;
		if(count==3)
			raise(SIGINT);
		sleep(2);
	}
}

