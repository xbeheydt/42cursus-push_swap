/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:44:25 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdarg.h>
# include <stdint.h>

# define RIGHT MINUS
# define LEFT 0
# define UINT_MASK 0x00000000ffffffff

typedef enum e_rmode
{
	RUN		= 1,
	DRYRUN	= -1,
	NOP		= 0
}	t_rmode;

typedef enum e_conv
{
	ERROR	= -1,
	PERCENT	= '%',
	CHAR	= 'c',
	STR		= 's',
	INT		= 'i',
	DEC		= 'd',
	UINT	= 'u',
	PTR		= 'p',
	HEXL	= 'x',
	HEXU	= 'X'
}	t_conv;

typedef enum e_flag
{
	ZERO	= '0',
	MINUS	= '-',
	PLUS	= '+',
	DOT		= '.',
	DASH	= '#',
	SPC		= ' '
}	t_flag;

typedef struct s_fmt
{
	t_conv	conv;
	char	dir;
	char	dash;
	char	sign;
	char	tpad;
	int		pad;
	int		prec;
	char	dot;
}	t_fmt;

typedef unsigned long	t_ulong;

/* parser{_bonus}.c */
int		conv_dispatch(t_fmt f, va_list *args);
t_fmt	fmt_parser(const char **fmt, t_fmt f);

/* utils.c */
t_fmt	init_fmt(void);
int		ft_putpadding(char c, int size);

/* string.c */
int		printf_char(t_fmt f, char c);
int		printf_str(t_fmt f, const char *s);

/* integer.c */
int		printf_uint(t_fmt f, unsigned int n);
int		printf_int(t_fmt f, int n);

/* hexadecimal.c */
int		printf_hex(t_fmt f, unsigned int n);
int		printf_hex_alt(t_fmt f, t_ulong n);

#endif /* FT_PRINTF_INTERNAL_H */
