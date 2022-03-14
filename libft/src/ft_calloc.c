/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:02:03 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/08 14:09:12 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	tsize;

	ret = NULL;
	tsize = size * count;
	if (count && size != (tsize / count))
		return (ret);
	ret = malloc(size * count);
	if (ret)
		ft_bzero(ret, tsize);
	return (ret);
}
