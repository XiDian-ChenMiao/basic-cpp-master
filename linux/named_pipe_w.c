#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FIFO_NAME "/home/daqinzhidi/programs/c/pipe_r_w"
int main(int argc, char const *argv[])
{
	int pipe_fd;
	int res;
	char buffer[] = "Hello Node.js";
	if (access(FIFO_NAME, F_OK) == -1)
	{
		res = mkfifo(FIFO_NAME, 0766);
		if (res != 0)
		{
			fprintf(stderr, "Could not create file %s\n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}
	}
	printf("Process %d opening FIFO O_WRONLY\n", getpid());
	pipe_fd = open(FIFO_NAME, O_WRONLY);
	printf("The file's decriptor is %d\n", pipe_fd);
	if (pipe_fd != -1)
	{
		res = write(pipe_fd, buffer, sizeof(buffer));
		if (res == -1)
		{
			fprintf(stderr, "Write error on pipe\n");
			exit(EXIT_FAILURE);
		}
		printf("Write data is %s, %d bytes is writen\n", buffer, res);
		close(pipe_fd);
	} else {
		exit(EXIT_FAILURE);
	}
	printf("Process %d finished\n", getpid());
	return 0;
}
