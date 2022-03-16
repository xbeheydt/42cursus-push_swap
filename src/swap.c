/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 08:57:31 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	sa(t_stack **a)
{
	if ((*a) && (*a)->next)
	{
		stswap(a, &(*a)->next);
		ft_putendl_fd((char *)__func__, 1);
	}
}

void	sb(t_stack **b)
{
	if ((*b) && (*b)->next)
	{
		stswap(b, &(*b)->next);
		ft_putendl_fd((char *)__func__, 1);
	}
}

void	ss(t_stack **a, t_stack **b)
{
	if ((*a) && (*a)->next && (*b) && (*b)->next)
	{
		stswap(a, &(*a)->next);
		stswap(b, &(*b)->next);
		ft_putendl_fd((char *)__func__, 1);
	}
	else
	{
		sa(a);
		sb(b);
	}
}
