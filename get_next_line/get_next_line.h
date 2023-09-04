#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char *get_next_line(int fd);
char *read_to_n(int fd, char *save);
char *final_line(char *save_line);
char *remainder_chars(char *save_line);
char *join_read(char *save_line, char *buf);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *str, unsigned long int n);

#endif