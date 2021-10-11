#include "get_next_line.h"

void ft_getline(int fd, char **save, char *saved)
{
	char *aux;
	ssize_t num;

	aux = malloc(BUFFER_SIZE + 1);
	while ((!*save || !ft_strchr(*save, '\n')))
	{
		num = read(fd, aux, BUFFER_SIZE);
		if (num <= 0)
			return ;			
		aux[num] = '\0';
		if (!*save)
			*save = ft_chartostr(saved, aux);
		else
			*save = ft_strdup(aux);
	}
	free(aux);
	*save = ft_strdup("ME CAGO EN DIOS");
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
	if (save[fd])
	{
		if (!(ft_strchr(auxline, '\n')))
		{
			//no pasa por referencia cuando deberia debido a que si devuelve correctamente.
			ft_getline(fd, &(save[fd]), save[fd]);
			printf("%s\n", save[fd]);
			auxline = ft_beforejump(&save[fd]);
		}
	}
	else
	{
		ft_getline(fd, &save[fd], save[fd]);
		if(!(ft_freesave(&save[fd])))
			return(NULL);
		auxline = ft_beforejump(&save[fd]);
	}
	return (auxline);
}

 

int main()
{
	int 	fd;
	int		fd2;
	char	*line;
	int		j;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	while (j < 1)
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