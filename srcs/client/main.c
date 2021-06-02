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
		usleep(100);
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
		client_send(server, sig);
		i++;
	}
	client_atosig('\n', sig);
	client_send(server, sig);
}
