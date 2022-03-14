/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:40:32 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/08 10:51:20 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ucs1;
	char	*ucs2;

	ucs1 = (char *)s1;
	ucs2 = (char *)s2;
	while (n--)
		if (*ucs1++ != *ucs2++)
			return (*(unsigned char *)--ucs1 - *(unsigned char *)--ucs2);
	return (0);
}
