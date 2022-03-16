/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 08:57:31 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	rra(t_stack **a)
{
	if ((*a) && (*a)->next)
	{
		strevrot(a);
		ft_putendl_fd((char *)__func__, 1);
	}
}

void	rrb(t_stack **b)
{
	if ((*b) && (*b)->next)
	{
		strevrot(b);
		ft_putendl_fd((char *)__func__, 1);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((*a) && (*a)->next && (*b) && (*b)->next)
	{
		strevrot(a);
		strevrot(b);
		ft_putendl_fd((char *)__func__, 1);
	}
	else
	{
		rra(a);
		rrb(b);
	}
}
