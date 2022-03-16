/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_putchar_fd.c                              :+:      :+:    :+:   */
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

int	test_ft_putchar_fd(void *args)
{
	(void)args;

	catch_fd(1, 1);
	ft_putchar_fd('H', 1);
	ft_putchar_fd('E', 1);
	ft_putchar_fd('L', 1);
	char	*ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "HEL") == 0, "");
	free(ret);
	return (OK);
}
