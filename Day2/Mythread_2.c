#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS     5

int k = 0;

/*void *print_hello(void *num) {
    long t_num;
    int t_id;
    int i;
    t_num = (long) num;
    t_id =  pthread_self();
    for (i = 0; i < 10; i++) {
        printf("Hello World! Thread num: %ld, id: %d\n", t_num, t_id);
        sleep(1);
    }
    pthread_exit(NULL);
}*/

void *func_add(){
	int i;
	for(i = 0; i < 10; i++){
		k++;
		printf("%d\n", k);	
	}
}

void *fucn_sub(){
	int i;
	for(i = 0; i < 10; i++){
		k--;
		printf("%d\n", k);	
	}
}

int main (int argc, char *argv[]) {
    pthread_t threads[2];
    int rc1, rc2;
    long t;

        rc1 = pthread_create(&threads[t], NULL, func_add, NULL);
        if (rc1) {
            printf("ERROR; return code from pthread_create() is %d\n", rc1);
            exit(-1);
        }
	
	rc2 = pthread_create(&threads[t], NULL, func_sub, NULL);
        if (rc2) {
            printf("ERROR; return code from pthread_create() is %d\n", rc2);
            exit(-1);
        }
    
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
//   for(t = 0; t < NUM_THREADS; t++) {
//        pthread_join(threads[t], NULL);
//        printf("Thread #%ld finished\n", t);
//    }

    return 0;
}
