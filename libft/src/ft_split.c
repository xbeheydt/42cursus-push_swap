/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:39:09 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/15 15:06:26 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int	ft_countword(char const *str, char c)
{
	int	ret;
	int	word;

	word = 0;
	ret = 0;
	while (*str)
	{
		if (*str == c)
			word = 0;
		if (word == 0 && *str != c)
		{
			word = 1;
			++ret;
		}
		++str;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char		**ret;
	char const	*start;
	int			count;
	int			i;

	i = 0;
	while (*s == c && *s && c != 0)
		++s;
	start = s++;
	count = ft_countword(start, c);
	ret = malloc((count + 1) * sizeof(char *));
	while (i < count && ret)
	{
		if (*start == c)
			++start;
		else
		{
			s = ft_strchr(start, c);
			ret[i] = ft_substr(start, 0, s - start);
			start = ++s;
			++i;
		}
	}
	ret[i] = NULL;
	return (ret);
}
