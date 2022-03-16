/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 08:57:31 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>

void	stclear(t_stack **s)
{
	if ((*s))
		stclear(&(*s)->next);
	free((*s));
	(*s) = NULL;
}

void	stswap(t_stack **a, t_stack **b)
{
	if ((*a) && (*b))
	{
		(*a)->val ^= (*b)->val;
		(*b)->val ^= (*a)->val;
		(*a)->val ^= (*b)->val;
	}
}

void	strot(t_stack **s)
{
	if ((*s) && (*s)->next)
		stadd_back(s, stpop_front(s));
}

void	strevrot(t_stack **s)
{
	if ((*s) && (*s)->next)
		stadd_front(s, stpop_back(s));
}

void	stpush(t_stack **src, t_stack **dst)
{
	if ((*src))
		stadd_front(dst, stpop_front(src));
}
