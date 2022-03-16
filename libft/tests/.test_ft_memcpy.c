/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_memcpy.c                                  :+:      :+:    :+:   */
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
#include <stdlib.h>

int	test_ft_memcpy(void *args)
{
	(void)args;
	char	dst[5] = { 0 };
	char	*src = "Hello";

	unit_test(
		memcmp(ft_memcpy(dst, src, 5), "Hello", 5) == 0,
		"");
	unit_test(
		memcmp(dst, "Hello", 5) == 0,
		"");
	return (OK);
}
