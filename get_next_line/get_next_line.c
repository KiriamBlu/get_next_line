/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:50:13 by jbernard          #+#    #+#             */
/*   Updated: 2021/08/31 20:50:15 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 20

int		ft_findchar(char *str, char c)
{
	/* Returns -1 if no \n, index of \n if there is one */
	int i;

	i = -1;
	while (str[++i] != c)
	{	
		// If looking for \0 and \0 is next char
		if (c == '\0' && str[i + 1] == 0)
			return (i + 1);

		// If next char is \0 and didn't find char
		else if (str[i + 1] == 0)
			return (-1);
	}
	return (i);
}

char	*ft_getbeforechar(char *s, char c)
{
	size_t	len;
	int 	i;
	char	*ret;

	/* get length up to c */
	len = 0;
	while(s[len] != c && s[len])
		len++;

	/* allocate memory for string return */
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);

	/* copy string until c */
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = s[i];
	ret[++i] = '\0';

	/* return ret */
	return (ret);
}

char	*ft_getafterchar(char *s, char c, int end)
{
	int 	start;
	int		i;
	char	*ret;

	// Get len before first \n
	start = ft_findchar(s, c) + 1;
	//printf("Start : %d\nEnd : %d\nDifference : %d\n\n", start, end, (end - start));

	// Allocate memory for ret
	ret = (char	*)malloc(sizeof(char) * (end - start));
	if (!ret)
		return (NULL);

	// Copy string from first \n to last char
	i = 0;
	while (start < end)
		ret[i++] = s[start++];
	ret[i] = '\0';

	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			is_reading;
	
	// if (save)
	// {
	// 	line = ft_strdup(save);
	// 	save = NULL;
	// }

	is_reading = 1;
	while (is_reading)
	{
		// READ
		is_reading = read(fd, buffer, BUFFER_SIZE);
		
		if (is_reading == 0 && line)
			return (line);
		// If reading nothing -> Returns Null
		if (is_reading == -1 || is_reading == 0)
			return (NULL);
		
		//Add \0 at end of buffer
		buffer[is_reading] = '\0';

		//If reading for less then BUFFER_SIZE
		if (is_reading < BUFFER_SIZE)
			return (line);

		// If buffer contains \n
		if (ft_findchar(buffer, '\n') >= 0)
		{	
			// Get before \n
			if(!line)
				line = "";
			line = ft_stradd(line, ft_getbeforechar(buffer, '\n'));
			// Put leftovers in static
			save = ft_getafterchar(buffer, '\n', is_reading);
			// Return line
			return (line);
		}
		else
		{
			if(!line)
				line = "";
			line = ft_stradd(line, buffer);
		}
	}
	return ("Unknown Case #2");
}


