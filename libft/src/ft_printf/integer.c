/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:44:25 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include <libft.h>

/* Private functions */

static void	parse_pad_int(t_fmt *f, long n, t_conv conv)
{
	int	n_len;

	n_len = 0;
	if (conv == INT || conv == DEC)
		n_len = -(ft_putnbr_fd(n, DRYRUN, NOP)) + (n < 0 || f->sign);
	else if (conv == UINT)
	{
		n_len = -(ft_putunbr_fd(n & UINT_MASK, DRYRUN));
		f->sign = 0;
	}
	f->prec -= n_len - (n < 0 || f->sign);
	if (f->prec < 0)
		f->prec = 0;
	if (f->dot)
	{
		f->tpad = SPC;
		f->pad -= f->prec + n_len;
	}
	else if (f->tpad == SPC)
		f->pad -= n_len;
	else if (f->tpad == ZERO)
	{
		f->prec = f->pad - n_len;
		f->pad = 0;
	}
}

static int	printf_int_null(t_fmt f, int n)
{
	f.pad -= (f.sign != 0);
	if (f.dir == LEFT)
		return (ft_putpadding(SPC, f.pad)
			+ ((n < 0) && ft_putchar_fd(MINUS, RUN))
			+ (f.sign && (n >= 0) && ft_putchar_fd(f.sign, RUN))
			+ ft_putpadding(ZERO, f.prec));
	return (((n < 0) && ft_putchar_fd(MINUS, RUN))
		+ (f.sign && (n >= 0) && ft_putchar_fd(f.sign, RUN))
		+ ft_putpadding(ZERO, f.prec)
		+ ft_putpadding(SPC, f.pad));
}

/* Internal API */

int	printf_uint(t_fmt f, unsigned int n)
{
	if (!n && !f.prec)
		return (printf_int_null(f, n));
	parse_pad_int(&f, n, f.conv);
	if (f.dir == LEFT)
		return (ft_putpadding(SPC, f.pad)
			+ (f.sign && ft_putchar_fd(f.sign, RUN))
			+ ft_putpadding(ZERO, f.prec) + ft_putunbr_fd(n, RUN));
	return ((f.sign && ft_putchar_fd(f.sign, RUN))
		+ ft_putpadding(ZERO, f.prec) + ft_putunbr_fd(n, RUN)
		+ ft_putpadding(SPC, f.pad));
}

int	printf_int(t_fmt f, int n)
{
	if (!n && !f.prec)
		return (printf_int_null(f, n));
	parse_pad_int(&f, n, f.conv);
	if (f.dir == LEFT)
		return (ft_putpadding(SPC, f.pad)
			+ ((n < 0) && ft_putchar_fd(MINUS, RUN))
			+ (f.sign && (n >= 0) && ft_putchar_fd(f.sign, RUN))
			+ ft_putpadding(ZERO, f.prec) + ft_putnbr_fd(n, RUN, NOP));
	return (((n < 0) && ft_putchar_fd(MINUS, RUN))
		+ (f.sign && (n >= 0) && ft_putchar_fd(f.sign, RUN))
		+ ft_putpadding(ZERO, f.prec) + ft_putnbr_fd(n, RUN, NOP)
		+ ft_putpadding(SPC, f.pad));
}
