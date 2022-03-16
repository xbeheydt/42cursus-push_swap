/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_calloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:05:43 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/03/09 11:48:48 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <libft.h>
#include <stdlib.h>
#include <string.h>

int	test_ft_calloc(void *args)
{
	(void)args;
	void	*ret;

	ret = NULL;
	ret = ft_calloc(0, 0);
	unit_test(ret != NULL, "ft_calloc(0, 0) -> ret != NULL");
	free(ret);
	ret = NULL;
	ret = ft_calloc(0, 1);
	unit_test(memcmp(ret, "\0", 1) == 0, "ft_calloc(0, 1) -> ret == '\\0'");
	free(ret);
	ret = NULL;
	ret = ft_calloc(1, 0);
	unit_test(memcmp(ret, "\0", 1) == 0, "ft_calloc(0, 1) -> ret == '\\0'");
	free(ret);
	ret = NULL;
	ret = ft_calloc(6, sizeof(char));
	unit_test(
		memcmp(ret, "\0\0\0\0\0\0", 6) == 0,
		"ft_calloc(6, sizeof(char)) -> ret == '\\0\\0\\0\\0\\0\\0'");
	free(ret);
	return (OK);
}
