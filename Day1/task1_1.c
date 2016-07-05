#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

	size_t size;
	int fd[2];

	char str[512];

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
		close(fd[0]);
		dup2(fd[1], 1);
		dup2(fd[1], 2);
		close(fd[1]);
		execlp("/bin/ls", "ls", "-l","/tmp/", NULL);
		exit(1);
	}
		else{
			int stat;
			printf("parrent process %d\n", getpid());
			close(fd[1]);
			wait(&stat);
			size = read(fd[0],str,sizeof(str));
			printf("My string:\n%s\n", str);
			
		}


}
