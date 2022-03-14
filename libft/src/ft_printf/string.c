/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:44:25 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include <libft.h>

#define NULLSTR "(null)"

/* Private functions */

static int	ft_putsubstr(const char *s, size_t size)
{
	int	len;

	len = 0;
	if (s && *s && size)
	{
		len = ft_putchar_fd(*s, RUN);
		len += ft_putsubstr(++s, --size);
	}
	return (len);
}

/* Internal API */

int	printf_char(t_fmt f, char c)
{
	int	len;

	len = 0;
	if (f.tpad == ZERO)
	{
		len = ft_putpadding(ZERO, f.pad - 1);
		f.pad = 0;
	}
	if (f.dir == LEFT)
		return (len + ft_putpadding(SPC, f.pad - 1) + ft_putchar_fd(c, RUN));
	return (len + ft_putchar_fd(c, RUN) + ft_putpadding(SPC, f.pad - 1));
}

int	printf_str(t_fmt f, const char *s)
{
	int	s_len;

	if (s)
		s_len = ft_strlen(s);
	else
		s_len = ft_strlen(NULLSTR);
	if (f.dot && f.conv == STR && f.prec < s_len)
		s_len = f.prec;
	if (s == NULL && f.dir == LEFT)
		return (ft_putpadding(SPC, f.pad - s_len)
			+ ft_putsubstr(NULLSTR, s_len));
	if (s == NULL)
		return (ft_putsubstr(NULLSTR, s_len)
			+ ft_putpadding(SPC, f.pad - s_len));
	if (f.dir == LEFT)
		return (ft_putpadding(SPC, f.pad - s_len) + ft_putsubstr(s, s_len));
	return (ft_putsubstr(s, s_len) + ft_putpadding(SPC, f.pad - s_len));
}
