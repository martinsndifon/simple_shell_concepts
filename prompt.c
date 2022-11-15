#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char * line = NULL;
	int nread;
	size_t len = 0;

	printf("$ ");
	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		perror("getline failed");
		free(line);
		return (1);
	}
	printf("%s", line);
	free(line);

	return (0);
}
