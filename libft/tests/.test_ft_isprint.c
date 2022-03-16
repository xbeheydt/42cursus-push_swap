/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_isprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:05:43 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/03/09 11:48:48 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <libft.h>
#include <ctype.h>

int	test_ft_isprint(void *args)
{
	(void)args;
	int	i;
	int	ret;
	
	i = 0;
	ret = OK;
	while (i <= 127 && ret == OK)
	{
		if (isprint(i))
			ret = ft_isprint(i) == 1 ? OK : KO;
		else
			ret = ft_isprint(i) == 0 ? OK : KO;
		++i;
	}
	unit_test(ret == OK, "values tested, 0 to +127");
	return (OK);
}
