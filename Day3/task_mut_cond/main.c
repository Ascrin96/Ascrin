#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS     5

int count;

pthread_mutex_t mut1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mut2 = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t *cond;
pthread_cond_init(cond, NULL);

void* counter(void*){
	count++;

	pthread_mutex_lock(&mut1);
	sleep(count);
	printf("Thread finished\n");
	pthread_mutex_unlock(&mut1);

	
	pthread_mutex_lock(&mut2);
	pthread_cond_wait(&cond, &mut2);
	pthread_mutex_unlock(&mut2);
	
	pthread_mutex_unlock(&mut1);
}

int main () {
	pthread_t threads[NUM_THREADS];
	int i, rc;

	for(i = 0; i < NUM_THREADS; i++){
		printf("In main: creating thread %d\n", t);
	        rc = pthread_create(&threads[t], NULL, counter, NULL);
	        if (rc) {
	            printf("ERROR; return code from pthread_create() is %d\n", rc);
	            exit(-1);
	        }
	
	}
	
	for(t = 0; t < NUM_THREADS; t++) {
        	pthread_join(threads[t], NULL);
        	printf("Thread #%d finished\n", t);
	}

}
