/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:43:21 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/05 13:47:21 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*cs;

	cs = (char *)s;
	while (n--)
		if (*cs++ == (unsigned char)c)
			return ((void *)cs - 1);
	return (NULL);
}
