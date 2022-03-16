/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_atoi.c                                    :+:      :+:    :+:   */
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

int	test_ft_atoi(void *args)
{
	(void)args;
	int	ret;

	ret = ft_atoi("0");
	unit_test(ret == 0, "0");

	ret = ft_atoi("-42");
	unit_test(ret == -42, "-42");

	ret = ft_atoi("10");
	unit_test(ret == 10, "10");

	ret = ft_atoi("-2147483648");
	unit_test(ret == INT_MIN, "INT_MIN");

	ret = ft_atoi("+2147483647");
	unit_test(ret == INT_MAX, "INT_MAX");

	ret = ft_atoi("+21474 83647");
	unit_test(ret == +21474, "+21474 83647");

	ret = ft_atoi("-+21474");
	unit_test(ret == 0, "-+21474");
	return (OK);
}
