/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_strmapi.c                                 :+:      :+:    :+:   */
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

static char	f(unsigned int i, char c)
{
	(void)i;
	return (ft_toupper(c));
}

int	test_ft_strmapi(void *args)
{
	(void)args;

	char *ret = ft_strmapi("Ipsum Lorem", f);
	unit_test(strcmp(ret, "IPSUM LOREM") == 0, "");
	free(ret);
	return (OK);
}
