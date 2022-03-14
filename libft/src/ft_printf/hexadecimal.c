/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
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

static void	parse_pad_hex(t_fmt *f, t_ulong n, int prefix)
{
	int	n_len;

	n_len = -(ft_puthnbr_fd(n, DRYRUN, 0)) + prefix;
	f->prec -= n_len - prefix;
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

static int	printf_hex_alt_null(t_fmt f)
{
	f.pad -= 2;
	if (f.dir == LEFT)
		return (ft_putpadding(SPC, f.pad)
			+ ((f.conv == PTR || f.conv == HEXL) && ft_putstr_fd("0x", RUN))
			+ (f.conv == HEXU && ft_putstr_fd("0X", RUN)) + 1
			+ ft_putpadding(ZERO, f.prec));
	return (ft_putpadding(ZERO, f.prec)
		+ ((f.conv == PTR || f.conv == HEXL) && ft_putstr_fd("0x", RUN))
		+ (f.conv == HEXU && ft_putstr_fd("0X", RUN)) + 1
		+ ft_putpadding(SPC, f.pad));
}

/* Internal API */

int	printf_hex(t_fmt f, unsigned int n)
{
	if (f.dash)
		return (printf_hex_alt(f, n));
	if (!n && !f.prec && f.dir == LEFT)
		return (ft_putpadding(SPC, f.pad) + ft_putpadding(ZERO, f.prec));
	else if (!n && !f.prec)
		return (ft_putpadding(ZERO, f.prec) + ft_putpadding(SPC, f.pad));
	parse_pad_hex(&f, n, 0);
	if (f.dir == LEFT)
		return (ft_putpadding(SPC, f.pad)
			+ ft_putpadding(ZERO, f.prec)
			+ ft_puthnbr_fd(n, RUN, f.conv == HEXU));
	return (ft_putpadding(ZERO, f.prec)
		+ ft_puthnbr_fd(n, RUN, f.conv == HEXU)
		+ ft_putpadding(SPC, f.pad));
}

int	printf_hex_alt(t_fmt f, t_ulong n)
{
	if ((f.conv == HEXL || f.conv == HEXU) && !n)
	{
		f.dash = 0;
		return (printf_hex(f, n));
	}
	if (!n && !f.prec)
		return (printf_hex_alt_null(f));
	parse_pad_hex(&f, n, 2);
	if (f.dir == LEFT)
		return (ft_putpadding(SPC, f.pad)
			+ ((f.conv == PTR || f.conv == HEXL) && ft_putstr_fd("0x", RUN))
			+ (f.conv == HEXU && ft_putstr_fd("0X", RUN)) + 1
			+ ft_putpadding(ZERO, f.prec)
			+ ft_puthnbr_fd(n, RUN, f.conv == HEXU));
	return (ft_putpadding(ZERO, f.prec)
		+ ((f.conv == PTR || f.conv == HEXL) && ft_putstr_fd("0x", RUN))
		+ (f.conv == HEXU && ft_putstr_fd("0X", RUN)) + 1
		+ ft_puthnbr_fd(n, RUN, f.conv == HEXU)
		+ ft_putpadding(SPC, f.pad));
}
