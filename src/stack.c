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

static void	lstclear_content(void *content)
{
	free(content);
	content = NULL;
}

/* Public API */

t_stack	*stacknew(void)
{
	t_stack	*s;

	s = NULL;
	s = malloc(sizeof(t_stack));
	if (s)
	{
		s->lst = NULL;
		s->last = NULL;
		s->size = 0;
	}
	return (s);
}

void	stackadd_back(t_stack **s, int *val)
{
	(*s)->last = ft_lstnew(val);
	ft_lstadd_back(&((*s)->lst), (*s)->last);
	(*s)->size++;
}

void	stackadd_front(t_stack **s, int *val)
{
	ft_lstadd_front(&((*s)->lst), ft_lstnew(val));
	if ((*s)->last == NULL)
		(*s)->last = (*s)->lst;
	(*s)->size++;
}

void	stackclear(t_stack **s)
{
	if ((*s))
	{
		ft_lstclear(&((*s)->lst), lstclear_content);
		(*s)->lst = NULL;
		(*s)->last = NULL;
		free((*s));
		(*s) = NULL;
	}
}
