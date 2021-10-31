/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:16:27 by mfujishi          #+#    #+#             */
/*   Updated: 2021/10/31 18:57:35 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	client_error(int argc)
{
	if (argc == 1 || argc == 2)
		write(1, "can't find message ", 19);
	else if (3 < argc)
		write(1, "many message ", 13);
	write(1, "please \"./client server_pid message\".\n", 38);
	exit(1);
}

void	client_finish(int sig, siginfo_t *siginfo, void *idk)
{
	(void)sig;
	(void)siginfo;
	(void)idk;
	exit (0);
}
