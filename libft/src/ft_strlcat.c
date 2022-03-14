/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:54:55 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/04 13:18:14 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		size;
	size_t		dlen;

	d = dst;
	s = src;
	size = dstsize;
	while (size-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	size = dstsize - dlen;
	if (size == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (size != 1)
		{
			*d++ = *s;
			size--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
