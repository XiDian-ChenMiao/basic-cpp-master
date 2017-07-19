#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	int fd;
	int i = 1, status;
	char *ch1 = "Chen", *ch2 = "Miao", *ch3 = "China";
	if ((fd = open("test.txt", O_RDWR | O_CREAT, 0644)) == -1)
	{
		perror("parent open");
		exit(EXIT_FAILURE);
	}
	if (write(fd, ch1, strlen(ch1)) == -1)
	{
		perror("parent write");
		exit(EXIT_FAILURE);
	}
	if ((pid = fork()) == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		i = 2;
		printf("child process\n");
		printf("i = %d\n", i);
		if (write(fd, ch2, strlen(ch2)) == -1)
		{		
			perror("child write");
		}
		return 0;
	} else {
		sleep(1);
		printf("parent process\n");
		printf("i = %d\n", i);
		if (write(fd, ch3, strlen(ch3)) == -1)
		{
			perror("parent write");
		}
		wait(&status);
		return 0;
	}
	return 0;
}