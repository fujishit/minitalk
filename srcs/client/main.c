#include "client.h"

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (1);
	kill(ft_atoi(argv[1]), SIGUSR1);
	kill(ft_atoi(argv[1]), SIGUSR2);
}
