#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define FIFO "/home/daqinzhidi/programs/c/named_pipe"
int main(int argc, char const *argv[])
{
	pid_t pid;
	char buffer[80];
	int fd;
	unlink(FIFO);
	mkfifo(FIFO, 0744);
	if ((pid = fork()) > 0)
	{
		char info[] = "Hello Node.js";
		fd = open(FIFO, O_WRONLY);
		printf("this is parent process write data is %s\n", info);
		printf("parent process id : %d\n", getpid());
		write(fd, info, sizeof(info));
		close(fd);
		exit(EXIT_SUCCESS);
	} else if (pid == 0) {
		sleep(2);
		fd = open(FIFO, O_RDONLY);
		read(fd, buffer, 80);
		printf("this is child process read data is %s\n", buffer);
		close(fd);
		printf("child process id : %d\n", getpid());
		exit(EXIT_SUCCESS);
	} else {
		perror("fork error");
		exit(EXIT_FAILURE);
	}
}