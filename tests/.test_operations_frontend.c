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

#define INT *(int *)

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

int	test_push(void *args)
{
	(void)args;
	t_stack *a = NULL;
	t_stack *b = NULL;
	char	*ret = NULL;

	catch_fd(1, 1);
	
	pa(&a, &b);

	a = stacknew();
	b = stacknew();
	pa(&a, &b);
	ret = catch_fd(0, 1);
	unit_test(ret == NULL, "");
	free(ret);
	
	stackadd_back(&a, lstadd_content(1));
	stackadd_back(&a, lstadd_content(2));
	stackadd_back(&a, lstadd_content(3));

	catch_fd(1, 1);
	pb(&a, &b);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "pb\n") == 0, "");
	free(ret);

	unit_test(INT b->lst->content == 1, "");
	unit_test(INT a->lst->content == 2, "");
	unit_test(INT a->lst->next->content == 3, "");

	catch_fd(1, 1);
	pa(&a, &b);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "pa\n") == 0, "");
	free(ret);

	unit_test(b->lst == NULL, "");
	unit_test(INT a->lst->content == 1, "");
	unit_test(INT a->lst->next->content == 2, "");
	unit_test(INT a->last->content == 3, "");

	catch_fd(1, 1);
	pa(&a, &b);
	ret = catch_fd(0, 1);
	unit_test(ret == NULL, "");
	stackclear(&a);
	stackclear(&b);
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
	a = stacknew();
	ra(&a);
	stackadd_back(&a, lstadd_content(1));
	ra(&a);
	stackadd_back(&a, lstadd_content(2));
	stackadd_back(&a, lstadd_content(3));
	ra(&a);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "ra\n") == 0, "");
	free(ret);
	unit_test(INT a->lst->content == 2, "");
	unit_test(INT a->lst->next->content == 3, "");
	unit_test(INT a->lst->next->next->content == 1, "");
	unit_test(INT a->last->content == 1, "");
	stackclear(&a);
	return (OK);
}

int	test_rb(void *args)
{
	(void)args;
	t_stack	*b = NULL;
	char	*ret = NULL;

	catch_fd(1, 1);
	rb(&b);
	b = stacknew();
	rb(&b);
	stackadd_back(&b, lstadd_content(1));
	rb(&b);
	stackadd_back(&b, lstadd_content(2));
	stackadd_back(&b, lstadd_content(3));
	rb(&b);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "rb\n") == 0, "");
	free(ret);
	unit_test(INT b->lst->content == 2, "");
	unit_test(INT b->lst->next->content == 3, "");
	unit_test(INT b->lst->next->next->content == 1, "");
	unit_test(INT b->last->content == 1, "");
	stackclear(&b);
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

	a = stacknew();
	b = stacknew();
	rr(&a, &b);

	stackadd_back(&a, lstadd_content(11));
	rr(&a, &b);

	stackadd_back(&b, lstadd_content(21));
	rr(&a, &b);

	stackadd_back(&a, lstadd_content(12));
	rr(&a, &b);

	stackclear(&a);
	a = stacknew();

	stackadd_back(&b, lstadd_content(22));
	rr(&a, &b);

	stackclear(&b);
	b = stacknew();

	stackadd_back(&a, lstadd_content(11));
	stackadd_back(&b, lstadd_content(21));
	stackadd_back(&a, lstadd_content(12));
	stackadd_back(&b, lstadd_content(22));
	stackadd_back(&a, lstadd_content(13));
	stackadd_back(&b, lstadd_content(23));
	rr(&a, &b);

	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "ra\nrb\nrr\n") == 0, "");

	unit_test(INT a->lst->content == 12, "");
	unit_test(INT a->lst->next->content == 13, "");
	unit_test(INT a->lst->next->next->content == 11, "");

	unit_test(INT b->lst->content == 22, "");
	unit_test(INT b->lst->next->content == 23, "");
	unit_test(INT b->lst->next->next->content == 21, "");

	free(ret);
	stackclear(&a);
	stackclear(&b);

	return (OK);
}

int	test_rra(void *args)
{
	(void)args;
	t_stack	*a = NULL;
	char	*ret = NULL;

	catch_fd(1, 1);
	rra(&a);
	a = stacknew();
	rra(&a);
	stackadd_back(&a, lstadd_content(1));
	rra(&a);
	stackadd_back(&a, lstadd_content(2));
	stackadd_back(&a, lstadd_content(3));
	rra(&a);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "rra\n") == 0, "");
	free(ret);
	unit_test(INT a->lst->content == 3, "");
	unit_test(INT a->lst->next->content == 1, "");
	unit_test(INT a->lst->next->next->content == 2, "");
	unit_test(INT a->last->content == 2, "");
	stackclear(&a);
	return (OK);
}

int	test_rrb(void *args)
{
	(void)args;
	t_stack	*b = NULL;
	char	*ret = NULL;

	catch_fd(1, 1);
	rrb(&b);
	b = stacknew();
	rrb(&b);
	stackadd_back(&b, lstadd_content(1));
	rrb(&b);
	stackadd_back(&b, lstadd_content(2));
	stackadd_back(&b, lstadd_content(3));
	rrb(&b);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "rrb\n") == 0, "");
	free(ret);
	unit_test(INT b->lst->content == 3, "");
	unit_test(INT b->lst->next->content == 1, "");
	unit_test(INT b->lst->next->next->content == 2, "");
	unit_test(INT b->last->content == 2, "");
	stackclear(&b);
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

	a = stacknew();
	b = stacknew();
	rrr(&a, &b);

	stackadd_back(&a, lstadd_content(11));
	rrr(&a, &b);

	stackadd_back(&b, lstadd_content(21));
	rrr(&a, &b);

	stackadd_back(&a, lstadd_content(12));
	rrr(&a, &b);

	stackclear(&a);
	a = stacknew();

	stackadd_back(&b, lstadd_content(22));
	rrr(&a, &b);

	stackclear(&b);
	b = stacknew();

	stackadd_back(&a, lstadd_content(11));
	stackadd_back(&b, lstadd_content(21));
	stackadd_back(&a, lstadd_content(12));
	stackadd_back(&b, lstadd_content(22));
	stackadd_back(&a, lstadd_content(13));
	stackadd_back(&b, lstadd_content(23));
	rrr(&a, &b);

	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "rra\nrrb\nrrr\n") == 0, "");

	unit_test(INT a->lst->content == 13, "");
	unit_test(INT a->lst->next->content == 11, "");
	unit_test(INT a->lst->next->next->content == 12, "");

	unit_test(INT b->lst->content == 23, "");
	unit_test(INT b->lst->next->content == 21, "");
	unit_test(INT b->lst->next->next->content == 22, "");

	free(ret);
	stackclear(&a);
	stackclear(&b);

	return (OK);
}

int	test_sa(void *args)
{
	(void)args;
	t_stack	*a = NULL;
	char	*ret = NULL;
	
	catch_fd(1, 1);

	sa(&a);

	a = stacknew();
	sa(&a);

	stackadd_back(&a, lstadd_content(1));
	sa(&a);

	stackadd_back(&a, lstadd_content(2));
	stackadd_back(&a, lstadd_content(3));
	sa(&a);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "sa\n") == 0, "");
	free(ret);
	unit_test(INT a->lst->content == 2, "");
	unit_test(INT a->lst->next->content == 1, "");
	unit_test(INT a->lst->next->next->content == 3, "");

	stackclear(&a);
	return (OK);
}

int	test_sb(void *args)
{
	(void)args;
	t_stack	*b = NULL;
	char	*ret = NULL;
	
	catch_fd(1, 1);

	sb(&b);

	b = stacknew();
	sb(&b);

	stackadd_back(&b, lstadd_content(1));
	sb(&b);

	stackadd_back(&b, lstadd_content(2));
	stackadd_back(&b, lstadd_content(3));
	sb(&b);
	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "sb\n") == 0, "");
	free(ret);
	unit_test(INT b->lst->content == 2, "");
	unit_test(INT b->lst->next->content == 1, "");
	unit_test(INT b->lst->next->next->content == 3, "");

	stackclear(&b);
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

	a = stacknew();
	b = stacknew();
	ss(&a, &b);

	stackadd_back(&a, lstadd_content(11));
	ss(&a, &b);

	stackadd_back(&b, lstadd_content(21));
	ss(&a, &b);

	stackadd_back(&a, lstadd_content(12));
	ss(&a, &b);

	stackclear(&a);
	a = stacknew();

	stackadd_back(&b, lstadd_content(22));
	ss(&a, &b);

	stackclear(&b);
	b = stacknew();

	stackadd_back(&a, lstadd_content(11));
	stackadd_back(&a, lstadd_content(12));
	stackadd_back(&a, lstadd_content(13));
	stackadd_back(&b, lstadd_content(21));
	stackadd_back(&b, lstadd_content(22));
	stackadd_back(&b, lstadd_content(23));
	ss(&a, &b);

	ret = catch_fd(0, 1);
	unit_test(strcmp(ret, "sa\nsb\nss\n") == 0, "");

	unit_test(INT a->lst->content == 12, "");
	unit_test(INT a->lst->next->content == 11, "");
	unit_test(INT a->lst->next->next->content == 13, "");

	unit_test(INT b->lst->content == 22, "");
	unit_test(INT b->lst->next->content == 21, "");
	unit_test(INT b->lst->next->next->content == 23, "");

	free(ret);
	stackclear(&a);
	stackclear(&b);

	return (OK);
}
