#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *say_hello(char *name);

int main(int argc, char const *argv[])
{
	int error;
	int *temptr;
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, (void *) *say_hello, "DAQINZHIDI");
	if (error = pthread_join(thread_id, (void **) &temptr))
	{
		perror("pthread_join error");
		exit(EXIT_FAILURE);
	}
	printf("create thread id : %d\n", thread_id);
	return 0;
}

void *say_hello(char *name) {
	printf("name is %s\n", name);
	printf("main thread id : %d\n", pthread_self());
	return 0;
}