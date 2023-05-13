#include "main.h"
/**
 *execute
 *@args
 *
 *Return: 1
 */
int execute(char *command, char **args)
{
	pid_t pid;
	int status;
	char *path;

	path = find_executable(command);
	if (!path)
	{
		fprintf(stderr, "%s: command not found\n", command);
		return 127;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execute");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
	{
		perror("execute");
		exit(EXIT_FAILURE);
	}
	else
	{
		do
		{
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(path);
	return WEXITSTATUS(status);
}
