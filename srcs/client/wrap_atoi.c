/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi </var/mail/mfujishi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:07:16 by mfujishi          #+#    #+#             */
/*   Updated: 2021/10/17 22:31:45 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int	wrap_atoi(const char *nptr, int *num)
{
	int	i;
	int	negative;

	i = 0;
	negative = -1;
	*num = 0;
	if (*nptr == '-')
		negative = 1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		*num = *num * 10 - (nptr[i++] - '0');
		if (((*num <= -214748364 && 7 < nptr[i] - '0') || 10 < i) && \
			negative == -1)
			return (1);
		if (((*num <= -214748364 && 8 < nptr[i] - '0') || 10 < i) && \
			negative == 1)
			return (1);
	}
	if (nptr[i] != '\0')
		return (1);
	*num = *num * negative;
	return (0);
}
