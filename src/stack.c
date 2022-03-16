/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 08:57:31 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stdlib.h>

/* Private functions */

/* Public API */

t_stack	*stnew(int val)
{
	t_stack	*s;

	s = NULL;
	s = malloc(sizeof(t_stack));
	if (s)
	{
		s->val = val;
		s->next = NULL;
	}
	return (s);
}

void	stadd_back(t_stack **s, t_stack *n)
{
	t_stack	*cur;

	if ((*s))
	{
		cur = (*s);
		while (cur->next)
			cur = cur->next;
		cur->next = n;
	}
	else
		(*s) = n;
}

void	stadd_front(t_stack **s, t_stack *n)
{
	if ((*s))
	{
		n->next = (*s);
	}
	(*s) = n;
}

t_stack	*stpop_back(t_stack **s)
{
	t_stack	*cur;
	t_stack	*last;

	cur = (*s);
	if (cur == NULL || cur->next == NULL)
	{
		(*s) = NULL;
		return (cur);
	}
	while (cur && cur->next && cur->next->next)
	{
		cur = cur->next;
	}
	last = cur->next;
	cur->next = NULL;
	return (last);
}

t_stack	*stpop_front(t_stack **s)
{
	t_stack	*front;

	front = (*s);
	if (front == NULL || front->next == NULL)
	{
		(*s) = NULL;
		return (front);
	}
	(*s) = (*s)->next;
	front->next = NULL;
	return (front);
}
