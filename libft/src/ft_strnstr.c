/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:12:52 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/08 12:58:49 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strnstr(const char	*haystack, const char *needle, size_t len)
{
	size_t	lneedle;

	lneedle = ft_strlen(needle);
	if (lneedle == 0)
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (lneedle > len--)
			break ;
		if (ft_strncmp(haystack++, needle, lneedle) == 0)
			return ((char *)(--haystack));
	}
	return (NULL);
}
