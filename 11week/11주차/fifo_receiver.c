#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){
	int f;
	int len;
	char buffer[256];
	const char* fifoname="./my.fifo";

	unlink(fifoname);
	if(mkfifo(fifoname,0666)==-1){
		printf("mkfifo fail\n");
		return -1;
	}

	f=open(fifoname,O_RDWR | O_NONBLOCK);
	if(f<0){
		printf("open fail\n");
		return -1;
	}
	
	while(1){
		memset(buffer,0,sizeof(buffer));
		len=read(f,buffer,256);

		if(len>0){
			printf("recv: [%s]\n",buffer);

			if(strcmp(buffer,"quit")==0){
				break;
			}
		}
		else {
			printf("wait for input fifo...\n");
		}
		sleep(1);
	}
	close(f);

	return 0;
}

