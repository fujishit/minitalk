#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"
# include <signal.h>

void	client_error(int argc);
void	client_finish(int sig, siginfo_t *siginfo, void *idk);

#endif /* CLIENT_H */
