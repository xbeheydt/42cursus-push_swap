/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 08:39:25 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 08:43:49 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	ret;

	ret = 0;
	while (*s)
		ret += ft_putchar_fd(*s++, fd);
	return (ret);
}
