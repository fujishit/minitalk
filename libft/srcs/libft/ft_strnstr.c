/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi </var/mail/mfujishi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:07:05 by mfujishi          #+#    #+#             */
/*   Updated: 2021/10/19 18:07:05 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		n = 0;
		while (haystack[i + n] == needle[n] && i + n < len && haystack[i + n])
		{
			n++;
			if (needle[n] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
