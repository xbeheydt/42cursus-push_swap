/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_isspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:36:44 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/04 13:18:44 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <libft.h>

int	test_ft_isspace(void *args)
{
	(void)args;
	int	i;
	int	ret;
	
	i = 0;
	ret = OK;
	while (i <= 127 && ret == OK)
	{
		if (i == ' ' || i == '\f' || i == '\n'
				|| i == '\r' || i == '\t' || i == '\v')
			ret = ft_isspace(i) ? OK : KO;
		else
			ret = ft_isspace(i) ? KO : OK;
		++i;
	}
	unit_test(ret == OK, "values tested, 0 to +127");
	return (OK);
}
