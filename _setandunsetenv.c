#include "shell.h"
/**
 *_atoi - converts a string into an integer
 *@str: Pointer to a string
 *Return: the converted integer
 */
int _atoi(char *str)
{
	int index, num, sign;

	sign = 1;
	index = num = 0;
	while (!((str[index] >= '0') && (str[index] <= '9')) && (str[index] != '\0'))
	{
		if (str[index] == '-')
		{
			sign = sign * (-1);
		}
		index++;
	}
	while ((str[index] >= '0') && (str[index] <= '9'))
	{
		num = (num * 10) + (sign * (str[index] - '0'));
		index++;
	}
	return (num);
}
/**
 *exitShell - exits the shell with or without a return status
 *@args: array of arguments entered in the command line
 */
void exitShell(char **args)
{
	int status, i;

	if (args[1])
	{
		status = _atoi(args[1]);
		if (status <= -1)
			status = 2;
		freearv(args);
		exit(status);
	}
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
	exit(0);
}
/**
 *printEnvironment - prints the current environment
 *@args: array of arguments
 */
void printEnvironment(char **args __attribute__ ((unused)))
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}
}
/**
 *setEnvironmentVariable - Initializes a new environment variable or
 *modifies an existing one
 *@args: array of entered words
 */
void setEnvironmentVariable(char **args)
{
	int i, j, k;

	if (!args[1] || !args[2])
	{
		perror(getenv(""));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (args[1][j] == environ[i][j])
		{
			while (args[1][j])
			{
				if (args[1][j] != environ[i][j])
					break;
				j++;
			}
			if (args[1][j] == '\0')
			{
				k = 0;
				while (args[2][k])
				{
					environ[i][j + 1 + k] = args[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{
		environ[i] = concatenateStrings(args[1], "=", args[2]);
		environ[i + 1] = '\0';
	}
}
/**
 *unsetEnvironmentVariable - Remove an environment variable
 *@args: array of entered words
 */
void unsetEnvironmentVariable(char **args)
{
	int i, j;

	if (!args[1])
	{
		perror(getenv(""));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (args[1][j])
		{
			while (args[1][j])
			{
				if (args[1][j] != environ[i][j])
					break;
				j++;
			}
			if (args[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}
