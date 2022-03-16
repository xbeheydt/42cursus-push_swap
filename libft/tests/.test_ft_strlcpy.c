/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_strlcpy.c                                 :+:      :+:    :+:   */
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
#include <stddef.h>

int	test_ft_strlcpy(void *args)
{
	(void)args;
	char	dst1[11];
	char	dst2[100];

	unit_test(ft_strlcpy(dst1, "Hello", 100) == 5, "");
	unit_test(strcmp(dst1, "Hello") == 0, "");
	unit_test(ft_strlcpy(dst2, "Hello World", 12) == 11, "");
	unit_test(strcmp(dst2, "Hello World") == 0, "");
	return (OK);
}
