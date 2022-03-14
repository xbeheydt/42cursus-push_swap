/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_stack_handling.c                             :+:      :+:    :+:   */
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

int	test_stacknew(void *args)
{
	(void)args;
	t_stack	*s;

	s = NULL;
	s = stacknew();
	unit_test(s->lst == NULL, "");
	unit_test(s->last == NULL, "");
	unit_test(s->size == 0, "");
	free(s);
	return (OK);
}

int	test_stackadd_back(void *args)
{
	(void)args;
	t_stack	*s;

	s = stacknew();
	stackadd_back(&s, lstadd_content(1));
	unit_test(s->lst == s->last, "");
	unit_test(*(int *)s->lst->content == 1, "");

	stackadd_back(&s, lstadd_content(2));
	stackadd_back(&s, lstadd_content(3));
	unit_test(s->lst != s->last, "");
	unit_test(*(int *)s->lst->content == 1, "");
	unit_test(*(int *)s->lst->next->content == 2, "");
	unit_test(*(int *)s->last->content == 3, "");
	unit_test(s->size == 3, "");

	free(s->last->content);
	free(s->last);
	free(s->lst->next->content);
	free(s->lst->next);
	free(s->lst->content);
	free(s->lst);
	free(s);
	return (OK);
}

int	test_stackadd_front(void *args)
{
	(void)args;
	t_stack	*s;

	s = stacknew();
	stackadd_front(&s, lstadd_content(1));
	unit_test(s->lst == s->last, "");
	unit_test(*(int *)s->lst->content == 1, "");

	stackadd_front(&s, lstadd_content(2));
	stackadd_front(&s, lstadd_content(3));
	unit_test(s->lst != s->last, "");
	unit_test(*(int *)s->lst->content == 3, "");
	unit_test(*(int *)s->lst->next->content == 2, "");
	unit_test(*(int *)s->last->content == 1, "");
	unit_test(s->size == 3, "");

	free(s->last->content);
	free(s->last);
	free(s->lst->next->content);
	free(s->lst->next);
	free(s->lst->content);
	free(s->lst);
	free(s);
	return (OK);
}

int	test_stackclear(void *args)
{
	(void)args;
	t_stack	*s;

	s = stacknew();
	stackadd_front(&s, lstadd_content(1));
	stackadd_front(&s, lstadd_content(2));
	stackadd_front(&s, lstadd_content(3));

	stackclear(&s);
	unit_test(s == NULL, "");
	return (OK);
}
