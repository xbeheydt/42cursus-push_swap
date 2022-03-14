/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:44:25 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include <libft.h>
#include <stdarg.h>

/* Private functions */

static int	pad_atoi(const char **fmt, int i)
{
	if (ft_isdigit(*(*fmt)))
	{
		i *= 10;
		i += (*(*fmt) - '0');
		++(*fmt);
		i = pad_atoi(fmt, i);
	}
	return (i);
}

static int	conv_parser(char conv, t_fmt *f)
{
	if (conv == PERCENT || conv == CHAR || conv == STR
		|| conv == INT || conv == DEC || conv == UINT
		|| conv == PTR || conv == HEXL || conv == HEXU)
	{
		f->conv = conv;
		return (1);
	}
	if (conv == '\0')
	{
		return (-1);
	}
	return (0);
}

/* Internal API */

t_fmt	fmt_parser(const char **fmt, t_fmt f)
{
	++(*fmt);
	if (*(*fmt) == DASH)
		f.dash = DASH;
	else if (*(*fmt) == MINUS)
	{
		f.dir = RIGHT;
		f.tpad = SPC;
	}
	else if (f.dir != MINUS && *(*fmt) == ZERO)
		f.tpad = ZERO;
	else if (*(*fmt) == PLUS)
		f.sign = PLUS;
	else if (f.sign != PLUS && *(*fmt) == SPC)
		f.sign = SPC;
	if (*(*fmt) != ZERO && *(*fmt) != DOT && ft_isdigit(*(*fmt)))
		f.pad = pad_atoi(fmt, 0);
	if (*(*fmt) == DOT)
	{
		f.dot = *(*fmt)++;
		f.prec = pad_atoi(fmt, 0);
	}
	if (conv_parser(*(*fmt), &f))
		return (f);
	return (fmt_parser(fmt, f));
}

int	conv_dispatch(t_fmt f, va_list *args)
{
	if (f.conv == PERCENT)
		return (printf_char(f, PERCENT));
	else if (f.conv == CHAR)
		return (printf_char(f, (char)va_arg((*args), int)));
	else if (f.conv == STR)
		return (printf_str(f, (char *)va_arg((*args), char *)));
	else if (f.conv == UINT)
		return (printf_uint(f, (unsigned int)va_arg((*args), int)));
	else if (f.conv == INT || f.conv == DEC)
		return (printf_int(f, (int)va_arg((*args), int)));
	else if (f.conv == HEXL || f.conv == HEXU)
		return (printf_hex(f, (unsigned int)va_arg((*args), int)));
	else if (f.conv == PTR)
		return (printf_hex_alt(f, (t_ulong)va_arg((*args), uintptr_t)));
	return (0);
}
