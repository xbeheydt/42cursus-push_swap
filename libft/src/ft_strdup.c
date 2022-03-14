/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:01:27 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/08 14:11:17 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	ret = malloc(len * sizeof(char) + 1);
	while (ret && i < len)
	{
		ret[i] = s1[i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}
