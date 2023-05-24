#include "shell.h"
/**
 *duplicateString - duplicates a given string into a newlly allocated memory
 *@str: pointer to the string
 *Return: pointer to the duplicated string
 */
char *duplicateString(char *str)
{
	int index, length;
	char *new_str;
	if (!str)
	{
		return (NULL);
	}
	for (length = 0; str[length] != '\0';)
	{
		length++;
	}
	new_str = malloc(sizeof(char) * length + 1);
	if (!new_str)
	{
		return (NULL);
	}
	for (index = 0; index < length; index ++)
	{
		new_str[index] = str[index];
	}
	new_str[length] = str[length];
	return (new_str);
}
/**
 *_strlen - It gives the length of the string
 *@str: pointer to the string
 *Return: Length of a string
 */
int _strlen(char *str)
{
	int i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}
/**
 *concatenateStrings - concatenates three strings into a newly allocated memroy
 *@str1: first string
 *@str2: second string
 *@str3: third string
 *Return: pointer to the concatenated string
 */
char *concatenateStrings(char *str1, char *str2, char *str3)
{
	char *result;
	int len1, len2, len3, index, k;
	len1 = _strlen(str1);
	len2 = _strlen(str2);
	len3 = _strlen(str3);
	result = malloc(len1 + len2 + len3 + 1);
	if (!result)
		return (NULL);
	for (index = 0; str1[index]; index++)
		result[index] = str1[index];
	k = index;
	for (index = 0; str2[index]; index++)
		result[k + index] = str2[index];
	k = k + index;
	for (index = 0; str3[index]; index++)
		result[k + index] = str3[index];
	k = k + index;
	result[k] = '\0';
	return (result);
}
/**
 *_putchar - writes the character to stdout
 *@c: The character to print
 *Return: On success 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 *_puts - prints a string
 *@str: pointer to a string
 */
void _puts(char *str)
{
	int i = 0;
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
