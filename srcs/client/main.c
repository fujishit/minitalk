/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:16:27 by mfujishi          #+#    #+#             */
/*   Updated: 2021/10/31 19:01:14 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	client_send(pid_t pid, int sig[8])
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (sig[i] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(WAIT_TIME);
	}
}

void	client_atosig(unsigned char c, int sig[8])
{
	sig[7] = c % 2;
	c = c / 2;
	sig[6] = c % 2;
	c = c / 2;
	sig[5] = c % 2;
	c = c / 2;
	sig[4] = c % 2;
	c = c / 2;
	sig[3] = c % 2;
	c = c / 2;
	sig[2] = c % 2;
	c = c / 2;
	sig[1] = c % 2;
	c = c / 2;
	sig[0] = c % 2;
}

void	client_send_args(int argc, char *argv[], pid_t server, int sig[8])
{
	int		i;
	size_t	n;

	i = 2;
	n = 0;
	while (argv[i][n] != '\0')
	{
		client_atosig(argv[i][n], sig);
		client_send(server, sig);
		n++;
	}
	i++;
	while (i < argc)
	{
		n = 0;
		client_atosig(' ', sig);
		client_send(server, sig);
		while (argv[i][n] != '\0')
		{
			client_atosig(argv[i][n], sig);
			client_send(server, sig);
			n++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int					sig[8];
	pid_t				server;
	struct sigaction	sigact;

	if (argc < 3)
		client_error(argc);
	if (wrap_atoi(argv[1], &server) == 1 || server <= 0)
	{
		write(1, "invalid pid\n", 12);
		return (1);
	}
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = client_finish;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		return (1);
	client_send_args(argc, argv, server, sig);
	client_atosig('\0', sig);
	client_send(server, sig);
}
