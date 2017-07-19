#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512
struct c_msg_st
{
	int c_msg_type;
	char msg_text[MAX_TEXT];
};

int main(int argc, char const *argv[])
{
	int running = 1;
	struct c_msg_st some_data;
	int msgid;
	char buffer[BUFSIZ];
	if ((msgid = msgget((key_t) 12345, 0666 | IPC_CREAT)) == -1)
	{
		perror("msgget error")
		exit(EXIT_FAILURE);
	}
	while(running) {
		printf("Enter message to send:");
		fgets(buffer, BUFSIZ, stdin);
		some_data.c_msg_type = 1;
		strcpy(some_data.msg_text, buffer);
		if ((msgsnd(msgid, (void *) &some_data, MAX_TEXT, 0)) == -1)
		{
			perror("msgsnd error");
			exit(EXIT_FAILURE);
		}
		if (strncmp(buffer, "end", 3) == 0)
		{
			running = 0;
		}
	}
	return 0;
}