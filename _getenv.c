#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
char *_getenv(const char *name);

int main(void)
{
	char *env, *env1;

	env = getenv("PATH");
	if (env == NULL)
		return (0);

	printf("%s\n", env);
	
	env1 = _getenv("PATH");
	if (env1 == NULL)
		return (0);
	printf("%s\n", env1);

	return (0);
}

char *_getenv(const char *name)
{
	int i = 0, sv;
	char *value, *str;

	while (environ[i])
	{
		str = strtok(environ[i], "=");
		if ((sv = strcmp(str, name)) == 0)
			break;
		i++;
	}
	
	str = strtok(NULL, "");
	value = str;
	return (value);
}

