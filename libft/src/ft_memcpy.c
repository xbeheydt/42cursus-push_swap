/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:14:11 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/05 13:33:27 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*usrc;
	unsigned char	*udst;

	usrc = (unsigned char *)src;
	udst = (unsigned char *)dst;
	if (n)
		while (n--)
			*udst++ = *usrc++;
	return (dst);
}
