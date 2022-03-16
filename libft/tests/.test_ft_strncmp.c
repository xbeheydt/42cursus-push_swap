/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_strncmp.c                                 :+:      :+:    :+:   */
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

int	test_ft_strncmp(void *args)
{
	(void)args;
	
	unit_test(ft_strncmp("Hello", "Hello World", 5) == 0, "");
	unit_test(ft_strncmp("Hello World", "Hello World", 100) == 0, "");
	unit_test(ft_strncmp("Hello World", "Hello World", -1) == 0, "");
	return (OK);
}
