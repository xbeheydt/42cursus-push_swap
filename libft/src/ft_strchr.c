/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:00:39 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/08 12:15:05 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if ((char)c == *s++)
			return ((char *)s - 1);
	if ((char)c == 0)
		return ((char *)s);
	return (NULL);
}
