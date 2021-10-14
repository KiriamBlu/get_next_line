#include "get_next_line.h"

char *preparea(int fd, char **save)
{
	char	*a;
	char	*ai;

	a = ft_beforejump(*save);
	if(ft_strlen(ft_beforejump(*save)) != ft_strlen(*save))
	{
		ai = ft_strchr(*save, '\n');
		free(*save);	
		*save = ft_substr(ai, 0, ft_strlen(ai));
	}
	else
	{
		free(*save);
		*save = ft_substr("",0,0);
	}
	return (a);
}

char *ft_getline(int fd, char **save)
{
char *a;
char *ai;
ssize_t num;

while(!ft_beforejump(*save))
{
	if(*save)
	{
		ai = ft_substr(*save, 0, ft_strlen(*save) + 1);
		free(*save);
		*save = malloc(sizeof(char) * BUFFER_SIZE + ft_strlen(ai));
		num = read(fd, *save, BUFFER_SIZE);
		*save = ft_chartostr(ai, *save, BUFFER_SIZE + ft_strlen(ai) + 1);
	}
	else
	{
		*save = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
		num = read(fd, *save, BUFFER_SIZE);
		a = malloc(num * sizeof(char) + 1);
	}
}
a = preparea(fd, &(*save));
return (a);
}

char *get_next_line(int fd)
{
	ssize_t		count;
	static char	*save[4096];
	char *a;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	a = ft_getline(fd, &(*save));
	if (!a)
		return(NULL);
	return (a);
}

 

int main()
{
	int 	fd;
	int		fd2;
	char	*line;
	int		j;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	while (j < 265)
	{
		line = get_next_line(fd);
		printf("%s", line);
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