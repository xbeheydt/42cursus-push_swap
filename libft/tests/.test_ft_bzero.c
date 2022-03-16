/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft - .test_ft_bzero.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:05:43 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/03/09 11:48:48 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <libft.h>
#include <string.h>

int	test_ft_bzero(void *args)
{
	(void)args;
	char	s[11] = "Ipsum Lorem";
	ft_bzero(s, 5);
	unit_test(
		memcmp(s, "\0\0\0\0\0 Lorem", 11) == 0,
		"'Ipsum Lorem' -> '\\0\\0\\0\\0\\0 Lorem'"
	);
	return (OK);
}
