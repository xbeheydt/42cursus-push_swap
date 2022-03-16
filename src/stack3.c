/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 08:57:31 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	stissorted(t_stack *s, int way)
{
	if (!s || !s->next)
		return (-1);
	while (s->next)
	{
		if (!way && s->val > s->next->val)
			return (0);
		if (way && s->val < s->next->val)
			return (0);
		s = s->next;
	}
	return (1);
}

int	stfindi(t_stack *s, int i)
{
	if (!s)
		return (0);
	while (s)
	{
		if (s->val == i)
			return (1);
		s = s->next;
	}
	return (0);
}
