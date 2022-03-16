/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_strdup.c                                  :+:      :+:    :+:   */
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

int	test_ft_strdup(void *args)
{
	(void)args;
	char	*ret = NULL;

	ret = ft_strdup("");
	unit_test(strcmp(ret, "") == 0, "");
	free(ret);

	ret = ft_strdup("Ipsum");
	unit_test(strcmp(ret, "Ipsum") == 0, "");
	free(ret);
	return (OK);
}
