#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	if ((pid = fork()) < 0)		
	{
		printf("error\n");
	} else if (pid == 0)
	{
		execl("/bin/ls", "ls", "-l", "/home", (char *) 0);
	} else {
		printf("parent process ok!\n");
	}
	return 0;
}