#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char *get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
ssize_t	ft_strlen(const char *c);
char	*ft_beforejump(const char *aux);
ssize_t ft_findjump(char *buffer, int c);
char	*ft_strchr(const char *s, int c);
char *ft_substr(const char *s, unsigned int start, size_t len);


# endif