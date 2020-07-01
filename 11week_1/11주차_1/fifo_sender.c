#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define GUESSFIFO "Guessfifo"
#define RESPNSFIFO "Respnsfifo"
int main(int argc, char *argv[]){
	int higuess, loguess,guess;
	int fdguess, fdresp;
	char response;
	if((fdguess = open(GUESSFIFO,O_WRONLY)) == -1){
		perror(GUESSFIFO);
		exit(1);
	}
	if((fdresp = open(RESPNSFIFO, O_RDONLY)) == -1){
		perror(RESPNSFIFO);
		exit(2);
	}
	loguess = 0;
	higuess = 1000;
	guess  = 500;
	write(fdguess,(char *) &guess, sizeof(guess));
	while(read(fdresp,&response,1)>0){
		if(response == 'H'){
			printf("%d is too high \n",guess);
			higuess = guess;
			guess = (higuess + loguess)/2;
		}
		else if(response == 'L'){
			printf("%d is too low \n",guess);
		}
		else if(response == 'L'){
			printf("%d is too low\n",guess);
			loguess = guess;
			guess = (higuess + loguess)/2;
		}
		else{
			printf("%d is correct\n",guess);
			break;
		}
		write(fdguess,(char * ) &guess, sizeof(guess));
	}
	close(fdguess);
	close(fdresp);
	exit(0);
	return 0;
}
