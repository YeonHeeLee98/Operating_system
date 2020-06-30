#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define GUESSFIFO "Guessfifo"
#define RESPNSFIFO "Respnsfifo"

int main(int argc,char *argv[]){
	int number,guess,rand();
	int fdguess,fdresp;
	if(mkfifo(GUESSFIFO,0666) == -1){
		perror(GUESSFIFO);
		exit(1);
	}
	if(mkfifo(RESPNSFIFO,0666) == -1){
		perror(RESPNSFIFO);
		exit(2);
	}
	if((fdguess = open(GUESSFIFO,O_RDONLY)) == -1){
		perror(GUESSFIFO);
		exit(3);
	}
	if((fdresp =  open(RESPNSFIFO,O_WRONLY)) == -1){
		perror(RESPNSFIFO);
		exit(4);
	}
	number = rand()%10;
	while(read(fdguess,(char *)&guess,sizeof(guess))>0){
		if(guess > number)
			write(fdresp,"H",1);
		else if(guess<number)
			write(fdresp,"L",1);
		else
			write(fdresp,"E",1);
	}
	close(fdguess);
	close(fdresp);
	unlink(GUESSFIFO);
	unlink(RESPNSFIFO);
	exit(0);
	return 0;
}

