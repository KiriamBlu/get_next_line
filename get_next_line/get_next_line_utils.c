#include "get_next_line.h"

ssize_t	ft_strlen(const char *c)
{
	unsigned int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_chartostr(char *buffer, char *auxline)
{
	char	*ptr;
	size_t	len;
	size_t i;
	size_t j;

	len = ft_strlen(buffer) + ft_strlen(auxline) + 1;
	ptr = (char	*)malloc(sizeof(char) * len);
	if (!ptr)
		return (NULL);
	i = -1;
	while (buffer[++i])
		ptr[i] = buffer[i];	
	j = 0;
	while (auxline[j] && i < len - 1)
		ptr[i++] = auxline[j++];
	ptr[i] = '\0';
	return (ptr);
}
char	*ft_beforejump(char *buffer)
{
	char	*beforebuff;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	if(!buffer)
		return(NULL);
	while(buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	beforebuff = (char *)malloc(sizeof(char) * i + 1);
	if(!beforebuff)
		return(NULL);
	while (j < i)
	{
		beforebuff[j] = buffer[j];
		j++;
	}
	beforebuff[j] = '\0';
	return(beforebuff);
}

ssize_t ft_findjump(char *buffer, int c)
{
	ssize_t j;

	if (!buffer)
		return (0);
	while (buffer[j] != '\0')
	{
		if (buffer[j] == (unsigned char)c)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return (s + i + 1);
	return (NULL);
}

char	*ft_strdup(const char *buffer)
{
	char	*aux;
	ssize_t	i;

	i = 0;
	aux = (char *)malloc(ft_strlen(buffer) + 1 * sizeof(char));
	if (!aux)
		return (NULL);
	while (buffer[i] != '\0')
	{
		aux[i] = buffer[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);

}





