/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_atol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:05:43 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/03/09 11:48:48 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <libft.h>
#include <limits.h>

int	test_ft_atol(void *args)
{
	(void)args;
	long	ret;

	ret = ft_atol("0");
	unit_test(ret == 0, "0");

	ret = ft_atol("-42");
	unit_test(ret == -42, "-42");

	ret = ft_atol("10");
	unit_test(ret == 10, "10");

	ret = ft_atol("-9223372036854775808");
	unit_test(ret == LONG_MIN, "LONG_MIN");

	ret = ft_atol("+9223372036854775807");
	unit_test(ret == LONG_MAX, "LONG_MAX");

	ret = ft_atol("+21474 83647");
	unit_test(ret == +21474, "+21474 83647");

	ret = ft_atol("-+21474");
	unit_test(ret == 0, "-+21474");
	return (OK);
}
