/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:41:28 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/08 12:02:16 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*c_src;
	char		*c_dst;

	c_src = (const char *)src;
	c_dst = (char *)dst;
	if (c_src < c_dst)
	{
		c_src += len;
		c_dst += len;
		while (len--)
			*--c_dst = *--c_src;
	}
	else
		while (len--)
			*c_dst++ = *c_src++;
	return (dst);
}
