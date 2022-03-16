/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_memcmp.c                                  :+:      :+:    :+:   */
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

int	test_ft_memcmp(void *args)
{
	(void)args;
	unit_test(
		ft_memcmp("Ipsum", "Ipsum", 5) == 0,
		"ft_memcmp(\"Ipsum\", \"Ipsum\", 5) == 0"
	);
	unit_test(
		ft_memcmp("Ipsum", "Hello", 5) != 0,
		"ft_memcmp(\"Ipsum\", \"Hello\", 5) != 0"
	);
	return (OK);
}
