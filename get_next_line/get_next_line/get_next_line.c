#include "get_next_line.h"

char *ft_getline(int fd, char **save)
{
	char *a;
	char *ai;
	ssize_t num;

	if (*save)
	{
		if(!ft_beforejump(*save))
		{
			printf("1\n");
			ai = ft_strdup(*save);
			free(*save);
			*save = malloc(sizeof(char) * BUFFER_SIZE + ft_strlen(ai));
			read(fd, *save, BUFFER_SIZE);
			*save = ft_chartostr(ai, *save, BUFFER_SIZE + ft_strlen(ai) + 1);
			a = ft_getline(fd, save);
		}
		else if(ft_strlen(ft_beforejump(*save)) <= BUFFER_SIZE)
		{
			printf("2\n");
			a = ft_beforejump(*save);
			ai = ft_strdup(*save);
			free(*save);
			*save = ft_substr(ai, ft_strlen(a) + 1,ft_strlen(ai));
		}
		else
		{
			printf("3\n");
			a = ft_substr(*save, 0, BUFFER_SIZE);
			ai = ft_strdup(*save);
			free(*save);
			*save = ft_substr(ai, ft_strlen(a) ,ft_strlen(ai));
		}
	}
	else
	{
		*save = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
		num = read(fd, *save, BUFFER_SIZE);
		a = malloc(num * sizeof(char) + 1);
		if (!ft_beforejump(*save))
		{
			printf("Entra\n");
			a = ft_strdup(*save);
		}
		else
		{
			printf("4\n");
			a = ft_beforejump(*save);
			ai = ft_strchr(*save, '\n');
		}
	free(*save);
	*save = ft_substr(ai, 0, ft_strlen(ai));
	}
	return (a);
}

int ft_freesave(char **save)
{
	if (!*save)
		return (0);
	if (!**save)
	{
		free(*save);
		*save = NULL;
		return (0);
	}
	return (1);
}

char *get_next_line(int fd)
{
	ssize_t		count;
	char		*auxline;
	static char	*save[4096];

	auxline = ft_strdup("");
	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	return (ft_getline(fd, &save[fd]));
}

 

int main()
{
	int 	fd;
	int		fd2;
	char	*line;
	int		j;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	while (j < 6)
	{
		line = get_next_line(fd);
		printf("[%s]\n", line);
		j++;
	}
	j = 0;
/*	while (j < 2)
	{
		line = get_next_line(fd2);
		printf("[%s]\n", line);
		j++;
	}*/
	return(0);
}