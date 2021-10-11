#include "get_next_line.h"

ssize_t	ft_strlen(const char *c)
{
	unsigned int	i;

	i = 0;
	if (!c)
		return (0);
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
	i = 0;
	if(buffer)
	{
		while (buffer[i])
		{		
			ptr[i] = buffer[i];	
			i++;
		}
	}
	j = 0;
	while (auxline[j] && i < len - 1)
		ptr[i++] = auxline[j++];	
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_beforejump(char **save)
{
	char	*beforebuff;
	ssize_t	i;
	ssize_t	j;
	ssize_t len;

	i = 0;
	j = 0;
	len = ft_strlen(*save);
	if(!*save)
		return(NULL);
	while(*save[i] != '\n' && *save[i] != '\0')
		i++;
	beforebuff = ft_substr(*save, 0, (i + 1));
	*save = ft_substr(*save, (i + 1), len);
	return(beforebuff);
}

char *ft_substr(char *s, unsigned int start, size_t len)
{
	char *a;
	size_t i;
	size_t	lens;

	lens = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (start >= lens)
		len = 0;
	if (len > lens)
		len = lens;
	a = (char *)malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	while (i < len && s[start + i])
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
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





