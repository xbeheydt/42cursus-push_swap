/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:22:23 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/05 13:04:39 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ub;

	ub = (unsigned char *)b;
	while (len--)
		*ub++ = (unsigned char)c;
	return (b);
}
