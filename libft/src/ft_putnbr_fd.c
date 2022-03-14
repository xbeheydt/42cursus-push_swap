/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 08:44:48 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 09:09:13 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putnbr_fd(int n, int fd, int sign)
{
	int	ret;

	ret = 0;
	if (sign && n < 0)
		ret += ft_putchar_fd('-', fd);
	if (n <= -10 || 10 <= n)
	{
		if (n < 0)
			ret += ft_putnbr_fd(-(n / 10), fd, sign);
		else
			ret += ft_putnbr_fd((n / 10), fd, sign);
	}
	if (n > 0)
		ret += ft_putchar_fd('0' + (n % 10), fd);
	else
		ret += ft_putchar_fd('0' + -(n % 10), fd);
	return (ret);
}
