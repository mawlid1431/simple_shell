#include "shell.h"
/**
 * execute - execute a command with its entire path variables.
 * @data: Pointer to the program's data structure
 * Return: If sucess returns zero, otherwise, return -1.
 */
int execute(data_of_program *data)
{
	int retval = 0, status;
	pid_t pid, pidd;
	char *path;

	path = find_executable(data->command_name);
	if (!path)
	{
		fprintf(stderr, "%s: command not found\n", data->command_name);
		return -1;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, data->tokens, NULL) == -1)
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
			retval = execve(data->tokens[0], data->tokens, data->env);
			if (retval == -1) /* if error when execve*/
				perror(data->command), exit(EXIT_FAILURE);
		}
		else
		{/*I am the father,I wait and check the exit status of the child */
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
