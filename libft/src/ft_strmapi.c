/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 08:15:38 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 08:29:35 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	size_t			len;
	unsigned int	i;

	len = ft_strlen(s);
	i = 0;
	ret = (char *)malloc((len + 1) * sizeof(char));
	while (ret && i < len)
	{
		ret[i] = f(i, s[i]);
		++i;
	}
	ret[i] = '\0';
	return (ret);
}
