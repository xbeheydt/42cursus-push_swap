/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_tolower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:43:21 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/05 13:47:21 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <libft.h>

int	test_ft_tolower(void *args)
{
	(void)args;

	unit_test(ft_tolower('h') == 'h', "");
	unit_test(ft_tolower('H') == 'h', "");
	return (OK);
}
