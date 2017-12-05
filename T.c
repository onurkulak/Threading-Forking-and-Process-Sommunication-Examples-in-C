#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* counter(void *param){
	int i = 1; 
	while(i<=100)
		printf("%d\n", i++);
}

int main(int argc, char const *argv[]){
	int threadCount = atoi(argv[1]);
	pthread_t * threads=(pthread_t *)malloc(threadCount*sizeof(pthread_t));
	int i = 0; 
	while(i<threadCount)
		pthread_create(&threads[i++], NULL, counter, NULL);
	i = 0; 
	while(i<threadCount)
		pthread_join(threads[i++], NULL);
}


