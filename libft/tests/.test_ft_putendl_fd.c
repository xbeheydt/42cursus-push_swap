/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_putendl_fd.c                              :+:      :+:    :+:   */
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

int	test_ft_putendl_fd(void *args)
{
	(void)args;

	catch_fd(1, 1);
	int len = ft_putendl_fd("Hello", 1);
	char	*ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "Hello\n") == 0, "");
	unit_test(len == 6, "");
	free(ret);
	return (OK);
}
