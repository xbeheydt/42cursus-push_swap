/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:17:07 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/04 13:19:19 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	const char	*count;

	count = s;
	while (*count++)
		;
	return ((size_t)(count - s - 1));
}
