/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi </var/mail/mfujishi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:07:04 by mfujishi          #+#    #+#             */
/*   Updated: 2021/10/19 18:07:04 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*ret;
	unsigned const char	*retsrc;
	size_t				i;

	ret = (unsigned char *)dest;
	retsrc = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		ret[i] = retsrc[i];
		if (ret[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
