#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#define WORK_SIZE 1024

void *thread_operation_func(void *arg);
pthread_mutex_t work_mutex;
char work_area[WORK_SIZE];

int time_to_exit = 0;
int main(int argc, char const *argv[])
{
	int res;
	pthread_t thread;
	void *thread_result;
	res = pthread_mutex_init(&work_mutex, NULL);
	if (res != 0)
	{
		perror("pthread_mutex_init error");
		exit(EXIT_FAILURE);
	}
	res = pthread_create(&thread, NULL, thread_operation_func, NULL);
	if (res != 0)
	{
		perror("pthread_create error");
		exit(EXIT_FAILURE);
	}
	pthread_mutex_lock(&work_mutex);
	printf("Enter text. Enter 'end' to finish\n");
	while(!time_to_exit) {
		fgets(work_area, WORK_SIZE, stdin);
		pthread_mutex_unlock(&work_mutex);/*解锁，两个线程抢占互斥锁*/
		while(1) {
			pthread_mutex_lock(&work_mutex);
			if (work_area[0] != '\0')/*检查读入的内容输出没有*/
			{
				pthread_mutex_unlock(&work_mutex);
				sleep(1);
			} else {
				break;
			}
		}
	}
	pthread_mutex_unlock(&work_mutex);
	printf("\nWaiting for thread to finish.\n");
	res = pthread_join(thread, &thread_result);/*等待另一个线程结束*/
	if (res != 0)
	{
		perror("pthread_join error");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined.\n");
	pthread_mutex_destory(&work_mutex);
	exit(EXIT_SUCCESS);
}

void *thread_operation_func(void *arg) {
	sleep(1);
	pthread_mutex_lock(&work_mutex);
	while(strncmp("end", work_area, 3) != 0) {
		printf("Your input %d characters, content is %s\n", strlen(work_area) - 1, work_area);
		work_area[0] = '\0';
		pthread_mutex_unlock(&work_mutex);
		sleep(1);
		pthread_mutex_lock(&work_mutex);
		while(work_area[0] == '\0') {/*判断第一位是否为\0，如果是，则表明主线程还没有输入数据，如果是，则表示有输入，执行下一轮输出操作*/
			pthread_mutex_unlock(&work_mutex);
			sleep(1);
			pthread_mutex_lock(&work_mutex);
		}
	}
	time_to_exit = 1;
	work_area[0] = '\0';
	pthread_mutex_unlock(&work_mutex);
	pthread_exit(0);
}