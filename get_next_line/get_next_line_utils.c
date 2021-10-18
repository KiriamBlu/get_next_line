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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*(s1 + i) != '\0')
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	j = 0;
	free((void *)s1);
	while (*(s2 + j) != '\0')
	{
		*(str + i + j) = *(s2 + j);
		j++;
	}
	free((void *)s2);
	str[i + j] = '\0';
	return (str);
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
	while (i < ft_strlen(s))
	{
		if(s[i] == (char)c)
			return ((char *)s + i + 1);
		i++;
	}
	return(NULL);
}






