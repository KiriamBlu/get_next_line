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

char	*ft_chartostr(const char *buffer, const char *auxline, size_t len)
{
	char	*ptr;
	size_t i;
	size_t j;

	if(!auxline || !buffer)
		return(NULL);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (buffer[i])
	{		
		ptr[i] = buffer[i];	
		i++;
	}
	j = 0;
	while (auxline[j] && i < len - 1)
		ptr[i++] = auxline[j++];
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_beforejump(const char *save)
{
	char	*beforebuff;
	char	*aux;
	ssize_t	i;
	ssize_t	j;
	ssize_t len;

	i = 0;
	j = 0;

	aux = (char *)save;
	if(!aux)
		return(NULL);
	len = ft_strlen(aux);
	while(i < len)
	{	
		if (aux[i] == '\n')
		{
			beforebuff = ft_substr(aux, 0, i + 1);
			return(beforebuff);
		}
		i++;
	}
	return(NULL);
}

char *ft_substr(const char *s, unsigned int start, size_t len)
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

char *ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if (!s)
		return(NULL);
	while (s[i] && s[i] != (char)c)
	{
		i++;
		if (s[i] == '\0' && c != 0)
		return (NULL);
	}
	return ((char *)s + i + 1);
}






