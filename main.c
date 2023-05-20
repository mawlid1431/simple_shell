#include "shell.h"
/**
 * main -Entry point
 *
 *Return: 0
 */
int main(void)
{
	char *buffer;
	size_t bufsize = BUFFER_SIZE;
	int status;
	data_of_program data;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	inicialize_data(&data, 0, NULL, environ);
	while (1)
	{
		printf(PROMPT);
		_getline(&data);

		tokenize(&data);
		status = execute(&data);

		free_recurrent_data(&data)

		if (status == -1)
			break;
	}
	free_all_data(&data);
	free(buffer);
	return (0);
}
