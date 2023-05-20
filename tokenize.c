#include "shell.h"
/**
 * tokenize - this function separate the string using a designed delimiter
 * @input_line: the input line to tokenize
 * @tokens: an array to store th resulting tokens
 * Return: the number of tokens
 */
int tokenize(const char *input_line, char **tokens)
{
	char *delimiter = " \t";
	int i, j, counter = 1, length;

	length = str_length(input_line);
	if (length)
	{
		if (input_line[length - 1] == '\n')
			input_line[length - 1] = '\0';
	}

	for (i = 0; input_line[i]; i++)
	{
		for (j = 0; delimiter[j]; j++)
		{
			if (input_line[i] == delimiter[j])
				counter++;
		}
	}

	tokens = malloc((counter + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("malloc");
		exit(errno);
	}
	i = 0;
	tokens[i] = _strdup(_strtok(input_line, delimiter));
	data->command_name = _strdup(tokens[0]);
	while (tokens[i] != NULL)
	{
		i++;
		tokens[i] = _strdup(_strtok(NULL, delimiter));
	}

	return counter;
}
