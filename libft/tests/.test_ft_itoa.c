/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:36:44 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/04 13:18:44 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <libft.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int	test_ft_itoa(void *args)
{
	(void)args;
	char	*ret;

	ret = ft_itoa(INT_MIN);
	unit_test(strcmp(ret, "-2147483648") == 0, "ft_itoa(INT_MIN) == '-2147483648'");
	free(ret);
	ret = ft_itoa(INT_MAX);
	unit_test(strcmp(ret, "2147483647") == 0, "ft_itoa(INT_MAX) == '2147483647'");
	free(ret);
	ret = ft_itoa(0);
	unit_test(strcmp(ret, "0") == 0, "ft_itoa(0) == '0'");
	free(ret);
	ret = ft_itoa(42);
	unit_test(strcmp(ret, "42") == 0, "ft_itoa(42) == '42'");
	free(ret);
	return (OK);
}
