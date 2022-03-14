/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_stack_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:05:43 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/03/09 11:48:48 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <push_swap.h>
#include <stdlib.h>

static int	*lstadd_content(int i)
{
	int	*val;

	val = NULL;
	val = malloc(sizeof(int));
	if (val)
	{
		*val = i;
	}
	return (val);
}

int	test_stack_rotate(void *args)
{
	(void)args;
	t_stack	*s;

	s = stacknew();
	stackadd_back(&s, lstadd_content(1));
	stackadd_back(&s, lstadd_content(2));
	stackadd_back(&s, lstadd_content(3));

	stack_rotate(&s);
	unit_test(*(int *)s->lst->content == 2, "");
	unit_test(*(int *)s->lst->next->content == 3, "");
	unit_test(*(int *)s->lst->next->next->content == 1, "");
	unit_test(*(int *)s->last->content == 1, "");
	unit_test(s->last->next == NULL, "");

	stackclear(&s);
	return (OK);
}

int	test_stack_rev_rotate(void *args)
{
	(void)args;
	t_stack	*s;

	s = stacknew();
	stackadd_back(&s, lstadd_content(1));
	stackadd_back(&s, lstadd_content(2));
	stackadd_back(&s, lstadd_content(3));

	stack_rev_rotate(&s);
	unit_test(*(int *)s->lst->content == 3, "");
	unit_test(*(int *)s->lst->next->content == 1, "");
	unit_test(*(int *)s->lst->next->next->content == 2, "");
	unit_test(*(int *)s->last->content == 2, "");
	unit_test(s->last->next == NULL, "");

	stackclear(&s);
	return (OK);
}

int	test_stack_push(void *args)
{
	(void)args;
	t_stack	*a;
	t_stack	*b;

	a = stacknew();
	b = stacknew();
	stackadd_back(&a, lstadd_content(1));
	stackadd_back(&a, lstadd_content(2));
	stackadd_back(&a, lstadd_content(3));

	stack_push(&a, &b);
	unit_test(*(int *)a->lst->content == 2, "");
	unit_test(*(int *)a->lst->next->content == 3, "");
	unit_test(*(int *)b->lst->content == 1, "");
	unit_test(a->last->next == NULL, "");
	unit_test(b->last->next == NULL, "");
	unit_test(a->size == 2, "");
	unit_test(b->size == 1, "");

	stackclear(&a);
	stackclear(&b);
	return (OK);
}

int	test_stack_swap(void *args)
{
	(void)args;
	t_stack	*s;

	s = stacknew();
	stackadd_back(&s, lstadd_content(1));
	stackadd_back(&s, lstadd_content(2));
	stackadd_back(&s, lstadd_content(3));

	stack_swap(&s);
	unit_test(*(int *)s->lst->content == 2, "");
	unit_test(*(int *)s->lst->next->content == 1, "");
	unit_test(*(int *)s->lst->next->next->content == 3, "");
	unit_test(s->last->next == NULL, "");

	stackclear(&s);
	return (OK);
}

#define INC 0
#define DEC 1

int	test_stack_issorted(void *args)
{
	(void)args;
	t_stack	*s;

	s = stacknew();
	unit_test(stack_issorted(s, INC) == -1, "neg if empty");
	stackadd_back(&s, lstadd_content(1));
	unit_test(stack_issorted(s, INC) == -1, "neg value when have only one");
	stackadd_back(&s, lstadd_content(2));
	stackadd_back(&s, lstadd_content(3));

	unit_test(stack_issorted(s, INC) == 1, "");
	unit_test(stack_issorted(s, DEC) == 0, "");

	stack_swap(&s);
	unit_test(stack_issorted(s, INC) == 0, "");
	unit_test(stack_issorted(s, DEC) == 0, "");

	stack_rev_rotate(&s);
	unit_test(stack_issorted(s, INC) == 0, "");
	unit_test(stack_issorted(s, DEC) == 1, "");

	stackclear(&s);
	return (OK);
}
