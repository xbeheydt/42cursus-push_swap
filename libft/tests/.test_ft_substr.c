/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_substr.c                                  :+:      :+:    :+:   */
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

int	test_ft_substr(void *args)
{
	(void)args;
	char	*ret = NULL;

	ret = ft_substr("Hello World  ,!,,  ", 6, 5);
	unit_test(strcmp(ret, "World") == 0, "");
	free(ret);
	return (OK);
}
