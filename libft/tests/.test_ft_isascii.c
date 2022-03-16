/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_isascii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:36:44 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/04 13:18:44 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <libft.h>

int	test_ft_isascii(void *args)
{
	(void)args;
	int	i;
	int	ret;
	
	i = 0;
	ret = OK;
	while (i <= 127 && ret == OK)
	{
		ret = ft_isascii(i) ? OK : KO;
		++i;
	}
	if (ret == OK)
		print_ok("values tested, 0 to +127", SPACE);
	else
		print_ko("values tested, 0 to +127", SPACE);
	return (OK);
}
