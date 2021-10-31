/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:16:27 by mfujishi          #+#    #+#             */
/*   Updated: 2021/10/31 18:57:23 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

// struct sigaction {
// 	void		(*sa_handler)(int);
// 	void		(*sa_sigaction)(int, siginfo_t *, void *);
// 	sigset_t	sa_mask;
// 	int			sa_flags;
// 	void		(*sa_restorer)(void);
// };

/*
int	server_check_client(char client[10], int count, char ascii)
{
	client[count] = ascii;
	if (count == 9)
	{
		write(1, "[", 1);
		ft_putstr_fd(client, 1);
		write(1, "]", 1);
	}
	return (count + 1);
}
*/

static int	server_sigtochar(char *c)
{
	int	ret;

	ret = 0;
	ret += (128 * (c[0] - '0'));
	ret += (64 * (c[1] - '0'));
	ret += (32 * (c[2] - '0'));
	ret += (16 * (c[3] - '0'));
	ret += (8 * (c[4] - '0'));
	ret += (4 * (c[5] - '0'));
	ret += (2 * (c[6] - '0'));
	ret += (1 * (c[7] - '0'));
	return (ret);
}

static int	server_send_client(pid_t client)
{
	kill(client, SIGUSR1);
	return (0);
}

static void	server_check(int sig, siginfo_t *siginfo, void *idk)
{
	int			ascii;
	static char	c[8];
	static int	num = 0;
	static int	count = 0;

	(void)idk;
	if (sig == SIGUSR1)
		c[num] = '0';
	else if (sig == SIGUSR2)
		c[num] = '1';
	num++;
	if (num == 8)
	{
		num = 0;
		ascii = server_sigtochar(c);
		write(1, &ascii, 1);
		if (ascii == '\0')
			count = server_send_client(siginfo->si_pid);
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_putnbr_fd(getpid(), 2);
	write(1, "\n", 1);
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = server_check;
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		return (0);
	else if (sigaction(SIGUSR2, &sig, NULL) == -1)
		return (0);
	while (1)
		pause();
}
