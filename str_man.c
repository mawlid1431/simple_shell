#include "shell.h"
/**
 *_strdup - A function that duplicates a str
 *@str: A pointer to the string
 *Return: A pointer to the duplicated string
 */
char *_strdup(char *str)
{
	unsigned int a, i;
	char *p;
	if (str == NULL)
	{
		return (NULL);
	}
	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	a++;
	p = malloc((a) * sizeof(char));
	if (p == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/**
 * str_length - computes the length of a string
 * @str: the string to compute the length of
 * Return: the length of the string
 */
size_t str_length(const char *str)
{
    size_t length = 0;

    while (str[length] != '\0')
        length++;

    return length;
}
