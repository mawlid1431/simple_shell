#include "shell.h"
/**
 *checkBuiltin - checks if the command is a builtin command
 *@command: name of the command
 *Return: pointer tot he corresponding builtin function or null if not found
 */
void (*checkBuiltin(char **command))(char **arv)
{
	int i, j;
	BuiltinCommand builtinCommands[] = {
		{"exit", exitShell},
		{"env", printEnvironment},
		{"setenv", setEnvironmentVariable},
		{"unsetenv", unsetEnvironmentVariable},
		{NULL, NULL}
	};
	for (i = 0; builtinCommands[i].name; i++)
	{
		j =0;
		if (builtinCommands[i].name[j] == command[0][j])
		{
			for (j = 0; command[0][j]; j++)
			{
				if (builtinCommands[i].name[j] != command[0][j])
					break;
			}
			if (!command[0][j])
				return (builtinCommands[i].func);
		}
	}
	return (NULL);
}
