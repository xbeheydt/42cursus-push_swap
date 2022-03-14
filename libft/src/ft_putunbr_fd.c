/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  libft - ft_putunbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 08:44:48 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/29 06:43:27 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	ret;

	ret = 0;
	if (10 <= n)
		ret += ft_putunbr_fd((n / 10), fd);
	ret += ft_putchar_fd('0' + (n % 10), fd);
	return (ret);
}
