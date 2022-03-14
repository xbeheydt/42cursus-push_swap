/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft - ft_puthnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 08:44:48 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/29 06:43:27 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_puthnbr_fd(unsigned long long int n, int fd, int ccase)
{
	int	ret;

	ret = 0;
	if (16 <= n)
		ret += ft_puthnbr_fd((n / 16), fd, ccase);
	if ((n % 16) > 9)
	{
		if (ccase == LOWERCASE)
			ret += ft_putchar_fd(87 + (n % 16), fd);
		else
			ret += ft_putchar_fd(ft_toupper(87 + (n % 16)), fd);
	}
	else
		ret += ft_putchar_fd('0' + (n % 16), fd);
	return (ret);
}
