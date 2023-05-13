#include "main.h"
/**
 *
 *
 *
 */
char *find_executable(char *command)
{
	char *path, *token, *dir, *result;
	struct stat st;

	path = getenv("PATH");
	if (!path)
		return NULL;

	token = strdup(command);
	if (!token)
		return NULL;

	if (stat(token, &st) == 0)
	{
		result = token;
	}
	else
	{
		for (dir = strtok(path, ":"); dir != NULL; dir = strtok(NULL, ":"))
		{
			result = malloc(strlen(dir) + strlen(token) + 2);
			if (!result)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			sprintf(result, "%s/%s", dir, token);

			if (stat(result, &st) == 0)
				break;

			free(result);
		}

		if (!dir)
		{
			free(result);
			result = NULL;
		}
	}

	free(token);
	return result;
}
