/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:43:21 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/05 13:47:21 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <libft.h>
#include <stdlib.h>
#include <string.h>

int	test_ft_split(void *args)
{
	(void)args;
	char	**ret = NULL;

	ret = ft_split("Ipsum,Lorem", ',');
	unit_test(strcmp(ret[0], "Ipsum") == 0, "");
	unit_test(strcmp(ret[1], "Lorem") == 0, "");
	unit_test(ret[2] == NULL, "");
	free(ret[0]);
	free(ret[1]);
	free(ret[2]);
	free(ret);
	return (OK);
}
