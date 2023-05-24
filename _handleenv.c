#include "shell.h"
/**
 *_getenv - gets the value of an environmental variable
 *@name: name of the environment variable
 *Return: String value of the variable
 */
char *_getenv(const char *name)
{
	int i, j;
	char *value;
	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;
				j++;
			}
			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (NULL);
}
/**
 *addNodeAtEnd - adds a new node at the end of a linked list
 *@head: pointer to pointer to the linked list
 *@str: pointer to string for the new node
 *Return: address of the new element/node
 */
list_path *addNodeAtEnd(list_path **head, char *str)
{
	list_path *tmp;
	list_path *newNode;
	newNode = malloc(sizeof(list_path));
	if (!newNode || !str)
	{
		return (NULL);
	}
	newNode->dir = str;
	newNode->p = NULL;
	if (!*head)
	{
		*head = newNode;
	}
	else
	{
		tmp = *head;
		while (tmp->p)
		{
			tmp = tmp->p;
		}
		tmp->p = newNode;
	}
	return *head;
}
/**
 *createPathList - creates a linked list for path directories
 *@path: string of path value
 *Return: pointer to the created linked list
 */
list_path *createPathList(char *path)
{
	list_path *head = NULL;
	char *token;
	char *cpath = duplicateString(path);
	token = strtok(cpath, ":");
	while (token)
	{
		head = addNodeAtEnd(&head, token);
		token = strtok(NULL, ":");
	}
	return (head);
}
/**
 *findPathname - finds the pathname of a file
 *@filename: name of file or command
 *@head: headn of linked list of path directories
 *Return: pathname of filename or NULL if no match
 */
char *findPathname(char *filename, list_path *head)
{
	struct stat st;
	char *pathname;
	list_path *tmp = head;
	while (tmp)
	{
		pathname = concatenateStrings(tmp->dir, "/", filename);
		if (stat(pathname, &st) == 0)
		{
			return (pathname);
		}
		free(pathname);
		tmp = tmp->p;
	}
	return (NULL);
}
/**
 *freeList - frees a linked list
 *@head: pointer to the head of the linked list
 */
void freeList(list_path *head)
{
	list_path *current = head;
	list_path *next;
	while (current)
	{
		next = current->p;
		free(current->dir);
		free(current);
		current = next;
	}
}
