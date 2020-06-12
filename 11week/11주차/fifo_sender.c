#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int f;
void my_send(const char* str){
	int len;
	len=strlen(str);
	write(f,str,len);
}

int main(){
	char buffer[256];
	const char* fifoname="./my.fifo";

	f=open(fifoname,O_WRONLY);
	if(f<0){
		return -1;
		printf("open fail\n");
	}
	my_send("hello");
	sleep(1);
	my_send("my name is");
	sleep(1);
	my_send("Operating System!");
	sleep(1);
	my_send("quit");

	return 0;
}

