#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"
# include <signal.h>

# define WAIT_TIME 150

void	client_error(int argc);
void	client_finish(int sig, siginfo_t *siginfo, void *idk);
int		wrap_atoi(const char *nptr, int *num);

#endif /* CLIENT_H */
