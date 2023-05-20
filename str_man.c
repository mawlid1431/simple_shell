#include "shell.h"
/**
 *_strdup - A function that duplicates a str
 *@str: A pointer to the string
 *Return: A pointer to the duplicated string
 */
char *_strdup(char *str)
{
	unsigned int len, i;
	char *dup;
	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len] != '\0')
		len++;
	len++;
	dup = malloc(len * sizeof(char));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	return (dup);
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
