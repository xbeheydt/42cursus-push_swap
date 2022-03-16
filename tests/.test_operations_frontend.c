/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_operations_frontend.c                        :+:      :+:    :+:   */
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
#include <string.h>

int	test_push(void *args)
{
	(void)args;
	t_stack *a = NULL;
	t_stack *b = NULL;
	char	*ret = NULL;

	catch_fd(1, 1);
	
	pa(&a, &b);
	ret = catch_fd(0, 1);
	unit_test(ret == NULL, "");
	free(ret);
	
	stadd_back(&a, stnew(1));
	stadd_back(&a, stnew(2));
	stadd_back(&a, stnew(3));

	catch_fd(1, 1);
	pb(&a, &b);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "pb\n") == 0, "");
	free(ret);

	unit_test(b->val == 1, "");
	unit_test(a->val == 2, "");
	unit_test(a->next->val == 3, "");

	catch_fd(1, 1);
	pa(&a, &b);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "pa\n") == 0, "");
	free(ret);

	unit_test(b == NULL, "");
	unit_test(a->val == 1, "");
	unit_test(a->next->val == 2, "");
	unit_test(a->next->next->val == 3, "");

	catch_fd(1, 1);
	pa(&a, &b);
	ret = catch_fd(0, 1);
	unit_test(ret == NULL, "");
	stclear(&a);
	stclear(&b);
	free(ret);
	return (OK);
}

int	test_ra(void *args)
{
	(void)args;
	t_stack	*a = NULL;
	char	*ret = NULL;

	catch_fd(1, 1);
	ra(&a);
	stadd_back(&a, stnew(1));
	ra(&a);
	stadd_back(&a, stnew(2));
	stadd_back(&a, stnew(3));
	ra(&a);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "ra\n") == 0, "");
	free(ret);
	unit_test(a->val == 2, "");
	unit_test(a->next->val == 3, "");
	unit_test(a->next->next->val == 1, "");
	stclear(&a);
	return (OK);
}

int	test_rb(void *args)
{
	(void)args;
	t_stack	*b = NULL;
	char	*ret = NULL;

	catch_fd(1, 1);
	rb(&b);
	stadd_back(&b, stnew(1));
	rb(&b);
	stadd_back(&b, stnew(2));
	stadd_back(&b, stnew(3));
	rb(&b);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "rb\n") == 0, "");
	free(ret);
	unit_test(b->val == 2, "");
	unit_test(b->next->val == 3, "");
	unit_test(b->next->next->val == 1, "");
	stclear(&b);
	return (OK);
}

int	test_rr(void *args)
{
	(void)args;
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	char	*ret = NULL;

	catch_fd(1, 1);
	rr(&a, &b);

	stadd_back(&a, stnew(11));
	rr(&a, &b);

	stadd_back(&b, stnew(21));
	rr(&a, &b);

	stadd_back(&a, stnew(12));
	rr(&a, &b);

	stclear(&a);

	stadd_back(&b, stnew(22));
	rr(&a, &b);

	stclear(&b);

	stadd_back(&a, stnew(11));
	stadd_back(&b, stnew(21));
	stadd_back(&a, stnew(12));
	stadd_back(&b, stnew(22));
	stadd_back(&a, stnew(13));
	stadd_back(&b, stnew(23));
	rr(&a, &b);

	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "ra\nrb\nrr\n") == 0, "");

	unit_test(a->val == 12, "");
	unit_test(a->next->val == 13, "");
	unit_test(a->next->next->val == 11, "");

	unit_test(b->val == 22, "");
	unit_test(b->next->val == 23, "");
	unit_test(b->next->next->val == 21, "");

	free(ret);
	stclear(&a);
	stclear(&b);

	return (OK);
}

int	test_rra(void *args)
{
	(void)args;
	t_stack	*a = NULL;
	char	*ret = NULL;

	catch_fd(1, 1);
	rra(&a);
	stadd_back(&a, stnew(1));
	rra(&a);
	stadd_back(&a, stnew(2));
	stadd_back(&a, stnew(3));
	rra(&a);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "rra\n") == 0, "");
	free(ret);
	unit_test(a->val == 3, "");
	unit_test(a->next->val == 1, "");
	unit_test(a->next->next->val == 2, "");
	stclear(&a);
	return (OK);
}

int	test_rrb(void *args)
{
	(void)args;
	t_stack	*b = NULL;
	char	*ret = NULL;

	catch_fd(1, 1);
	rrb(&b);
	stadd_back(&b, stnew(1));
	rrb(&b);
	stadd_back(&b, stnew(2));
	stadd_back(&b, stnew(3));
	rrb(&b);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "rrb\n") == 0, "");
	free(ret);
	unit_test(b->val == 3, "");
	unit_test(b->next->val == 1, "");
	unit_test(b->next->next->val == 2, "");
	stclear(&b);
	return (OK);
}

int	test_rrr(void *args)
{
	(void)args;
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	char	*ret = NULL;

	catch_fd(1, 1);
	rrr(&a, &b);

	stadd_back(&a, stnew(11));
	rrr(&a, &b);

	stadd_back(&b, stnew(21));
	rrr(&a, &b);

	stadd_back(&a, stnew(12));
	rrr(&a, &b);

	stclear(&a);

	stadd_back(&b, stnew(22));
	rrr(&a, &b);

	stclear(&b);

	stadd_back(&a, stnew(11));
	stadd_back(&b, stnew(21));
	stadd_back(&a, stnew(12));
	stadd_back(&b, stnew(22));
	stadd_back(&a, stnew(13));
	stadd_back(&b, stnew(23));
	rrr(&a, &b);

	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "rra\nrrb\nrrr\n") == 0, "");

	unit_test(a->val == 13, "");
	unit_test(a->next->val == 11, "");
	unit_test(a->next->next->val == 12, "");

	unit_test(b->val == 23, "");
	unit_test(b->next->val == 21, "");
	unit_test(b->next->next->val == 22, "");

	free(ret);
	stclear(&a);
	stclear(&b);

	return (OK);
}

int	test_sa(void *args)
{
	(void)args;
	t_stack	*a = NULL;
	char	*ret = NULL;
	
	catch_fd(1, 1);

	sa(&a);

	stadd_back(&a, stnew(1));
	sa(&a);

	stadd_back(&a, stnew(2));
	stadd_back(&a, stnew(3));
	sa(&a);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "sa\n") == 0, "");
	free(ret);
	unit_test(a->val == 2, "");
	unit_test(a->next->val == 1, "");
	unit_test(a->next->next->val == 3, "");

	stclear(&a);
	return (OK);
}

int	test_sb(void *args)
{
	(void)args;
	t_stack	*b = NULL;
	char	*ret = NULL;
	
	catch_fd(1, 1);

	sb(&b);

	sb(&b);

	stadd_back(&b, stnew(1));
	sb(&b);

	stadd_back(&b, stnew(2));
	stadd_back(&b, stnew(3));
	sb(&b);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "sb\n") == 0, "");
	free(ret);
	unit_test(b->val == 2, "");
	unit_test(b->next->val == 1, "");
	unit_test(b->next->next->val == 3, "");

	stclear(&b);
	return (OK);
}

int	test_ss(void *args)
{
	(void)args;
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	char	*ret = NULL;

	catch_fd(1, 1);
	ss(&a, &b);

	ss(&a, &b);

	stadd_back(&a, stnew(11));
	ss(&a, &b);

	stadd_back(&b, stnew(21));
	ss(&a, &b);

	stadd_back(&a, stnew(12));
	ss(&a, &b);

	stclear(&a);

	stadd_back(&b, stnew(22));
	ss(&a, &b);

	stclear(&b);

	stadd_back(&a, stnew(11));
	stadd_back(&a, stnew(12));
	stadd_back(&a, stnew(13));
	stadd_back(&b, stnew(21));
	stadd_back(&b, stnew(22));
	stadd_back(&b, stnew(23));
	ss(&a, &b);

	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "sa\nsb\nss\n") == 0, "");

	unit_test(a->val == 12, "");
	unit_test(a->next->val == 11, "");
	unit_test(a->next->next->val == 13, "");

	unit_test(b->val == 22, "");
	unit_test(b->next->val == 21, "");
	unit_test(b->next->next->val == 23, "");

	free(ret);
	stclear(&a);
	stclear(&b);

	return (OK);
}
