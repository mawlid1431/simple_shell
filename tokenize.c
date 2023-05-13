#include "main.h"
/**
 * tokenize - Tokenize a string into an array of tokens
 * @line: The string to tokenize
 *
 * Return: A pointer to an array of token
 */
char **tokenize(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	int index = 0;

	tokens = malloc(sizeof(char *) * BUFFER_SIZE);
	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIMETER);
	while (token != NULL)
	{
		tokens[index] = malloc(strlen(token) + 1);
		if (!tokens[index])
		{
			perror("mallcc");
			exit(EXIT_FAILURE);
		}
		strcpy(tokens[index], token);
		index++;
		token = strtok(NULL, DELIMETER);
	}

	tokens[index] = NULL;
	return tokens;
}
