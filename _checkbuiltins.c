#include "shell.h"
/**
 *checkBuiltin - checks if the command is a builtin command
 *@command: name of the command
 *Return: pointer tot he corresponding builtin function or null if not found
 */
void (*checkBuiltin(char *command))(char **arv)
{
	int i;
	BuiltinCommand builtinCommands[] = {
		{"exit", exitShell},
		{"env", printEnvironment},
		{"setenv", setEnvironmentVariable},
		{"unsetenv", unsetEnvironmentVariable},
		{NULL, NULL}
	};
	for (i = 0; builtinCommands[i].name, i++)
	{
		if (strcmp(command, builtinCommands[i].name) == 0)
			return buitlinCommands[i].func;
	}
	return (NULL);
}
