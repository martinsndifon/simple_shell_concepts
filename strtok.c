#include <stdio.h>
#include <string.h>

int main(void)
{
	char *ptr;
	char str[] = "my name is Martins Ndifon";

	ptr = strtok(str, " ");
	while (ptr != NULL)
	{
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
	}
	return 0;
}
