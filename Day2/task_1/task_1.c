#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 5
#define NUM_D 2

int uniqueId = -1;

char *Thread_names[] = { "thread_1" , "thread_2", "thread_3", "thread_4", "thread_5"};

typedef struct Mystruct {
	int id;
	char name_thread[256];
	int i;
	int d;
} Mystruct;

int unique_id(){
	uniqueId++;
	return uniqueId;
}

void* func_counter(void *p){
	int count = 0;
	int j;
	
	Mystruct *thread_struct = (Mystruct *) p;

	for(j = 0; j < thread_struct->i; j++){
		count = count + thread_struct->d;
		printf("Thread id: %d, thread name: %s, number of cycle: %d, counter = %d\n",thread_struct->id, thread_struct->name_thread, j, count);
	}
}

int main(int argc, char *argv){

	pthread_t threads[NUM_THREADS];
	int k;
	Mystruct t_struct[NUM_THREADS];	
		
	
	for(k = 0; k < NUM_THREADS; k++){

		t_struct[k].id = k;
		t_struct[k].i = rand()%20;
		strcpy(t_struct[k].name_thread, Thread_names[k]);
		t_struct[k].d = NUM_D;

		printf("In main: creating thread %d\n", k);
		pthread_create(&threads[k], NULL, func_counter, (void*) &t_struct[k]);
	}
	
	for(k = 0; k < NUM_THREADS; k++){
		pthread_join(threads[k], NULL);
		printf("Thread#%d finished\n", t_struct[k].id);	
	}

}





