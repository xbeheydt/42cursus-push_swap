/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:30:32 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 09:41:09 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*end;

	end = (char *)s;
	while (*++end)
		;
	if ((s + start) >= end)
	{
		start = 0;
		len = 0;
	}
	else if (len > (size_t)(end - (s + start)))
		len = (size_t)(end - (s + start));
	++len;
	ret = malloc((len) * sizeof(char));
	if (ret)
		ft_strlcpy(ret, (s + start), len);
	return (ret);
}
