#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t my_pid;
	pid_t pid;
	pid_t ppid;

	printf("Before fork\n");
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	printf("After fork\n");
	my_pid = getpid();
	ppid = getppid();
	printf("My pid is %u\n", my_pid);
	printf("My child pid is %u\n", pid);

	return (0);
}
