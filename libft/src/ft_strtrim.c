/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:38:26 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 09:40:48 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_setcmp(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static char	*ft_lastchr(char const *s)
{
	while (*s)
		++s;
	return ((char *)--s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;

	start = (char *)s1;
	end = ft_lastchr(s1);
	if (end - start == 0)
		return (ft_strdup(s1));
	while (ft_setcmp(*start, set))
		++start;
	while (ft_setcmp(*end, set))
		--end;
	return (ft_substr(s1, start - s1, end - start + 1));
}
