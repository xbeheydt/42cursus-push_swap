/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_isalnum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:05:43 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/03/09 11:48:48 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <libft.h>

int	test_ft_isalpha(void *args)
{
	(void)args;
	int	i;
	int	ret;
	
	i = 0;
	ret = OK;
	while (i <= 127 && ret == OK)
	{
		if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
			ret = ft_isalpha(i) ? OK : KO;
		else
			ret = ft_isalpha(i) ? KO : OK;
		++i;
	}
	unit_test(ret == OK, "values tested, 0 to +127");
	return (OK);
}
