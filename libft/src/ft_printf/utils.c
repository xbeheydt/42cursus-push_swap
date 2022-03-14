/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:44:25 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include <libft.h>
#include <stddef.h>

/* Internal API */

t_fmt	init_fmt(void)
{
	t_fmt	f;

	f.conv = ERROR;
	f.dir = LEFT;
	f.pad = 0;
	f.dot = 0;
	f.prec = 1;
	f.sign = 0;
	f.tpad = SPC;
	f.dash = 0;
	return (f);
}

int	ft_putpadding(char c, int size)
{
	int	len;

	len = 0;
	if (size <= 0)
		return (0);
	len += ft_putpadding(c, --size);
	return (len + ft_putchar_fd(c, RUN));
}
