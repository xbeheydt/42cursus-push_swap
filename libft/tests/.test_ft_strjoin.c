/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_strjoin.c                                :+:      :+:    :+:   */
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

int	test_ft_strjoin(void *args)
{
	(void)args;
	char	*ret = NULL;

	ret = ft_strjoin("Ipsum ", "Lorem");
	unit_test(strcmp(ret, "Ipsum Lorem") == 0, "");
	free(ret);
	return (OK);
}
