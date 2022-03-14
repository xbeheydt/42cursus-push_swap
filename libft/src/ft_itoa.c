/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:10:13 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/15 15:40:46 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa(int n)
{
	char	tmp[13];
	int		i;
	int		t;

	i = n;
	t = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		tmp[t++] = '-';
	while (i)
	{
		++t;
		i /= 10;
	}
	tmp[t] = '\0';
	while (n)
	{
		if (n < 0)
			tmp[--t] = '0' + -(n % 10);
		else
			tmp[--t] = '0' + (n % 10);
		n /= 10;
	}
	return (ft_strdup(tmp));
}
