#include "get_next_line.h"

char *ft_getline(int fd, char **save)
{
	char *a;
	char *ai;
	ssize_t num;

	a = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if(!a)
		return(NULL);
	if (*save)
	{
		if(!ft_beforejump(*save))
		{
			read(fd, a, BUFFER_SIZE);
			num = ft_strlen(*save) + ft_strlen(ft_beforejump(a));
			ai = (char *)malloc(sizeof(char) * num + 1);
			
			ai = ft_chartostr(*save, ft_beforejump(a));
			
			printf("%s\n", a);
			ai[num] = '\0';
			*save = ft_substr(a, ft_strchr(a, '\n') - a + 1, BUFFER_SIZE);
		}
		else
		{
			num = ft_strlen(ft_beforejump(*save));
			ai = (char *)malloc(sizeof(char) * num + 1);
			ai = ft_chartostr(ft_beforejump(*save), a);
			ai[num] = '\0';
			a = *save;
			free(*save);
			*save = ft_strchr(a, '\n');
		}
	}
	else
	{
		num = read(fd, a, BUFFER_SIZE);
		ai = ft_substr(a, 0, ft_strchr(a, '\n') - a);
		*save = ft_substr(a, ft_strchr(a, '\n') - a + 1, BUFFER_SIZE);
	}
	return (ai);
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
	while (j < 3)
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