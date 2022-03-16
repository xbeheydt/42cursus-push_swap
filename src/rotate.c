/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 08:57:31 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	ra(t_stack **a)
{
	if ((*a) && (*a)->next)
	{
		strot(a);
		ft_putendl_fd((char *)__func__, 1);
	}
}

void	rb(t_stack **b)
{
	if ((*b) && (*b)->next)
	{
		strot(b);
		ft_putendl_fd((char *)__func__, 1);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	if ((*a) && (*a)->next && (*b) && (*b)->next)
	{
		strot(a);
		strot(b);
		ft_putendl_fd((char *)__func__, 1);
	}
	else
	{
		ra(a);
		rb(b);
	}
}
