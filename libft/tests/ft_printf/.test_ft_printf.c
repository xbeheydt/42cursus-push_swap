/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:33:48 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:33:50 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <ft_printf.h>

#include <stdio.h>
#include <limits.h>
#include <string.h>

static int	ret1;
static int	ret2;
static char *str1;
static char *str2;

#define FT_PRINTF(fmt, ...) \
	catch_fd(1, 1); \
	ret1 = ft_printf(fmt, __VA_ARGS__); \
	str1 = catch_fd(0, 1); \
	catch_fd(1, 1); \
	ret2 = printf(fmt, __VA_ARGS__); \
	str2 = catch_fd(0, 1); \
	unit_test(ret1 == ret2, ""); \
	unit_test(memcmp(str1, str2, ret2) == 0, "");\
	free(str1); free(str2); str1 = NULL; str2 = NULL;

int	test_ft_printf_percent(void *args)
{
	(void)args;

	FT_PRINTF(" %% ", 1);
	FT_PRINTF(" %%%% ", 1);
	FT_PRINTF(" %% %% %% ", 1);
	FT_PRINTF(" %%  %%  %% ", 1);
	FT_PRINTF(" %%   %%   %% ", 1);
	FT_PRINTF("%%", 1);
	FT_PRINTF("%% %%", 1);

	return (OK);
}

int	test_ft_printf_c(void *args)
{;
	(void)args;

	FT_PRINTF("%c", '0');
	FT_PRINTF(" %c ", '0');
	FT_PRINTF(" %c", '0' - 256);
	FT_PRINTF("%c ", '0' + 256);
	FT_PRINTF(" %c %c %c ", '0', 0, '1');
	FT_PRINTF(" %c %c %c ", ' ', ' ', ' ');
	FT_PRINTF(" %c %c %c ", '1', '2', '3');
	FT_PRINTF(" %c %c %c ", '2', '1', 0);
	FT_PRINTF(" %c %c %c ", 0, '1', '2');

	return (OK);
}

int	test_ft_printf_s(void *args)
{
	(void)args;

	FT_PRINTF("%s", "");
	FT_PRINTF(" %s", "");
	FT_PRINTF("%s ", "");
	FT_PRINTF(" %s ", "");
	FT_PRINTF(" %s ", "-");
	FT_PRINTF(" %s %s ", "", "-");
	FT_PRINTF(" %s %s ", " - ", "");
	FT_PRINTF(" %s %s %s %s %s", " - ", "", "4", "", "Ipsum");
	FT_PRINTF(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	FT_PRINTF(" NULL %s NULL ", NULL);
	return (OK);
}

int	test_ft_printf_u(void *args)
{
	(void)args;

	FT_PRINTF(" %u ", 0);
	FT_PRINTF(" %u ", -1);
	FT_PRINTF(" %u ", 1);
	FT_PRINTF(" %u ", 9);
	FT_PRINTF(" %u ", 10);
	FT_PRINTF(" %u ", 11);
	FT_PRINTF(" %u ", 15);
	FT_PRINTF(" %u ", 16);
	FT_PRINTF(" %u ", 17);
	FT_PRINTF(" %u ", 99);
	FT_PRINTF(" %u ", 100);
	FT_PRINTF(" %u ", 101);
	FT_PRINTF(" %u ", -9);
	FT_PRINTF(" %u ", -10);
	FT_PRINTF(" %u ", -11);
	FT_PRINTF(" %u ", -14);
	FT_PRINTF(" %u ", -15);
	FT_PRINTF(" %u ", -16);
	FT_PRINTF(" %u ", -99);
	FT_PRINTF(" %u ", -100);
	FT_PRINTF(" %u ", -101);
	FT_PRINTF(" %u ", INT_MAX);
	FT_PRINTF(" %u ", INT_MIN);
	FT_PRINTF(" %u ", LONG_MAX);
	FT_PRINTF(" %u ", LONG_MIN);
	FT_PRINTF(" %u ", UINT_MAX);
	FT_PRINTF(" %u ", ULONG_MAX);
	FT_PRINTF(" %u ", 9223372036854775807LL);
	FT_PRINTF(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	return (OK);
}

int	test_ft_printf_i(void *args)
{
	(void)args;

	FT_PRINTF(" %i ", -1);
	FT_PRINTF(" %i ", 1);
	FT_PRINTF(" %i ", 9);
	FT_PRINTF(" %i ", 10);
	FT_PRINTF(" %i ", 11);
	FT_PRINTF(" %i ", 15);
	FT_PRINTF(" %i ", 16);
	FT_PRINTF(" %i ", 17);
	FT_PRINTF(" %i ", 99);
	FT_PRINTF(" %i ", 100);
	FT_PRINTF(" %i ", 101);
	FT_PRINTF(" %i ", -9);
	FT_PRINTF(" %i ", -10);
	FT_PRINTF(" %i ", -11);
	FT_PRINTF(" %i ", -14);
	FT_PRINTF(" %i ", -15);
	FT_PRINTF(" %i ", -16);
	FT_PRINTF(" %i ", -99);
	FT_PRINTF(" %i ", -100);
	FT_PRINTF(" %i ", -101);
	FT_PRINTF(" %i ", INT_MAX);
	FT_PRINTF(" %i ", INT_MIN);
	FT_PRINTF(" %i ", LONG_MAX);
	FT_PRINTF(" %i ", LONG_MIN);
	FT_PRINTF(" %i ", UINT_MAX);
	FT_PRINTF(" %i ", ULONG_MAX);
	FT_PRINTF(" %i ", 9223372036854775807LL);
	FT_PRINTF(" %i %i %i %i %i %i %i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	return (OK);
}

int	test_ft_printf_d(void *args)
{
	(void)args;

	FT_PRINTF(" %d ", -1);
	FT_PRINTF(" %d ", 1);
	FT_PRINTF(" %d ", 9);
	FT_PRINTF(" %d ", 10);
	FT_PRINTF(" %d ", 11);
	FT_PRINTF(" %d ", 15);
	FT_PRINTF(" %d ", 16);
	FT_PRINTF(" %d ", 17);
	FT_PRINTF(" %d ", 99);
	FT_PRINTF(" %d ", 100);
	FT_PRINTF(" %d ", 101);
	FT_PRINTF(" %d ", -9);
	FT_PRINTF(" %d ", -10);
	FT_PRINTF(" %d ", -11);
	FT_PRINTF(" %d ", -14);
	FT_PRINTF(" %d ", -15);
	FT_PRINTF(" %d ", -16);
	FT_PRINTF(" %d ", -99);
	FT_PRINTF(" %d ", -100);
	FT_PRINTF(" %d ", -101);
	FT_PRINTF(" %d ", INT_MAX);
	FT_PRINTF(" %d ", INT_MIN);
	FT_PRINTF(" %d ", LONG_MAX);
	FT_PRINTF(" %d ", LONG_MIN);
	FT_PRINTF(" %d ", UINT_MAX);
	FT_PRINTF(" %d ", ULONG_MAX);
	FT_PRINTF(" %d ", 9223372036854775807LL);
	FT_PRINTF(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	return (OK);
}

int	test_ft_printf_x(void *args)
{
	(void)args;

	FT_PRINTF(" %x ", 0);
	FT_PRINTF(" %x ", -1);
	FT_PRINTF(" %x ", 1);
	FT_PRINTF(" %x ", 9);
	FT_PRINTF(" %x ", 10);
	FT_PRINTF(" %x ", 11);
	FT_PRINTF(" %x ", 15);
	FT_PRINTF(" %x ", 16);
	FT_PRINTF(" %x ", 17);
	FT_PRINTF(" %x ", 99);
	FT_PRINTF(" %x ", 100);
	FT_PRINTF(" %x ", 101);
	FT_PRINTF(" %x ", -9);
	FT_PRINTF(" %x ", -10);
	FT_PRINTF(" %x ", -11);
	FT_PRINTF(" %x ", -14);
	FT_PRINTF(" %x ", -15);
	FT_PRINTF(" %x ", -16);
	FT_PRINTF(" %x ", -99);
	FT_PRINTF(" %x ", -100);
	FT_PRINTF(" %x ", -101);
	FT_PRINTF(" %x ", INT_MAX);
	FT_PRINTF(" %x ", INT_MIN);
	FT_PRINTF(" %x ", LONG_MAX);
	FT_PRINTF(" %x ", LONG_MIN);
	FT_PRINTF(" %x ", UINT_MAX);
	FT_PRINTF(" %x ", ULONG_MAX);
	FT_PRINTF(" %x ", 9223372036854775807LL);
	FT_PRINTF(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	FT_PRINTF(" %x ", 42);
	FT_PRINTF(" %x ", -42);

	return (OK);
}

int	test_ft_printf_X(void *args)
{
	(void)args;

	FT_PRINTF(" %X ", 0);
	FT_PRINTF(" %X ", -1);
	FT_PRINTF(" %X ", 1);
	FT_PRINTF(" %X ", 9);
	FT_PRINTF(" %X ", 10);
	FT_PRINTF(" %X ", 11);
	FT_PRINTF(" %X ", 15);
	FT_PRINTF(" %X ", 16);
	FT_PRINTF(" %X ", 17);
	FT_PRINTF(" %X ", 99);
	FT_PRINTF(" %X ", 100);
	FT_PRINTF(" %X ", 101);
	FT_PRINTF(" %X ", -9);
	FT_PRINTF(" %X ", -10);
	FT_PRINTF(" %X ", -11);
	FT_PRINTF(" %X ", -14);
	FT_PRINTF(" %X ", -15);
	FT_PRINTF(" %X ", -16);
	FT_PRINTF(" %X ", -99);
	FT_PRINTF(" %X ", -100);
	FT_PRINTF(" %X ", -101);
	FT_PRINTF(" %X ", INT_MAX);
	FT_PRINTF(" %X ", INT_MIN);
	FT_PRINTF(" %X ", LONG_MAX);
	FT_PRINTF(" %X ", LONG_MIN);
	FT_PRINTF(" %X ", UINT_MAX);
	FT_PRINTF(" %X ", ULONG_MAX);
	FT_PRINTF(" %X ", 9223372036854775807LL);
	FT_PRINTF(" %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	FT_PRINTF(" %X ", 42);
	FT_PRINTF(" %X ", -42);

	return (OK);
}

int	test_ft_printf_p(void *args)
{
	(void)args;

	FT_PRINTF(" %p ", (void *)-1);
	FT_PRINTF(" %p ", (void *)1);
	FT_PRINTF(" %p ", (void *)15);
	FT_PRINTF(" %p ", (void *)16);
	FT_PRINTF(" %p ", (void *)17);
	FT_PRINTF(" %p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
	FT_PRINTF(" %p %p ", (void *)INT_MIN, (void *)INT_MAX);
	FT_PRINTF(" %p %p ", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	FT_PRINTF(" %p %p ", (void *)0, (void *)0);

	return (OK);
}

int	test_ft_printf_minus(void *args)
{
	(void)args;

	/* percent */
	FT_PRINTF("%-%", '0');
	FT_PRINTF(" %-2%", '0');
	FT_PRINTF(" %-3% " , '0', 128);
	FT_PRINTF("%-4%   " , '0', +256);
	FT_PRINTF(" %-1% %-4% %-3%   ", '1', 4, 'f');
	FT_PRINTF(" %-0% %-10% %-3%   ", '1', 'r', -12);

	/* char */
	FT_PRINTF("%-1c", '0');
	FT_PRINTF(" %-2c", '0');
	FT_PRINTF(" %-3c " , '0', 128);
	FT_PRINTF("%-4c   " , '0', +256);
	FT_PRINTF(" %-1c %-4c %-3c   ", '1', 4, 'f');
	FT_PRINTF(" %-0c %-10c %-3c   ", '1', 'r', -12);

	/* string */
	FT_PRINTF("%-1s ", "TEST", "Ip\nsum", NULL);
	FT_PRINTF("  %-3s ", "Ip\nsum", NULL);
	FT_PRINTF("   %-5s", "Ip\nsum", NULL);
	FT_PRINTF(" %-1s %-4s %-3s   ", "TEST", "Ip\nsum", NULL);
	FT_PRINTF(" %-1 %-4s %-3s   ", "TEST", "um", NULL);
	FT_PRINTF(" %-1 %-4s %-3s   ", "", NULL);

	/* int */
	FT_PRINTF("%-i", 1254);
	FT_PRINTF("%-1i", 0);
	FT_PRINTF("%-12i", INT_MIN);
	FT_PRINTF("%-254i", INT_MAX);
	FT_PRINTF("%-2i %-3 %-23i", INT_MAX, 42, 156);
	FT_PRINTF("%-2i %-3i %-23i", INT_MAX, 42, 156);

	/* decimal */
	FT_PRINTF("%-d", 1254);
	FT_PRINTF("%-1d", 0);
	FT_PRINTF("%-12d", INT_MIN);
	FT_PRINTF("%-254d", INT_MAX);
	FT_PRINTF("%-2d %-3 %-23d", INT_MAX, 42, 156);
	FT_PRINTF("%-2d %-3d %-23d", INT_MAX, 42, 156);

	/* uint */
	FT_PRINTF("%-u", 1254);
	FT_PRINTF("%-1u", 0);
	FT_PRINTF("%-12u", INT_MIN);
	FT_PRINTF("%-254u", INT_MAX);
	FT_PRINTF("%-2u %-3 %-23u", INT_MAX, 42, 156);
	FT_PRINTF("%-2u %-3u %-23u", INT_MAX, 42, 156);

	/* hex low */
	FT_PRINTF("%-x", 1254);
	FT_PRINTF("%-1x", 0);
	FT_PRINTF("%-12x", INT_MIN);
	FT_PRINTF("%-254x", LONG_MAX);
	FT_PRINTF("%-2u %-3 %-23x", INT_MAX, 42, 156);
	FT_PRINTF("%-2x %-3x %-23x", UINT_MAX, 42, 156);

	/* hex up */
	FT_PRINTF("%-X", 1254);
	FT_PRINTF("%-1X", 0);
	FT_PRINTF("%-12X", INT_MIN);
	FT_PRINTF("%-254X", LONG_MAX);
	FT_PRINTF("%-2X %-3 %-23X", INT_MAX, 42, 156);
	FT_PRINTF("%-2X %-3d %-23X", UINT_MAX, 42, 156);

	/* ptr */
	FT_PRINTF("%-p", 1254);
	FT_PRINTF("%-1p", 0);
	FT_PRINTF("%-12p", INT_MIN);
	FT_PRINTF("%-254p", LONG_MAX);
	FT_PRINTF("%-2p %-3 %-23p", INT_MAX, 42, 156);
	FT_PRINTF("%-2p %-3d %-23p", UINT_MAX, 42, 156);
	return (OK);
}

int	test_ft_printf_plus(void *args)
{
	(void)args;

	/* percent */
	FT_PRINTF("%+1%", '0');
	FT_PRINTF(" %+2%", '0');
	FT_PRINTF(" %+3% " , '0', 128);
	FT_PRINTF("%+4%   " , '0', +256);
	FT_PRINTF(" %+1% %+4% %+3%   ", '1', 4, 'f');
	FT_PRINTF(" %+0% %+10% %+3%   ", '1', 'r', -12);

	/* char */
	FT_PRINTF("%+1c", '0');
	FT_PRINTF(" %+2c", '0');
	FT_PRINTF(" %+3c " , '0', 128);
	FT_PRINTF("%+4c   " , '0', +256);
	FT_PRINTF(" %+1c %+4c %+3c   ", '1', 4, 'f');
	FT_PRINTF(" %+0c %+10c %+3c   ", '1', 'r', -12);

	/* string */
	FT_PRINTF("%+1s ", "TEST", "Ip\nsum", NULL);
	FT_PRINTF("  %+3s ", "Ip\nsum", NULL);
	FT_PRINTF("   %+5s", "Ip\nsum", NULL);
	FT_PRINTF(" %+1s %+4s %+3s   ", "TEST", "Ip\nsum", NULL);

	/* int */
	FT_PRINTF("%+i", 1254);
	FT_PRINTF("%+1i", 0);
	FT_PRINTF("%+12i", INT_MIN);
	FT_PRINTF("%+254i", INT_MAX);
	FT_PRINTF("%+2i %+3i %+23i", INT_MAX, 42, 156);

	/* decimal */
	FT_PRINTF("%+d", 1254);
	FT_PRINTF("%+1d", 0);
	FT_PRINTF("%+12d", INT_MIN);
	FT_PRINTF("%+254d", INT_MAX);
	FT_PRINTF("%+2d %+3d %+23d", INT_MAX, 42, 156);

	/* uint */
	FT_PRINTF("%+u", 1254);
	FT_PRINTF("%+1u", 0);
	FT_PRINTF("%+12u", INT_MIN);
	FT_PRINTF("%+254u", INT_MAX);
	FT_PRINTF("%+2u %+3u %+23u", INT_MAX, 42, 156);

	/* hex low */
	FT_PRINTF("%+x", 1254);
	FT_PRINTF("%+1x", 0);
	FT_PRINTF("%+12x", INT_MIN);
	FT_PRINTF("%+254x", LONG_MAX);
	FT_PRINTF("%+2x %+3x %+23x", UINT_MAX, 42, 156);

	/* hex up */
	FT_PRINTF("%+X", 1254);
	FT_PRINTF("%+1X", 0);
	FT_PRINTF("%+12X", INT_MIN);
	FT_PRINTF("%+254X", LONG_MAX);
	FT_PRINTF("%+2X %+3d %+23X", UINT_MAX, 42, 156);

	/* ptr */
	FT_PRINTF("%+p", 1254);
	FT_PRINTF("%+1p", 0);
	FT_PRINTF("%+12p", INT_MIN);
	FT_PRINTF("%+254p", LONG_MAX);
	FT_PRINTF("%+2p %+3d %+23p", UINT_MAX, 42, 156);
	return (OK);
}

int	test_ft_printf_zero(void *args)
{
	(void)args;

	/* percent */
	FT_PRINTF("%01%", '0');
	FT_PRINTF(" %02%", '0');
	FT_PRINTF(" %03% " , '0', 128);
	FT_PRINTF("%04%   " , '0', +256);
	FT_PRINTF(" %01% %04% %03%   ", '1', 4, 'f');
	FT_PRINTF(" %00% %010% %03%   ", '1', 'r', -12);

	/* char */
	FT_PRINTF("%01c", '0');
	FT_PRINTF(" %02c", '0');
	FT_PRINTF(" %03c " , '0', 128);
	FT_PRINTF("%04c   " , '0', +256);
	FT_PRINTF(" %01c %04c %03c   ", '1', 4, 'f');
	FT_PRINTF(" %00c %010c %03c   ", '1', 'r', -12);

	/* string */
	FT_PRINTF("%01s ", "TEST", "Ip\nsum", NULL);
	FT_PRINTF("  %03s ", "Ip\nsum", NULL);
	FT_PRINTF("   %05s", "Ip\nsum", NULL);
	FT_PRINTF(" %01s %04s %03s   ", "TEST", "Ipsum", NULL);

	/* int */
	FT_PRINTF("%0i", 1254);
	FT_PRINTF("%01i", 0);
	FT_PRINTF("%012i", INT_MIN);
	FT_PRINTF("%0254i", INT_MAX);
	FT_PRINTF("%02i %03 %023i", INT_MAX, 42, 156);
	FT_PRINTF("%02i %03i %023i", INT_MAX, 42, 156);

	/* decimal */
	FT_PRINTF("%0d", 1254);
	FT_PRINTF("%01d", 0);
	FT_PRINTF("%012d", INT_MIN);
	FT_PRINTF("%0254d", INT_MAX);
	FT_PRINTF("%02d %03 %023d", INT_MAX, 42, 156);
	FT_PRINTF("%02d %03d %023d", INT_MAX, 42, 156);

	/* uint */
	FT_PRINTF("%0u", 1254);
	FT_PRINTF("%01u", 0);
	FT_PRINTF("%012u", INT_MIN);
	FT_PRINTF("%0254u", INT_MAX);
	FT_PRINTF("%02u %03 %023u", INT_MAX, 42, 156);
	FT_PRINTF("%02u %03u %023u", INT_MAX, 42, 156);

	/* hex low */
	FT_PRINTF("%0x", 1254);
	FT_PRINTF("%01x", 0);
	FT_PRINTF("%012x", INT_MIN);
	FT_PRINTF("%0254x", LONG_MAX);
	FT_PRINTF("%02u %03 %023x", INT_MAX, 42, 156);
	FT_PRINTF("%02x %03x %023x", UINT_MAX, 42, 156);

	/* hex up */
	FT_PRINTF("%0X", 1254);
	FT_PRINTF("%01X", 0);
	FT_PRINTF("%012X", INT_MIN);
	FT_PRINTF("%0254X", LONG_MAX);
	FT_PRINTF("%02X %03 %023X", INT_MAX, 42, 156);
	FT_PRINTF("%02X %03d %023X", UINT_MAX, 42, 156);

	/* ptr */
	FT_PRINTF("%0p", 1254);
	FT_PRINTF("%01p", 0);
	FT_PRINTF("%012p", INT_MIN);
	FT_PRINTF("%0254p", LONG_MAX);
	FT_PRINTF("%02p %03 %023p", INT_MAX, 42, 156);
	FT_PRINTF("%02p %03d %023p", UINT_MAX, 42, 156);
	return (OK);
}

int	test_ft_printf_sharp(void *args)
{
	(void)args;

	/* percent */
	FT_PRINTF("%#1%", '0');
	FT_PRINTF(" %#2%", '0');
	FT_PRINTF(" %#3% " , '0', 128);
	FT_PRINTF("%#4%   " , '0', +256);
	FT_PRINTF(" %#1% %#4% %#3%   ", '1', 4, 'f');
	FT_PRINTF(" %#0% %#10% %#3%   ", '1', 'r', -12);

	/* char */
	FT_PRINTF("%#1c", '0');
	FT_PRINTF(" %#2c", '0');
	FT_PRINTF(" %#3c " , '0', 128);
	FT_PRINTF("%#4c   " , '0', +256);
	FT_PRINTF(" %#1c %#4c %#3c   ", '1', 4, 'f');
	FT_PRINTF(" %#0c %#10c %#3c   ", '1', 'r', -12);

	/* string */
	FT_PRINTF("%#1s ", "TEST", "Ip\nsum", NULL);
	FT_PRINTF("  %#3s ", "Ip\nsum", NULL);
	FT_PRINTF("   %#5s", "Ip\nsum", NULL);
	FT_PRINTF(" %#1s %#4s %#3s   ", "TEST", "Ip\nsum", NULL);
	FT_PRINTF(" %#1 %#4s %#3s   ", "TEST", "um", NULL);
	FT_PRINTF(" %#1 %#4s %#3s   ", "", NULL);

	/* int */
	FT_PRINTF("%#i", 1254);
	FT_PRINTF("%#1i", 0);
	FT_PRINTF("%#12i", INT_MIN);
	FT_PRINTF("%#254i", INT_MAX);
	FT_PRINTF("%#2i %#3 %#23i", INT_MAX, 42, 156);
	FT_PRINTF("%#2i %#3i %#23i", INT_MAX, 42, 156);

	/* decimal */
	FT_PRINTF("%#d", 1254);
	FT_PRINTF("%#1d", 0);
	FT_PRINTF("%#12d", INT_MIN);
	FT_PRINTF("%#254d", INT_MAX);
	FT_PRINTF("%#2d %#3 %#23d", INT_MAX, 42, 156);
	FT_PRINTF("%#2d %#3d %#23d", INT_MAX, 42, 156);

	/* uint */
	FT_PRINTF("%#u", 1254);
	FT_PRINTF("%#1u", 0);
	FT_PRINTF("%#12u", INT_MIN);
	FT_PRINTF("%#254u", INT_MAX);
	FT_PRINTF("%#2u %#3 %#23u", INT_MAX, 42, 156);
	FT_PRINTF("%#2u %#3u %#23u", INT_MAX, 42, 156);

	/* hex low */
	FT_PRINTF("%#x", 1254);
	FT_PRINTF("%#1x", 0);
	FT_PRINTF("%#12x", INT_MIN);
	FT_PRINTF("%#254x", LONG_MAX);
	FT_PRINTF("%#2u %#3 %#23x", INT_MAX, 42, 156);
	FT_PRINTF("%#2x %#3x %#23x", UINT_MAX, 42, 156);

	/* hex up */
	FT_PRINTF("%#X", 1254);
	FT_PRINTF("%#1X", 0);
	FT_PRINTF("%#12X", INT_MIN);
	FT_PRINTF("%#254X", LONG_MAX);
	FT_PRINTF("%#2X %#3 %#23X", INT_MAX, 42, 156);
	FT_PRINTF("%#2X %#3d %#23X", UINT_MAX, 42, 156);

	/* ptr */
	FT_PRINTF("%#p", 1254);
	FT_PRINTF("%#1p", 0);
	FT_PRINTF("%#12p", INT_MIN);
	FT_PRINTF("%#254p", LONG_MAX);
	FT_PRINTF("%#2p %#3 %#23p", INT_MAX, 42, 156);
	FT_PRINTF("%#2p %#3d %#23p", UINT_MAX, 42, 156);
	return (OK);
}

int	test_ft_printf_dot(void *args)
{
	(void)args;

	/* percent */
	FT_PRINTF("%.1%", '0');
	FT_PRINTF(" %.2%", '0');
	FT_PRINTF(" %.3% " , '0', 128);
	FT_PRINTF("%.4%   " , '0', +256);
	FT_PRINTF(" %.1% %.4% %.3%   ", '1', 4, 'f');
	FT_PRINTF(" %.0% %.10% %.3%   ", '1', 'r', -12);

	/* char */
	FT_PRINTF("%.1c", '0');
	FT_PRINTF(" %.2c", '0');
	FT_PRINTF(" %.3c " , '0', 128);
	FT_PRINTF("%.4c   " , '0', +256);
	FT_PRINTF(" %.1c %.4c %.3c   ", '1', 4, 'f');
	FT_PRINTF(" %.0c %.10c %.3c   ", '1', 'r', -12);

	/* string */
	FT_PRINTF("%.1s ", "TEST", "Ip\nsum", NULL);
	FT_PRINTF("  %.3s ", "Ip\nsum", NULL);
	FT_PRINTF("   %.5s", "Ip\nsum", NULL);
	FT_PRINTF(" %.1s %.4s %.3s   ", "TEST", "Ip\nsum", NULL);
	FT_PRINTF(" %.1 %.4s %.3s   ", "TEST", "um", NULL);
	FT_PRINTF(" %.1 %.4s %.3s   ", "", NULL);

	/* int */
	FT_PRINTF("%.i", 1254);
	FT_PRINTF("%.1i", 0);
	FT_PRINTF("%.12i", INT_MIN);
	FT_PRINTF("%.254i", INT_MAX);
	FT_PRINTF("%.2i %.3 %.23i", INT_MAX, 42, 156);
	FT_PRINTF("%.2i %.3i %.23i", INT_MAX, 42, 156);

	/* decimal */
	FT_PRINTF("%.d", 1254);
	FT_PRINTF("%.1d", 0);
	FT_PRINTF("%.12d", INT_MIN);
	FT_PRINTF("%.254d", INT_MAX);
	FT_PRINTF("%.2d %.3 %.23d", INT_MAX, 42, 156);
	FT_PRINTF("%.2d %.3d %.23d", INT_MAX, 42, 156);

	/* uint */
	FT_PRINTF("%.u", 1254);
	FT_PRINTF("%.1u", 0);
	FT_PRINTF("%.12u", INT_MIN);
	FT_PRINTF("%.254u", INT_MAX);
	FT_PRINTF("%.2u %.3 %.23u", INT_MAX, 42, 156);
	FT_PRINTF("%.2u %.3u %.23u", INT_MAX, 42, 156);

	/* hex low */
	FT_PRINTF("%.x", 1254);
	FT_PRINTF("%.1x", 0);
	FT_PRINTF("%.12x", INT_MIN);
	FT_PRINTF("%.254x", LONG_MAX);
	FT_PRINTF("%.2u %.3 %.23x", INT_MAX, 42, 156);
	FT_PRINTF("%.2x %.3x %.23x", UINT_MAX, 42, 156);

	/* hex up */
	FT_PRINTF("%.X", 1254);
	FT_PRINTF("%.1X", 0);
	FT_PRINTF("%.12X", INT_MIN);
	FT_PRINTF("%.254X", LONG_MAX);
	FT_PRINTF("%.2X %.3 %.23X", INT_MAX, 42, 156);
	FT_PRINTF("%.2X %.3d %.23X", UINT_MAX, 42, 156);

	/* ptr */
	FT_PRINTF("%.p", 1254);
	FT_PRINTF("%.1p", 0);
	FT_PRINTF("%.12p", INT_MIN);
	FT_PRINTF("%.254p", LONG_MAX);
	FT_PRINTF("%.2p %.3 %.23p", INT_MAX, 42, 156);
	FT_PRINTF("%.2p %.3d %.23p", UINT_MAX, 42, 156);
	return (OK);
}

int	test_ft_printf_space(void *args)
{
	(void)args;

	/* percent */
	FT_PRINTF("% 1%", '0');
	FT_PRINTF(" % 2%", '0');
	FT_PRINTF(" % 3% " , '0', 128);
	// undefined by implementation : FT_PRINTF(" %    3 % " , '0', 128);
	FT_PRINTF("% 4%   " , '0', +256);
	FT_PRINTF(" % 1% % 4% % 3%   ", '1', 4, 'f');
	FT_PRINTF(" % 0% % 10% % 3%   ", '1', 'r', -12);

	/* char */
	FT_PRINTF("% 1c", '0');
	FT_PRINTF(" % 2c", '0');
	FT_PRINTF(" %  c " , '0', 128);
	FT_PRINTF("% 4c   " , '0', +256);
	FT_PRINTF(" % 1c % 4c % 3c   ", '1', 4, 'f');
	FT_PRINTF(" % 0c % 10c % 3c   ", '1', 'r', -12);

	/* string */
	FT_PRINTF("% 1s ", "TEST", "Ip\nsum", NULL);
	FT_PRINTF("  % 3s ", "Ip\nsum", NULL);
	FT_PRINTF("   % 5s", "Ip\nsum", NULL);
	FT_PRINTF(" % 1s % 4s % 3s   ", "TEST", "Ip\nsum", NULL);
	FT_PRINTF(" % 1 % 4s % 3s   ", "TEST", "um", NULL);
	FT_PRINTF(" % 1 % 4s % 3s   ", "", NULL);

	/* int */
	FT_PRINTF("% i", 1254);
	FT_PRINTF("% 1i", 0);
	FT_PRINTF("% 12i", INT_MIN);
	// undefined by the implementation FT_PRINTF("% 25i", INT_MAX);
	//FT_PRINTF("% 2i % 3 % 23i", INT_MAX, 42, 156);
	//FT_PRINTF("% 2i % 3i % 23i", INT_MAX, 42, 156);

	/* decimal */
	FT_PRINTF("% d", 1254);
	FT_PRINTF("% 1d", 0);
	FT_PRINTF("% 12d", INT_MIN);
	//FT_PRINTF("% 254d", INT_MAX);
	//FT_PRINTF("% 2d % 3 % 23d", INT_MAX, 42, 156);
	//FT_PRINTF("% 2d % 3d % 23d", INT_MAX, 42, 156);

	/* uint */
	FT_PRINTF("% u", 1254);
	FT_PRINTF("% 1u", 0);
	FT_PRINTF("% 12u", INT_MIN);
	FT_PRINTF("% 254u", INT_MAX);
	FT_PRINTF("% 2u % 3 % 23u", INT_MAX, 42, 156);
	FT_PRINTF("% 2u % 3u % 23u", INT_MAX, 42, 156);

	/* hex low */
	FT_PRINTF("% x", 1254);
	FT_PRINTF("% 1x", 0);
	FT_PRINTF("% 12x", INT_MIN);
	FT_PRINTF("% 254x", LONG_MAX);
	FT_PRINTF("% 2u % 3 % 23x", INT_MAX, 42, 156);
	FT_PRINTF("% 2x % 3x % 23x", UINT_MAX, 42, 156);

	/* hex up */
	FT_PRINTF("% X", 1254);
	FT_PRINTF("% 1X", 0);
	FT_PRINTF("% 12X", INT_MIN);
	FT_PRINTF("% 254X", LONG_MAX);
	FT_PRINTF("% 2X % 3 % 23X", INT_MAX, 42, 156);
	FT_PRINTF("% 2X % 3X % 23X", UINT_MAX, 42, 156);

	/* ptr */
	FT_PRINTF("% p", 1254);
	FT_PRINTF("% 1p", 0);
	FT_PRINTF("% 12p", INT_MIN);
	FT_PRINTF("% 254p", LONG_MAX);
	FT_PRINTF("% 2p % 3 % 23p", INT_MAX, 42, 156);
	FT_PRINTF("% 2p % 3p % 23p", UINT_MAX, 42, 156);
	FT_PRINTF("% 2p % 4p % 23p", UINT_MAX, 42, 156);
	return (OK);
}

int	test_ft_printf_bonus_percent(void *args)
{
	(void)args;

	FT_PRINTF("%%", 1);
	FT_PRINTF("%5%", 2);
	FT_PRINTF("%05%", 3);
	FT_PRINTF("%-5%", 4);
	FT_PRINTF("% %", 5);
	FT_PRINTF("%.%", 6);
	FT_PRINTF("%0%", 7);
	FT_PRINTF("%.0%",8);
	FT_PRINTF("%0.%", 9);
	FT_PRINTF("%0.0%", 10);

	FT_PRINTF("%", 1);
	FT_PRINTF("%5", 2);
	FT_PRINTF("%05", 3);
	FT_PRINTF("%-5", 4);
	FT_PRINTF("% ", 5);
	FT_PRINTF("%.", 6);
	FT_PRINTF("%0", 7);
	FT_PRINTF("%.0",8);
	FT_PRINTF("%0.", 9);
	FT_PRINTF("%0.0", 10);

	FT_PRINTF("% j", 1);
	FT_PRINTF("%5 j", 2);
	FT_PRINTF("%05 j", 3);
	FT_PRINTF("%-5 j", 4);
	FT_PRINTF("% j", 5);
	FT_PRINTF("%. j", 6);
	FT_PRINTF("%0 j", 7);
	FT_PRINTF("%.0 j",8);
	FT_PRINTF("%0. j", 9);
	FT_PRINTF("%0.0 j", 10);

	FT_PRINTF("% j%i", 1);
	FT_PRINTF("%5 j%i", 2);
	FT_PRINTF("%05 j%i", 3);
	FT_PRINTF("%-5 j%i", 4);
	FT_PRINTF("% j%i", 5);
	FT_PRINTF("%. j%i", 6);
	FT_PRINTF("%0 j%i", 7);
	FT_PRINTF("%.0 j%i",8);
	FT_PRINTF("%0. j%i", 9);
	FT_PRINTF("%0.0 j%i", 10);
	return (OK);
}

int	test_ft_printf_bonus_s(void *args)
{
	(void)args;

	FT_PRINTF("%.3s", "Ipsum");
	FT_PRINTF("%.s", "Ipsum");
	FT_PRINTF("%.0s", "Ipsum");

	FT_PRINTF("%.3s%.2s", "Hello", "World");
	FT_PRINTF("%.2s%.1s", "Ipsum", "Lorem");

	FT_PRINTF("%3.3s%6.2s", "Hello", "World");
	FT_PRINTF("%4.3s%12.1s", "Ipsum", "Lorem");
	FT_PRINTF("%0.3s%0.1s", "Ipsum", "Lorem");
	FT_PRINTF("%2.s%4.s", "Ipsum", "Lorem");
	
	FT_PRINTF("%7.5s", "toto");
	FT_PRINTF("%7.5s", "bombastic");
	FT_PRINTF("%-7.5s", "toto");
	FT_PRINTF("%-7.5s", "requiem");
	FT_PRINTF("%7.7s%7.7s", "hello", "world");
	FT_PRINTF("%3.7s%7.7s", "hello", "world");
	FT_PRINTF("%7.7s%3.7s", "hello", "wototorld");
	FT_PRINTF("%3.7s%3.7s", "hello", "world");
	FT_PRINTF("%7.3s%7.7s", "hello", "world");
	FT_PRINTF("%3.3s%7.7s", "hello", "world");
	FT_PRINTF("%7.3s%3.7s", "hello", "world");
	FT_PRINTF("%3.3s%3.7s", "hello", "world");
	FT_PRINTF("%7.7s%7.3s", "hello", "world");
	FT_PRINTF("%3.7s%7.3s", "hello", "world");
	FT_PRINTF("%7.7s%3.3s", "hello", "world");
	FT_PRINTF("%3.7s%3.3s", "hello", "world");
	FT_PRINTF("%7.3s%7.3s", "hello", "world");
	FT_PRINTF("%3.3s%7.3s", "hello", "world");
	FT_PRINTF("%7.3s%3.3s", "hello", "world");
	FT_PRINTF("%3s%3s", "hello", "world");

	FT_PRINTF("%7.5s", "toto");
	FT_PRINTF("%7.5s", "bombastic");
	FT_PRINTF("%-7.5s", "toto");
	FT_PRINTF("%-7.5s", "tubular");
	FT_PRINTF("%7.7s%7.7s", "hello", "world");
	FT_PRINTF("%3.7s%7.7s", "hello", "world");
	FT_PRINTF("%7.7s%3.7s", "hello", "world");
	FT_PRINTF("%3.7s%3.7s", "hello", "world");
	FT_PRINTF("%7.3s%7.7s", "hello", "world");
	FT_PRINTF("%3.3s%7.7s", "hello", "world");
	FT_PRINTF("%7.3s%3.7s", "hello", "world");
	FT_PRINTF("%3.3s%3.7s", "hello", "world");
	FT_PRINTF("%7.7s%7.3s", "hello", "world");
	FT_PRINTF("%3.7s%7.3s", "hello", "world");
	FT_PRINTF("%7.7s%3.3s", "hello", "world");
	FT_PRINTF("%3.7s%3.3s", "hello", "world");
	FT_PRINTF("%7.3s%7.3s", "hello", "world");
	FT_PRINTF("%3.3s%7.3s", "hello", "world");
	FT_PRINTF("%7.3s%3.3s", "hello", "world");
	FT_PRINTF("%3.3s%3.3s", "hello", "world");
	FT_PRINTF("%3s%3s", "hello", "world");

	char	*w_nullbyte = "Ici ça print\0 et la non \0";
	FT_PRINTF("%.3s", w_nullbyte);
	FT_PRINTF("%.s", w_nullbyte);
	FT_PRINTF("%.0s", w_nullbyte);

	FT_PRINTF("%.3s%.2s", "Hello", "World");
	FT_PRINTF("%.2s%.1s", w_nullbyte, "Lorem");

	FT_PRINTF("%3.3s%6.2s", "Hello", w_nullbyte);
	FT_PRINTF("%4.3s%12.1s", w_nullbyte, "Lorem");
	FT_PRINTF("%0.3s%0.1s", w_nullbyte, "Lorem");
	FT_PRINTF("%2.s%4.s", w_nullbyte, "Lorem");
	
	FT_PRINTF("%7.5s", w_nullbyte);
	FT_PRINTF("%7.5s", w_nullbyte);
	FT_PRINTF("%-7.5s", w_nullbyte);
	FT_PRINTF("%-7.5s", w_nullbyte);
	FT_PRINTF("%7.7s%7.7s", "hello", w_nullbyte);
	FT_PRINTF("%3.7s%7.7s", "hello", w_nullbyte);
	FT_PRINTF("%7.7s%3.7s", "hello", w_nullbyte);
	FT_PRINTF("%3.7s%3.7s", "hello", w_nullbyte);
	FT_PRINTF("%7.3s%7.7s", "hello", w_nullbyte);
	FT_PRINTF("%3.3s%7.7s", "hello", w_nullbyte);
	FT_PRINTF("%7.3s%3.7s", "hello", w_nullbyte);
	FT_PRINTF("%3.3s%3.7s", "hello", w_nullbyte);
	FT_PRINTF("%7.7s%7.3s", "hello", w_nullbyte);
	FT_PRINTF("%3.7s%7.3s", "hello", w_nullbyte);
	FT_PRINTF("%7.7s%3.3s", "hello", w_nullbyte);
	FT_PRINTF("%3.7s%3.3s", "hello", w_nullbyte);
	FT_PRINTF("%7.3s%7.3s", "hello", w_nullbyte);
	FT_PRINTF("%3.3s%7.3s", "hello", w_nullbyte);
	FT_PRINTF("%7.3s%3.3s", "hello", w_nullbyte);
	FT_PRINTF("%3s%3s", "hello", w_nullbyte);

	 FT_PRINTF("%+- 06.06s", w_nullbyte);
	 FT_PRINTF("% 0+-6.06s", w_nullbyte);
	 FT_PRINTF("%0 +-6.06s", w_nullbyte);
	 FT_PRINTF("%+-0 6.06s", w_nullbyte);
	 FT_PRINTF("%-+ 06.06s", w_nullbyte);
	 FT_PRINTF("% -+06.06s", w_nullbyte);
	 FT_PRINTF("%+- 07.06s", w_nullbyte);
	 FT_PRINTF("% 0+-8.06s", w_nullbyte);
	 FT_PRINTF("%0 +-9.06s", w_nullbyte);
	 FT_PRINTF("%+-0 10.06s", w_nullbyte);
	 FT_PRINTF("%-+ 011.06s", w_nullbyte);
	 FT_PRINTF("% -+012.06s", w_nullbyte);
	 FT_PRINTF("%+- 06.04s", w_nullbyte);
	 FT_PRINTF("% 0+-6.04s", w_nullbyte);
	 FT_PRINTF("%0 +-6.04s", w_nullbyte);
	 FT_PRINTF("%+-0 6.04s", w_nullbyte);
	 FT_PRINTF("%-+ 06.04s", w_nullbyte);
	 FT_PRINTF("% 0-+6.04s", w_nullbyte);
	 FT_PRINTF("%+- 06.09s", w_nullbyte);
	 FT_PRINTF("% 0+-6.09s", w_nullbyte);
	 FT_PRINTF("%0 +-6.09s", w_nullbyte);
	 FT_PRINTF("%+-0 6.09s", w_nullbyte);
	 FT_PRINTF("%-+ 06.09s", w_nullbyte);
	 FT_PRINTF("% 0-+6.09s", w_nullbyte);
	 FT_PRINTF("%00s", w_nullbyte);
	 FT_PRINTF("%000s", w_nullbyte);
	 FT_PRINTF("%0000s", w_nullbyte);
	 FT_PRINTF("%-00s", w_nullbyte);
	 FT_PRINTF("%0-0s", w_nullbyte);
	 FT_PRINTF("%00-s", w_nullbyte);
	 FT_PRINTF("%03s", w_nullbyte);
	 FT_PRINTF("%09s", w_nullbyte);
	 FT_PRINTF("%+03s", w_nullbyte);
	 FT_PRINTF("%+09s", w_nullbyte);
	 FT_PRINTF("%-03s", w_nullbyte);
	 FT_PRINTF("%-09s", w_nullbyte);
	 FT_PRINTF("%+ 3s", w_nullbyte);
	 FT_PRINTF("%+ 6s", w_nullbyte);
	return (OK);
}

int	test_ft_printf_bonus_p(void *args)
{
	(void)args;
	char	a01;
	unsigned char a02;
	short a03;
	unsigned short a04;
	int a05;
	unsigned int a06;
	long a07;
	unsigned long a08;
	long long a09;
	unsigned long long a10;
	char *a11;
	void *a12;

	FT_PRINTF("%p", NULL);
	FT_PRINTF("%9.2p\n", 1234);
	FT_PRINTF("%2.9p\n", 1234);
	FT_PRINTF("%.5p", 0);
	FT_PRINTF("%.0p", 0);
	FT_PRINTF("%10.0p", 0);
	FT_PRINTF("%010.0p", 0);
	FT_PRINTF("%-10.0p", 0);
	FT_PRINTF("%+10.0p", 0);
	FT_PRINTF("%5p", 0);
	FT_PRINTF("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	FT_PRINTF("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	FT_PRINTF("%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	FT_PRINTF("%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	FT_PRINTF("%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	FT_PRINTF("%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	FT_PRINTF("%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	FT_PRINTF("%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	FT_PRINTF("%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	FT_PRINTF("%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	FT_PRINTF("%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	return (OK);
}

int	test_ft_printf_bonus_d(void *args)
{
	(void)args;
	FT_PRINTF("this %d number", 17);
	FT_PRINTF("this %d number", -267);
	FT_PRINTF("this %d number", 0);
	FT_PRINTF("%d", 3);
	FT_PRINTF("%d", -1);
	FT_PRINTF("%d", 0);
	FT_PRINTF("%d",  2147483647);
	FT_PRINTF("%d", (int)(-2147483678));
	FT_PRINTF("%7d", 33);
	FT_PRINTF("%7d", -14);
	FT_PRINTF("%3d", 0);
	FT_PRINTF("%5d", 52625);
	FT_PRINTF("%5d", -2562);
	FT_PRINTF("%4d", 94827);
	FT_PRINTF("%4d", -2464);
	FT_PRINTF("%-7d", 33);
	FT_PRINTF("%-7d", -14);
	FT_PRINTF("%-3d", 0);
	FT_PRINTF("%-5d", 52625);
	FT_PRINTF("%-5d", -2562);
	FT_PRINTF("%-4d", 94827);
	FT_PRINTF("%-4d", -2464);
	FT_PRINTF("%.5d", 2);
	FT_PRINTF("%.6d", -3);
	FT_PRINTF("%.3d", 0);
	FT_PRINTF("%.4d", 5263);
	FT_PRINTF("%.4d", -2372);
	FT_PRINTF("%.3d", 13862);
	FT_PRINTF("%.3d",-23646);
	FT_PRINTF("%05d", 43);
	FT_PRINTF("%07d", -54);
	FT_PRINTF("%03d", 0);
	FT_PRINTF("%03d", 634);
	FT_PRINTF("%04d", -532);
	FT_PRINTF("%04d", -4825);
	FT_PRINTF("%8.5d", 34);
	FT_PRINTF("%10.5d", -216);
	FT_PRINTF("%8.5d", 0);
	FT_PRINTF("%8.3d", 8375);
	FT_PRINTF("%8.3d", -8473);
	FT_PRINTF("%3.7d", 3267);
	FT_PRINTF("%3.7d", -2375);
	FT_PRINTF("%3.3d", 6983);
	FT_PRINTF("%3.3d", -8462);
	FT_PRINTF("%-8.5d", 34);
	FT_PRINTF("%-10.5d", -216);
	FT_PRINTF("%-8.5d", 0);
	FT_PRINTF("%-8.3d", 8375);
	FT_PRINTF("%-8.3d", -8473);
	FT_PRINTF("%-3.7d", 3267);
	FT_PRINTF("%-3.7d", -2375);
	FT_PRINTF("%-3.3d", 6983);
	FT_PRINTF("%-3.3d", -8462);
	FT_PRINTF("%08.5d", 34);
	FT_PRINTF("%010.5d", -216);
	FT_PRINTF("%08.5d", 0);
	FT_PRINTF("%08.3d", 8375);
	FT_PRINTF("%08.3d", -8473);
	FT_PRINTF("%03.7d", 3267);
	FT_PRINTF("%03.7d", -2375);
	FT_PRINTF("%03.3d", 6983);
	FT_PRINTF("%03.3d", -8462);
	FT_PRINTF("%0-8.5d", 34);
	FT_PRINTF("%0-10.5d", -216);
	FT_PRINTF("%0-8.5d", 0);
	FT_PRINTF("%0-8.3d", 8375);
	FT_PRINTF("%0-8.3d", -8473);
	FT_PRINTF("%0-3.7d", 3267);
	FT_PRINTF("%0-3.7d", -2375);
	FT_PRINTF("%0-3.3d", 6983);
	FT_PRINTF("%0-3.3d", -8462);
	FT_PRINTF("%.0d", 0);
	FT_PRINTF("%.d", 0);
	FT_PRINTF("%5.0d", 0);
	FT_PRINTF("%5.d", 0);
	FT_PRINTF("%-5.0d", 0);
	FT_PRINTF("%-5.d", 0);
	FT_PRINTF("%+.0d", 0);
	FT_PRINTF("%+.d", 0);
	FT_PRINTF("%+5.0d", 0);
	FT_PRINTF("%+5.d", 0);
	FT_PRINTF("% .0d", 0);
	FT_PRINTF("% .d", 0);
	FT_PRINTF("% 5.0d", 0);
	FT_PRINTF("% 5.d", 0);
	return (OK);
}

int	test_ft_printf_bonus_i(void *args)
{
	(void)args;
	FT_PRINTF("this %i number", 17);
	FT_PRINTF("this %i number", -267);
	FT_PRINTF("this %i number", 0);
	FT_PRINTF("%i", 3);
	FT_PRINTF("%i", -1);
	FT_PRINTF("%i", 0);
	FT_PRINTF("%i",  2147483647);
	FT_PRINTF("%i", (int)(-2147483678));
	FT_PRINTF("%7i", 33);
	FT_PRINTF("%7i", -14);
	FT_PRINTF("%3i", 0);
	FT_PRINTF("%5i", 52625);
	FT_PRINTF("%5i", -2562);
	FT_PRINTF("%4i", 94827);
	FT_PRINTF("%4i", -2464);
	FT_PRINTF("%-7i", 33);
	FT_PRINTF("%-7i", -14);
	FT_PRINTF("%-3i", 0);
	FT_PRINTF("%-5i", 52625);
	FT_PRINTF("%-5i", -2562);
	FT_PRINTF("%-4i", 94827);
	FT_PRINTF("%-4i", -2464);
	FT_PRINTF("%.5i", 2);
	FT_PRINTF("%.6i", -3);
	FT_PRINTF("%.3i", 0);
	FT_PRINTF("%.4i", 5263);
	FT_PRINTF("%.4i", -2372);
	FT_PRINTF("%.3i", 13862);
	FT_PRINTF("%.3i",-23646);
	FT_PRINTF("%05i", 43);
	FT_PRINTF("%07i", -54);
	FT_PRINTF("%03i", 0);
	FT_PRINTF("%03i", 634);
	FT_PRINTF("%04i", -532);
	FT_PRINTF("%04i", -4825);
	FT_PRINTF("%8.5i", 34);
	FT_PRINTF("%10.5i", -216);
	FT_PRINTF("%8.5i", 0);
	FT_PRINTF("%8.3i", 8375);
	FT_PRINTF("%8.3i", -8473);
	FT_PRINTF("%+.0i", 0);
	FT_PRINTF("%+.i", 0);
	FT_PRINTF("%+5.0i", 0);
	FT_PRINTF("%+5.i", 0);
	FT_PRINTF("% .0i", 0);
	FT_PRINTF("% .i", 0);
	FT_PRINTF("% 5.0i", 0);
	FT_PRINTF("% 5.i", 0);
	FT_PRINTF("%3.7i", 3267);
	FT_PRINTF("%3.7i", -2375);
	FT_PRINTF("%3.3i", 6983);
	FT_PRINTF("%3.3i", -8462);
	FT_PRINTF("%-8.5i", 34);
	FT_PRINTF("%-10.5i", -216);
	FT_PRINTF("%-8.5i", 0);
	FT_PRINTF("%-8.3i", 8375);
	FT_PRINTF("%-8.3i", -8473);
	FT_PRINTF("%-3.7i", 3267);
	FT_PRINTF("%-3.7i", -2375);
	FT_PRINTF("%-3.3i", 6983);
	FT_PRINTF("%-3.3i", -8462);
	FT_PRINTF("%08.5i", 34);
	FT_PRINTF("%010.5i", -216);
	FT_PRINTF("%08.5i", 0);
	FT_PRINTF("%08.3i", 8375);
	FT_PRINTF("%08.3i", -8473);
	FT_PRINTF("%03.7i", 3267);
	FT_PRINTF("%03.7i", -2375);
	FT_PRINTF("%03.3i", 6983);
	FT_PRINTF("%03.3i", -8462);
	FT_PRINTF("%0-8.5i", 34);
	FT_PRINTF("%0-10.5i", -216);
	FT_PRINTF("%0-8.5i", 0);
	FT_PRINTF("%0-8.3i", 8375);
	FT_PRINTF("%0-8.3i", -8473);
	FT_PRINTF("%0-3.7i", 3267);
	FT_PRINTF("%0-3.7i", -2375);
	FT_PRINTF("%0-3.3i", 6983);
	FT_PRINTF("%0-3.3i", -8462);
	FT_PRINTF("%.0i", 0);
	FT_PRINTF("%.i", 0);
	FT_PRINTF("%5.0i", 0);
	FT_PRINTF("%5.i", 0);
	FT_PRINTF("%-5.0i", 0);
	FT_PRINTF("%-5.i", 0);
	FT_PRINTF("%+.0i", 0);
	FT_PRINTF("%+.i", 0);
	FT_PRINTF("%+5.0i", 0);
	FT_PRINTF("%+5.i", 0);
	FT_PRINTF("% .0i", 0);
	FT_PRINTF("% .i", 0);
	FT_PRINTF("% 5.0i", 0);
	FT_PRINTF("% 5.i", 0);
	return (OK);
}

int	test_ft_printf_bonus_u(void *args)
{
	(void)args;

	FT_PRINTF("this %u number", 17);
	FT_PRINTF("this %u number", 0);
	FT_PRINTF("%u", 3);
	FT_PRINTF("%u", 4294967295u);
	FT_PRINTF("%7u", 33);
	FT_PRINTF("%3u", 0);
	FT_PRINTF("%5u", 52625);
	FT_PRINTF("%4u", 94827);
	FT_PRINTF("%-7u", 33);
	FT_PRINTF("%-3u", 0);
	FT_PRINTF("%-5u", 52625);
	FT_PRINTF("%-4u", 94827);
	FT_PRINTF("%.5u", 2);
	FT_PRINTF("%.3u", 0);
	FT_PRINTF("%.4u", 5263);
	FT_PRINTF("%.3u", 13862);
	FT_PRINTF("%05u", 43);
	FT_PRINTF("%03u", 0);
	FT_PRINTF("%03u", 634);
	FT_PRINTF("%8.5u", 34);
	FT_PRINTF("%8.5u", 0);
	FT_PRINTF("%8.3u", 8375);
	FT_PRINTF("%3.7u", 3267);
	FT_PRINTF("%3.3u", 6983);
	FT_PRINTF("%-8.5u", 34);
	FT_PRINTF("%-8.5u", 0);
	FT_PRINTF("%-8.3u", 8375);
	FT_PRINTF("%-3.7u", 3267);
	FT_PRINTF("%-3.3u", 6983);
	FT_PRINTF("%08.5u", 34);
	FT_PRINTF("%08.5u", 0);
	FT_PRINTF("%08.3u", 8375);
	FT_PRINTF("%03.7u", 3267);
	FT_PRINTF("%03.3u", 6983);
	FT_PRINTF("%0-8.5u", 34);
	FT_PRINTF("%0-8.5u", 0);
	FT_PRINTF("%0-8.3u", 8375);
	FT_PRINTF("%0-3.7u", 3267);
	FT_PRINTF("%0-3.3u", 6983);
	FT_PRINTF("%.0u", 0);
	FT_PRINTF("%.u", 0);
	FT_PRINTF("%5.0u", 0);
	FT_PRINTF("%5.u", 0);
	FT_PRINTF("%-5.0u", 0);
	FT_PRINTF("%-5.u", 0);

	return (OK);
}

int	test_ft_printf_bonus_x(void *args)
{
	(void)args;

	FT_PRINTF("this %x number", 17);
	FT_PRINTF("this %x number", 0);
	FT_PRINTF("%x", 3);
	FT_PRINTF("%x", 4294967295u);
	FT_PRINTF("%7x", 33);
	FT_PRINTF("%3x", 0);
	FT_PRINTF("%5x", 52625);
	FT_PRINTF("%2x", 94827);
	FT_PRINTF("%-7x", 33);
	FT_PRINTF("%-3x", 0);
	FT_PRINTF("%-5x", 52625);
	FT_PRINTF("%-4x", 9648627);
	FT_PRINTF("%.5x", 21);
	FT_PRINTF("%.3x", 0);
	FT_PRINTF("%.4x", 5263);
	FT_PRINTF("%.3x", 938862);
	FT_PRINTF("%05x", 43);
	FT_PRINTF("%03x", 0);
	FT_PRINTF("%03x", 698334);
	FT_PRINTF("%8.5x", 34);
	FT_PRINTF("%8.5x", 0);
	FT_PRINTF("%8.3x", 8375);
	FT_PRINTF("%2.7x", 3267);
	FT_PRINTF("%3.3x", 6983);
	FT_PRINTF("%-8.5x", 34);
	FT_PRINTF("%-8.5x", 0);
	FT_PRINTF("%-8.3x", 8375);
	FT_PRINTF("%-2.7x", 3267);
	FT_PRINTF("%-3.3x", 6983);
	FT_PRINTF("%08.5x", 34);
	FT_PRINTF("%08.5x", 0);
	FT_PRINTF("%08.3x", 8375);
	FT_PRINTF("%02.7x", 3267);
	FT_PRINTF("%03.3x", 6983);
	FT_PRINTF("%0-8.5x", 34);
	FT_PRINTF("%0-8.5x", 0);
	FT_PRINTF("%0-8.3x", 8375);
	FT_PRINTF("%0-2.7x", 3267);
	FT_PRINTF("%0-3.3x", 6983);
	FT_PRINTF("%.0x", 0);
	FT_PRINTF("%.x", 0);
	FT_PRINTF("%5.0x", 0);
	FT_PRINTF("%5.x", 0);
	FT_PRINTF("%-5.0x", 0);
	FT_PRINTF("%-5.x", 0);
	FT_PRINTF("%#.0x", 0);
	FT_PRINTF("%#.x", 0);
	FT_PRINTF("%#5.0x", 0);
	FT_PRINTF("%#5.x", 0);
	FT_PRINTF("%#-5.0x", 0);
	FT_PRINTF("%#-5.x", 0);

	return (OK);
}

int	test_ft_printf_bonus_X(void *args)
{
	(void)args;

	FT_PRINTF("this %X number", 17);
	FT_PRINTF("this %X number", 0);
	FT_PRINTF("%X", 3);
	FT_PRINTF("%X", 4294967295u);
	FT_PRINTF("%7X", 33);
	FT_PRINTF("%3X", 0);
	FT_PRINTF("%5X", 52625);
	FT_PRINTF("%2X", 94827);
	FT_PRINTF("%-7X", 33);
	FT_PRINTF("%-3X", 0);
	FT_PRINTF("%-5X", 52625);
	FT_PRINTF("%-4X", 9648627);
	FT_PRINTF("%.5X", 21);
	FT_PRINTF("%.3X", 0);
	FT_PRINTF("%.4X", 5263);
	FT_PRINTF("%.3X", 938862);
	FT_PRINTF("%05X", 43);
	FT_PRINTF("%03X", 0);
	FT_PRINTF("%03X", 698334);
	FT_PRINTF("%8.5X", 34);
	FT_PRINTF("%8.5X", 0);
	FT_PRINTF("%8.3X", 8375);
	FT_PRINTF("%2.7X", 3267);
	FT_PRINTF("%3.3X", 6983);
	FT_PRINTF("%-8.5X", 34);
	FT_PRINTF("%-8.5X", 0);
	FT_PRINTF("%-8.3X", 8375);
	FT_PRINTF("%-2.7X", 3267);
	FT_PRINTF("%-3.3X", 6983);
	FT_PRINTF("%08.5X", 34);
	FT_PRINTF("%08.5X", 0);
	FT_PRINTF("%08.3X", 8375);
	FT_PRINTF("%02.7X", 3267);
	FT_PRINTF("%03.3X", 6983);
	FT_PRINTF("%0-8.5X", 34);
	FT_PRINTF("%0-8.5X", 0);
	FT_PRINTF("%0-8.3X", 8375);
	FT_PRINTF("%0-2.7X", 3267);
	FT_PRINTF("%0-3.3X", 6983);
	FT_PRINTF("%.0X", 0);
	FT_PRINTF("%.X", 0);
	FT_PRINTF("%5.0X", 0);
	FT_PRINTF("%5.X", 0);
	FT_PRINTF("%-5.0X", 0);
	FT_PRINTF("%-5.X", 0);
	FT_PRINTF("%#.0X", 0);
	FT_PRINTF("%#.X", 0);
	FT_PRINTF("%#5.0X", 0);
	FT_PRINTF("%#5.X", 0);
	FT_PRINTF("%#-5.0X", 0);
	FT_PRINTF("%#-5.X", 0);

	return (OK);
}
