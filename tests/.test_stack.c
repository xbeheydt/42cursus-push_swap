/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_stack.c                                      :+:      :+:    :+:   */
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

int	test_stnew(void *args)
{
	(void)args;
	t_stack	*s;

	s = stnew(5);
	unit_test(s->val == 5, "");
	unit_test(s->next == NULL, "");
	free(s);
	return (OK);
}

int	test_stclear(void *args)
{
	(void)args;
	t_stack	*s;

	s = stnew(1);
	s->next = stnew(2);
	unit_test(s->val == 1, "");
	unit_test(s->next->val == 2, "");
	stclear(&s);
	unit_test(s == NULL, "");
	return (OK);
}

int	test_stadd_back(void *args)
{
	(void)args;
	t_stack	*s = NULL;
	
	stadd_back(&s, stnew(1));
	stadd_back(&s, stnew(2));
	stadd_back(&s, stnew(3));
	unit_test(s->val == 1, "");
	unit_test(s->next->val == 2, "");
	unit_test(s->next->next->val == 3, "");
	unit_test(s->next->next->next == NULL, "");
	stclear(&s);
	unit_test(s == NULL, "");
	return (OK);
}

int	test_stadd_front(void *args)
{
	(void)args;
	t_stack	*s = NULL;
	
	stadd_front(&s, stnew(1));
	stadd_front(&s, stnew(2));
	stadd_front(&s, stnew(3));
	unit_test(s->val == 3, "");
	unit_test(s->next->val == 2, "");
	unit_test(s->next->next->val == 1, "");
	unit_test(s->next->next->next == NULL, "");
	stclear(&s);
	unit_test(s == NULL, "");
	return (OK);
}

int	test_stpop_back(void *args)
{
	(void)args;
	t_stack	*lst = NULL, *last = NULL;


	stadd_back(&lst, stnew(1));
	stadd_back(&lst, stnew(2));
	stadd_back(&lst, stnew(3));

	last = stpop_back(&lst);
	unit_test(last->next == NULL, "");
	unit_test(last->val == 3, "");
	unit_test(lst->val == 1, "");
	unit_test(lst->next->val == 2, "");
	unit_test(lst->next->next == NULL, "");
	free(last);

	last = stpop_back(&lst);
	unit_test(last->next == NULL, "");
	unit_test(last->val == 2, "");
	unit_test(lst->val == 1, "");
	unit_test(lst->next == NULL, "");
	free(last);

	last = stpop_back(&lst);
	unit_test(last->next == NULL, "");
	unit_test(last->val == 1, "");
	unit_test(lst == NULL, "");
	free(last);

	last = stpop_back(&lst);
	unit_test(last == NULL, "");
	return (OK);
}

int	test_stpop_front(void *args)
{
	(void)args;
	t_stack	*lst = NULL, *head = NULL;


	stadd_back(&lst, stnew(1));
	stadd_back(&lst, stnew(2));
	stadd_back(&lst, stnew(3));

	head = stpop_front(&lst);
	unit_test(head->next == NULL, "");
	unit_test(head->val == 1, "");
	unit_test(lst->val == 2, "");
	unit_test(lst->next->val == 3, "");
	unit_test(lst->next->next == NULL, "");
	free(head);

	head = stpop_front(&lst);
	unit_test(head->next == NULL, "");
	unit_test(head->val == 2, "");
	unit_test(lst->val == 3, "");
	unit_test(lst->next == NULL, "");
	free(head);

	head = stpop_front(&lst);
	unit_test(head->next == NULL, "");
	unit_test(head->val == 3, "");
	unit_test(lst == NULL, "");
	free(head);

	head = stpop_front(&lst);
	unit_test(head == NULL, "");
	return (OK);
}

int	test_stswap(void *args)
{
	(void)args;
	t_stack	*s = NULL;

	stadd_back(&s, stnew(1));
	stswap(&s, &s->next);
	stadd_back(&s, stnew(42));
	stswap(&s, &s->next);
	unit_test(s->val == 42, "");
	unit_test(s->next->val == 1, "");
	stclear(&s);
	return (OK);
}

int	test_strot(void *args)
{
	(void)args;
	t_stack	*s = NULL;

	strot(&s);
	stadd_back(&s, stnew(1));
	strot(&s);
	stadd_back(&s, stnew(2));
	strot(&s);
	unit_test(s->val == 2, "");
	unit_test(s->next->val == 1, "");
	stadd_back(&s, stnew(3));
	strot(&s);
	unit_test(s->val == 1, "");
	unit_test(s->next->val == 3, "");
	unit_test(s->next->next->val == 2, "");
	stclear(&s);
	return (OK);
}

int	test_strevrot(void *args)
{
	(void)args;
	t_stack	*s = NULL;

	strevrot(&s);
	stadd_back(&s, stnew(1));
	strevrot(&s);
	stadd_back(&s, stnew(2));
	strevrot(&s);
	unit_test(s->val == 2, "");
	unit_test(s->next->val == 1, "");
	stadd_back(&s, stnew(3));
	strevrot(&s);
	unit_test(s->val == 3, "");
	unit_test(s->next->val == 2, "");
	unit_test(s->next->next->val == 1, "");
	stclear(&s);
	return (OK);
}

int	test_stpush(void *args)
{
	(void)args;
	t_stack	*a = NULL,	*b = NULL;

	stpush(&a, &b);
	stadd_back(&a, stnew(1));
	stadd_back(&a, stnew(2));
	stadd_back(&a, stnew(3));

	stpush(&a, &b);
	stpush(&a, &b);
	stpush(&a, &b);
	unit_test(a == NULL, "");
	unit_test(b->val == 3, "");
	unit_test(b->next->val == 2, "");
	unit_test(b->next->next->val == 1, "");
	unit_test(b->next->next->next == NULL, "");
	stclear(&b);
	return (OK);
}

int	test_stissorted(void *args)
{
	(void)args;
	t_stack	*s = NULL;

	unit_test(stissorted(s, 0) == -1, "");
	unit_test(stissorted(s, 1) == -1, "");
	stadd_back(&s, stnew(1));
	unit_test(stissorted(s, 0) == -1, "");
	unit_test(stissorted(s, 1) == -1, "");
	stadd_back(&s, stnew(2));
	stadd_back(&s, stnew(3));
	stadd_back(&s, stnew(4));
	unit_test(stissorted(s, 0) == 1, "");
	unit_test(stissorted(s, 1) == 0, "");


	stadd_back(&s, stnew(-1));
	unit_test(stissorted(s, 0) == 0, "");
	unit_test(stissorted(s, 1) == 0, "");
	t_stack *last = stpop_back(&s);
	free(last);
	strot(&s);
	unit_test(stissorted(s, 0) == 0, "");
	unit_test(stissorted(s, 1) == 0, "");
	stclear(&s);
	
	stadd_front(&s, stnew(1));
	stadd_front(&s, stnew(2));
	stadd_front(&s, stnew(3));
	stadd_front(&s, stnew(4));
	unit_test(stissorted(s, 0) == 0, "");
	unit_test(stissorted(s, 1) == 1, "");
	stclear(&s);
	return (OK);
}

int	test_stfindi(void *args)
{
	(void)args;
	t_stack *s = NULL;

	unit_test(stfindi(s, 42) == 0, "");
	stadd_front(&s, stnew(1));
	unit_test(stfindi(s, 42) == 0, "");
	stadd_front(&s, stnew(12));
	stadd_front(&s, stnew(5));
	stadd_front(&s, stnew(56));
	unit_test(stfindi(s, 42) == 0, "");
	stadd_front(&s, stnew(42));
	unit_test(stfindi(s, 42) == 1, "");
	stclear(&s);
	return (OK);
}
