/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:44:25 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "ft_printf_internal.h"
#include <stddef.h>
#include <unistd.h>

/* Public API */

int	ft_printf(const char *format, ...)
{
	size_t	len;
	va_list	args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == PERCENT)
			len += conv_dispatch(fmt_parser(&format, init_fmt()), &args);
		else
			len += write(1, format, 1);
		if (*format)
			format++;
	}
	va_end(args);
	return (len);
}
