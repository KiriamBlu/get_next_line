#include "get_next_line.h"

void	ft_strdel(char **saved)
{
	if (saved != NULL)
	{
		free(*saved);
		*saved = NULL;
	}
}

char *get_next_line(int fd)
{
	ssize_t		count;
	char		*buffer;
	char		*auxline;	
	static char	*save[4096];

	auxline = ft_strdup(" ");
	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!save[fd])
	{
		if(read(fd, buffer, BUFFER_SIZE))
		{
			auxline = ft_chartostr(ft_beforejump(buffer), auxline);
			if (!auxline)
			{
				ft_strdel(&auxline);
				return(NULL);
			}
			save[fd] = ft_strchr(buffer, '\n');
			return(auxline);
		}
		else
			return(NULL);
	}
	else
	{
		if(read(fd, buffer, BUFFER_SIZE))
		{
			auxline = ft_chartostr(ft_beforejump(buffer), auxline);
			if (!auxline)
			{
				ft_strdel(&auxline);
				return(NULL);
			}
			auxline =ft_chartostr(save[fd], auxline);
			save[fd] = ft_strchr(buffer, '\n');
			if (!save[fd])
				ft_strdel(save);
			return(auxline);
		}
		else
			return(NULL);
	}
	return(NULL);
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