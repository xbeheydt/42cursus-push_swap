/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 08:57:31 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

#define INC	0
#define DEC 1

/* Private functions */

/* Public API */

void	stack_rotate(t_stack **s)
{
	t_list	*head;

	if ((*s) && (*s)->lst)
	{
		head = ft_lstpop_front(&((*s)->lst));
		(*s)->last = head;
		ft_lstadd_back(&((*s)->lst), head);
	}
}

void	stack_rev_rotate(t_stack **s)
{
	t_list	*last;

	if ((*s) && (*s)->lst)
	{
		last = ft_lstpop_back(&((*s)->lst));
		ft_lstadd_front(&((*s)->lst), last);
		(*s)->last = ft_lstlast((*s)->lst);
	}
}

void	stack_push(t_stack **a, t_stack **b)
{
	if ((*a) && (*a)->lst && (*b))
	{
		ft_lstadd_front(&((*b)->lst), ft_lstpop_front(&((*a)->lst)));
		if ((*b)->last == NULL)
			(*b)->last = (*b)->lst;
		(*a)->size--;
		(*b)->size++;
		if ((*a)->lst == NULL)
			(*a)->last = NULL;
	}
}

void	stack_swap(t_stack **s)
{
	int	*tmp;

	if ((*s) && (*s)->lst)
	{
		tmp = (*s)->lst->content;
		(*s)->lst->content = (*s)->lst->next->content;
		(*s)->lst->next->content = tmp;
	}
}

int	stack_issorted(t_stack *s, int dir)
{
	t_list	*cur;

	if (!s || s->lst == NULL || s->size == 1)
		return (-1);
	cur = s->lst;
	while (cur != s->last)
	{
		if (!dir && *(int *)cur->content > *(int *)cur->next->content)
			return (0);
		if (dir && *(int *)cur->content < *(int *)cur->next->content)
			return (0);
		cur = cur->next;
	}
	return (1);
}
