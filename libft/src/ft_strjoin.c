/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:26:58 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/08 15:36:24 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(len * sizeof(char));
	str = ret;
	while (ret && *s1)
		*str++ = *s1++;
	while (ret && *s2)
		*str++ = *s2++;
	*str = '\0';
	return (ret);
}
