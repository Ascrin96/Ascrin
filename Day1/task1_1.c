#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

	size_t size;

	if(pipe(fd) < 0){
		printf("Can\'t create pipe\n");
		exit(-1);
	}
	
	pid_t pid;
	pid = fork();
	if(pid == -1){
		printf("Some error happened\n");	
	}
	
	else if(pid == 0){
		printf("Child process %d\n", getpid());
		size = write(fd[1], execlp("/bin/ls", "ls", "-l","/tmp/", NULL), );
	}
		else{
			
		}














}
