#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char str[10], word[10];
	int fd[2];
	size_t sizeW, sizeR;

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
			printf("Enter the word:\n");
			scanf("%s", str);
			sizeW = write(fd[1], str, strlen(str));
	}
		else{
			int stat;
			printf("parrent process %d\n", getpid());
			sizeR = read(fd[0], word, 10);
			wait(&stat);
			printf("The entered word: %s\n", word);
			printf("parrent process %d finished %d\n", getpid(), stat);
		}
	return;
}
