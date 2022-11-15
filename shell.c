#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
	char *str;
	char * line = NULL;
	ssize_t nread;
	size_t len = 0;
	int wstatus;
	char *argv[2];
	char *envp[] = {NULL};
	pid_t shell_pid;

	while (1)
	{
		printf("shell$ ");
		nread = getline(&line, &len, stdin);
		
		str = strtok(line, " \n\t");
		argv[0] = str;
		str = strtok(NULL, " \n\t");
		argv[1] = str;
		argv[2] = NULL;

		shell_pid = fork();
		if (shell_pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (shell_pid == 0)
		{
			if ((nread = execve(argv[0], argv, envp)) == -1)
				perror("Not a valid command");
		}
		else
			wait(&wstatus);
		
		free(line);
		line = NULL;
	}
}
