/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_strlcat.c                                 :+:      :+:    :+:   */
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

int	test_ft_strlcat(void *args)
{
	(void)args;
	char	dst1[11] = "Hello";
	char	dst2[100] = "Hello";

	unit_test(ft_strlcat(dst1, "World", 11) == 10, "");
	unit_test(strcmp(dst1, "HelloWorld") == 0, "");
	unit_test(ft_strlcat(dst2, " World", 50) == 11, "");
	unit_test(strcmp(dst2, "Hello World") == 0, "");
	return (OK);
}
