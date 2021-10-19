/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi </var/mail/mfujishi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:07:04 by mfujishi          #+#    #+#             */
/*   Updated: 2021/10/19 18:07:04 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ret;

	ret = ft_strlen(dst);
	if (ret >= size)
		return (ft_strlen(src) + size);
	else
		ret += ft_strlen(src);
	while (--size && *dst != '\0')
		dst++;
	while (size-- && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (ret);
}
