#include "shell.h"
/**
 * execute - execute a command with its entire path variables.
 * @command: the command to execute
 * @args: an array of arguments for the command
 * Return: If sucess returns zero, otherwise, return -1.
 */
int execute(const char *command, char **args)
{
	int retval = 0, status;
	pid_t pid, pidd;

	path = find_executable(command);
	if (!path)
	{
		fprintf(stderr, "%s: command not found\n", command);
		return -1;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, NULL) == -1)
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
	{/* if program was found */
		pidd = fork(); /* create a child process */
		if (pidd == -1)
		{ /* if the fork call failed */
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{/* I am the child process, I execute the program*/
			retval = execve(args[0], args, data->env);
			if (retval == -1) /* if error when execve*/
				perror(command), exit(EXIT_FAILURE);
		}
		else
		{/* I am the father, I wait and check the exit status of the child */
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
