#include <stdio.h>
#include <unistd.h>
#include <string.h>

extern char **environ;
void print_path_dir(const char *name);

int main(void)
{
	print_path_dir("PATH");
	
	return (0);
}

void print_path_dir(const char *name)
{
	int i = 0, sv;
	char *str;

	while (environ[i])
	{
		str = strtok(environ[i], "=");

		if ((sv = strcmp(str, name)) == 0)
			break;
		i++;
	}
	while (str != NULL)
	{
		str = strtok(NULL, ":");
		if (str == NULL)
			break;
		printf("%s\n", str);
	}
}
	
