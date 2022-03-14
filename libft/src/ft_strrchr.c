/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:32:07 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/08 12:17:47 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	while (*s)
		if ((char)c == *s++)
			ret = (char *)s - 1;
	if (c == 0)
		ret = (char *) s;
	return (ret);
}
