/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_memchr.c                                  :+:      :+:    :+:   */
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

int	test_ft_memchr(void *args)
{
	(void)args;
	unit_test(
		memcmp(ft_memchr("Ipsum", 'p', 5), "psum", 4) == 0,
		"ft_memch(\"Ipsum\", 'p') == \"psum\"");
	unit_test(
		ft_memchr("Ipsum", 'a', 5) == NULL,
		"ft_memch(\"Ipsum\", 'a') == NULL");
	return (OK);
}
