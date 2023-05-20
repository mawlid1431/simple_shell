#include "shell.h"
/**
 * main -Entry point
 *
 *Return: 0
 */
int main(void)
{
	char *buffer, **args;
	size_t bufsize = BUFFER_SIZE;
	int status;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		printf(PROMPT);
		getline(&buffer, &bufsize, stdin);

		args = tokenize(buffer);
		status = execute(args[0], args);



		if (status == -1)
			break;
	}
	free(args);
	free(buffer);
	return (0);
}
