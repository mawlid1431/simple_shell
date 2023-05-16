#include "shell.h"
/**
 * execute - execute a command with its entire path variables.
 * @data: a pointer to the program's data
 * Return: If sucess returns zero, otherwise, return -1.
 */
int execute(data_of_program *data)
{
	int retval = 0, status;
	pid_t pidd;

<<<<<<< HEAD

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
=======
	/* check for program in built ins */
	retval = builtins_list(data);
	if (retval != -1)/* if program was found in built ins */
		return (retval);

	/* check for program file system */
	retval = find_program(data);
	if (retval)
	{/* if program not found */
		return (retval);
>>>>>>> 8cbb51c596c8489fafdde6a25936e8ce40babec0
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
				perror(data->command_name), exit(EXIT_FAILURE);
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
