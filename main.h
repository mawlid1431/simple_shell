#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define PROMPT "$ "
#define DELIMETER " \t\n\r\a"

char **tokenize(char *line);
int execute(char *command, char **args);
char *find_executable(char *command);
#endif /*MAIN_H*/
