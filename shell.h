#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>
extern char **environ;

/**
 * strcut list_path - path directories
 *@dir: directory in path
 *@p: pointer to the next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
}list_path;

/**
 *struct BuiltinCommand - pointer to function with corresponding builtin
 *@name: builtin
 *@func: execute the builtin
 */
typedef struct BuiltinCommand
{
	char *name;
	void (*func)(char **);
}BuiltinCommand;
int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
char *duplicateString(char *str);
char *concatenateStrings(char *str1, char *str2, char *str3);
char **splitString(char *str, const char *delim);
void executeCommand(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void freearv(char **arv);
char *_getenv(const char *name);
list_path *addNodeAtEnd(list_path **head, char *str);
list_path *createPathList(char *path);
char *findPathname(char *filenae, list_path *head);
void freeList(list_path *head);
void(*checkBuiltin(char **command))(char **arv);
int _atoi(char *str);
void exitShell(char **args);
void printEnvironment(char **args);
void setEnvironmentVariable(char **args);
void unsetEnvironmentVariable(char **args);
void signal_handler(int sig_num);
void _EOF(int len, char *buff);
void _isatty(void);
#endif /*SHELL_H*/
