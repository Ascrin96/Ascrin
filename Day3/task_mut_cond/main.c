#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS     5

int count = 0;
int status;


pthread_mutex_t mut1;
pthread_mutex_t mut2;

pthread_cond_t cond;

void *My_counter(){

	pthread_mutex_lock(&mut1);
	count++;
	status++;
	pthread_mutex_unlock(&mut1);
	sleep(count);

	printf("Thread %d stopped\n", status);

	pthread_mutex_lock(&mut2);
	if(status == NUM_THREADS){
		pthread_cond_broadcast(&cond);
	}
	pthread_cond_wait( &cond, &mut2 );
	if(status == NUM_THREADS){
		pthread_cond_broadcast(&cond);
	}
	pthread_mutex_unlock(&mut2);
	printf("Threads free\n");
}

int main (int argc, char *argv) {
	pthread_mutex_init(&mut1, NULL);
	pthread_mutex_init(&mut2, NULL);
	pthread_cond_init(&cond, NULL);
	pthread_t threads[NUM_THREADS];
	int i, rc;

	for(i = 0; i < NUM_THREADS; i++){
		printf("In main: creating thread %d\n", i+1);
	        rc = pthread_create(&threads[i], NULL, My_counter, NULL);
	        if (rc) {
	            printf("ERROR; return code from pthread_create() is %d\n", rc);
	            exit(-1);
	        }
	
	}
	
	for(i = 0; i < NUM_THREADS; i++) {
        	pthread_join(threads[i], NULL);
  	   	printf("Thread #%d finished\n", i+1);
	}

}
