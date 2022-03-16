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
