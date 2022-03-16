/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:02:37 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/05 07:00:40 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long	ft_atol(const char *nptr)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*nptr) && *nptr != '\0')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr) && *nptr)
		ret = (ret * 10) + (*nptr++ - '0');
	return (ret * sign);
}
