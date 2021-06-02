#include "client.h"

void	client_send(pid_t pid, int sig)
{
	if (sig == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
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

int		main(int argc, char *argv[])
{
	int		sig[8];
	pid_t	server;
	size_t	i;

	if (argc == 1)
		return (1);
	server = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		client_atosig(argv[2][i], sig);
		client_send(server, sig[0]);
		client_send(server, sig[1]);
		client_send(server, sig[2]);
		client_send(server, sig[3]);
		client_send(server, sig[4]);
		client_send(server, sig[5]);
		client_send(server, sig[6]);
		client_send(server, sig[7]);
		i++;
	}
}
