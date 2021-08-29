#ifndef MYLIB_H
# define MYLIB_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		ft_strcmp(const char *s1, const char *s2);
int		ft_isint(char *num);
void	ft_heapsort(int *array, int len);
void	ft_swap(int *a, int *b);

#endif
