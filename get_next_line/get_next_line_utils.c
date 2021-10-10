/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:52:37 by jbernard          #+#    #+#             */
/*   Updated: 2021/08/31 20:52:38 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	len_str;
	size_t	i;

	// Get size and allocate memory
	len_str = ft_strlen(str);
	ptr = malloc(sizeof(char) * len_str + 1);
	if (!ptr)
		return (0);

	// Duplicating str into newly allocated str 
	i = 0;
	while (len_str--)
		ptr[i++] = *str++;
	ptr[i] = '\0';

	return (ptr);
}

char	*ft_stradd(char *s1, char *s2)
{
	char	*ptr;
	size_t	len;
	size_t i;
	size_t j;

	printf("OK1");
	// Get size and allocate memory
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char	*)malloc(sizeof(char) * len);
	if (!ptr)
		return (0);

	printf("OK2");
	// Copy s1 string into new string
	i = -1;
	while (s1[++i])
	{
		ptr[i] = s1[i];	
	}

	printf("OK3");
	// Concatenate s2 into new string
	j = 0;
	while (s2[j] && i < len - 1)
	{
		ptr[i++] = s2[j++];
	}
	ptr[--i] = '\0';
	return (ptr);
}
