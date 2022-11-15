#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int wstatus;
	char * argv[] = {"/usr/bin/ls", "-l", "/tmp", NULL};
	char * envp[] = {NULL};
	pid_t child0_pid;
	pid_t child1_pid;
	pid_t child2_pid;
	pid_t child3_pid;
	pid_t child4_pid;
	
	child0_pid = fork();
	if (child0_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child0_pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
			perror("could not execute");
	}
	else
		wait(&wstatus);

	child1_pid = fork();
	if (child1_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child1_pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
			perror("could not execute");
	}
	else
		wait(&wstatus);

	child2_pid = fork();
	if (child2_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child2_pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
			perror("could not execute");
	}
	else
		wait(&wstatus);

	child3_pid = fork();
	if (child3_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child3_pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
			perror("could not execute");
	}
	else
		wait(&wstatus);

	child4_pid = fork();
	if (child4_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child4_pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
			perror("could not execute");
	}
	else
		wait(&wstatus);

	return (0);
}
