/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_strchr.c                                  :+:      :+:    :+:   */
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

int	test_ft_strchr(void *args)
{
	(void)args;
	unit_test(
		strcmp(ft_strchr("Ipsum", 'p'), "psum") == 0,
		"ft_strch(\"Ipsum\", 'p') == \"psum\"");
	unit_test(
		ft_strchr("Ipsum", 'a') == NULL,
		"ft_strch(\"Ipsum\", 'a') == NULL");
	return (OK);
}
