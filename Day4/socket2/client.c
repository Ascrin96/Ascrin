#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <netinet/in.h>


int main(int argc, char *argv[]){
	struct sockaddr_in addr;
	char message[] = "Hello World!";
	char buf[sizeof(message)];
	int sock, rc;
	
	sock = socket(AF_INET, SOCK_STREAM, 0);	


	if(sock < 0){
		perror("socket");	
		return 1;
	}
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(3425);
	addr.sin_addr.s_addr = inet_addr("192.168.99.1");
		
	if(connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0){
		perror("connect");	
		return 1;
	}
	
	if(rc = send(sock, message, sizeof(message),0)){	
	
		printf("write\n");
	}
	
	else{
		
		perror("write error");	
		return 1;
	}
	
	close(sock);
	return 0;
}













