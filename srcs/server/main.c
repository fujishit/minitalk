#include "server.h"

// struct sigaction {
// 	void		(*sa_handler)(int);
// 	void		(*sa_sigaction)(int, siginfo_t *, void *);
// 	sigset_t	sa_mask;
// 	int			sa_flags;
// 	void		(*sa_restorer)(void);
// };

int	main(void)
{
	//struct sigaction	sig;
	pid_t	pid;

	//sigemptyset(&sig.sa_mask);
	pid = getpid();
	write(1, "pid:", 4);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	pause();
	write(1, "ポーズ終了\n", 6);
}
