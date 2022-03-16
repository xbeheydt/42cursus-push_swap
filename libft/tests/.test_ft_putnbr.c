/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_putnbr_fd.c                               :+:      :+:    :+:   */
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

int	test_ft_putnbr_fd(void *args)
{
	(void)args;
	int		len;
	char	*ret = NULL;

	catch_fd(1, 1);
	len = ft_putnbr_fd(0, 1, 1);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "0") == 0, "");
	unit_test(len == 1, "");
	free(ret);
	ret = NULL;

	catch_fd(1, 1);
	len = ft_putnbr_fd(42, 1, 1);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "42") == 0, "");
	unit_test(len == 2, "");
	free(ret);
	ret = NULL;

	catch_fd(1, 1);
	len = ft_putnbr_fd(-42, 1, 1);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "-42") == 0, "");
	unit_test(len == 3, "");
	free(ret);
	ret = NULL;

	catch_fd(1, 1);
	len = ft_putnbr_fd(-42, 1, 0);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "42") == 0, "");
	unit_test(len == 2, "");
	free(ret);
	ret = NULL;

	len = ft_putnbr_fd(42, -1, 0);
	unit_test(len == -2, "");
	return (OK);
}
