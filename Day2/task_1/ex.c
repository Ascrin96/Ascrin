#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
//	char **Thread_names = { "thread_1" , "thread_2", "thread_3", "thread_4", "thread_5"};
	char *ptr[] = { "строка1", "строка2", "строка3" };

	for(i = 0; i < 3; i++){
		printf("%s\n", ptr[i]);
	}
}
