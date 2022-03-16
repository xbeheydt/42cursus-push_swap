/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_putstr_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:43:21 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/05 13:47:21 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <libft.h>
#include <string.h>

int	test_ft_putstr_fd(void *args)
{
	(void)args;

	catch_fd(1, 1);
	int len = ft_putstr_fd("Hello", 1);
	char	*ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "Hello") == 0, "");
	unit_test(len == 5, "");
	free(ret);
	unit_test(ft_putstr_fd("Test", -1) == -4, "");
	return (OK);
}
