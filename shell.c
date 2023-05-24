#include "shell.h"
/**
 *signal_handler - checks if c-c is pressed
 *sig_num: integer
 */
void signal_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\n#$ ");
	}
}
/**
 *_EOF - Hnaldes the end of file
 *@len: return value of getline function
 *@buff: buffer
 */
void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}
/**
 *_isatty - verify the terminal
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#$ ");
}
/**
 *main - entry point
 *Return: 0
 */
int main(void)
{
	ssize_t len;
	size_t size;
	char *buff = NULL, *value, *pathname, **arv;
	list_path *head;
	void (*f)(char **);
	len = size = 0;
	head = '\0';
	signal(SIGINT, signal_handler);
	while (len != EOF)
	{
		_isatty();
		len = getline(&buff, &size, stdin);
		_EOF(len, buff);
		arv = splitString(buff, " \n");
		if (!arv || !arv[0])
			executeCommand(arv);
		else
		{
			value = _getenv("PATH");
			head = createPathList(value);
			pathname = findPathname(arv[0], head);
			f = checkBuiltin(arv);
			if (f)
			{
				free(buff);
				f(arv);
			}
			else if (!pathname)
				executeCommand(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				executeCommand(arv);
			}
		}
	}
	freeList(head);
	freearv(arv);
	free(buff);
	return (0);
}
