#include "get_next_line.h"

void	firstenty(int fd, char **save)
{
	char	*aux;
	ssize_t	num;

	aux = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	num = read(fd, aux, BUFFER_SIZE);
	if (num <= 0)
	{
		free(aux);
		return ;
	}
	aux[num] = '\0';
	*save = ft_substr(aux, 0, num);
	free(aux);
}

char	*doafterjump(char **save)
{
	char	*aux;
	char	*auxi;

	aux = ft_beforejump(*save);
	auxi = ft_substr(ft_strchr(*save, '\n'), 0, ft_strlen(ft_strchr(*save, '\n')));
	free(*save);
	*save = ft_substr(auxi, 0, ft_strlen(auxi));
	free(auxi);
	return (aux);
}

void	middlepart(int fd, char **save)
{
	char *aux;
	ssize_t num;
	char *check;

	check = NULL;
	while(!ft_strchr(*save, '\n'))
	{
		aux = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		num = read(fd, aux, BUFFER_SIZE);
		aux[num] = '\0';
		*save = ft_strjoin(*save, aux);
		free(aux);
		if (!read(fd, check, BUFFER_SIZE))
			return ;
	}
}

char	*ft_getline(int fd, char **save)
{
	char	*aux;
	
	if(!*save)
		firstenty(fd, &(*save));
	if(!*save)
		return (NULL);
	middlepart(fd, &(*save));
	if (ft_strchr(*save, '\n'))
		aux = doafterjump(&(*save));
	else if (ft_strlen(*save) > 0)
		{
			aux = ft_substr(*save, 0, ft_strlen(*save));
			free(*save);
			*save = NULL;
		}
	else
		return (NULL);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*save[4096];
	char		*a;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	a = ft_getline(fd, &(*save));
	if (!a)
	{
		free(*save);
		return (NULL);
	}
	return (a);
}
