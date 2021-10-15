#include "get_next_line.h"

char *lastlane(char **save)
{
	char *ai;

	ai = ft_substr(*save, 0, ft_strlen(*save) + 1);
	*save = ft_substr("", 0, 0);
	return(ai);
}

char *preparea(int fd, char **save, ssize_t num)
{
	char	*a;
	char	*ai;

	a = malloc(num * sizeof(char) + 1);
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
char *ai;
char *aux;
ssize_t num;

while(!ft_beforejump(*save) && read(fd, aux, BUFFER_SIZE))
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
	}
}
if(!read(fd, aux, BUFFER_SIZE) && !ft_strchr(*save, '\n'))
	return(lastlane(&(*save)));
return(preparea(fd, &(*save), num));
}

char *get_next_line(int fd)
{
	static char	*save[4096];
	char *a;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
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

	j = 0;
	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	while (j < 1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		j++;
	}
	j = 0;
	while (j < 2)
	{
		line = get_next_line(fd2);
		printf("%s", line);
		j++;
	}
	return(0);
}