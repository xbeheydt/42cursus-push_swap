/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_striteri.c                                :+:      :+:    :+:   */
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

void	f(unsigned int i, char *s)
{
	if (s[i])
		s[i] = ft_toupper(s[i]);
}

int	test_ft_striteri(void *args)
{
	(void)args;
	char	s[12] = "Ipsum Lorem";

	ft_striteri(s, f);
	unit_test(strcmp(s, "IPSUM LOREM") == 0, "");
	return (OK);
}
