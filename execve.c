#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char cmd[] = "/usr/bin/ls";

	char * argv[] = {"/usr/bin/ls", "-l", NULL};
	char * envp[] = {NULL};

	printf("start of execve call %s:\n", cmd);
	printf("=========================================================\n");
	if (execve(cmd, argv, envp) == -1)
	{
		perror("could not execute");
	}
	printf("Oops, something went wrong");

	return 0;
}
