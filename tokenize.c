#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
#define DELIMITER " \t\r\n\a"

char **tokenize(char *line)
{
    char **tokens = NULL;
    char *token = NULL;
    int index = 0;
    size_t size = 0;

    if (line == NULL)
        return NULL;

    tokens = malloc(BUFFER_SIZE * sizeof(char *));
    if (tokens == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DELIMITER);
    while (token != NULL)
    {
        if (index >= BUFFER_SIZE)
        {
            fprintf(stderr, "tokenize: too many tokens\n");
            free(tokens);
            return NULL;
        }

        size = strlen(token) + 1;
        tokens[index] = malloc(size * sizeof(char));
        if (tokens[index] == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        strcpy(tokens[index], token);
        index++;

        token = strtok(NULL, DELIMITER);
    }

    tokens[index] = NULL;

    if (index == 0)
    {
        free(tokens);
        tokens = NULL;
    }

    return tokens;
}
