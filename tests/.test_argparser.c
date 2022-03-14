/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_argperser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:05:43 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/03/09 11:48:48 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <push_swap.h>

static const char	*argv1[] = {
	"",
	"12",
	"42",
	"-23",
	NULL
};

static const char	*argv2[] = {
	"",
	"12 42",
	"-23",
	NULL
};

static const char	*argv3[] = {
	"",
	"12",
	"4t2",
	"-23",
	NULL
};

#define INT	*(int *)

int	test_argparser(void *args)
{
	(void)args;

	t_stack	*s;

	s = stacknew();
	unit_test(argparser(&s, argv1) == 1, "");
	unit_test(INT s->lst->content == 12, "");
	unit_test(INT s->lst->next->content == 42, "");
	unit_test(INT s->lst->next->next->content == -23, "");
	unit_test(s->size == 3, "");
	stackclear(&s);

	s = stacknew();
	unit_test(argparser(&s, argv2) == 1, "");
	unit_test(INT s->lst->content == 12, "");
	unit_test(INT s->lst->next->content == 42, "");
	unit_test(INT s->lst->next->next->content == -23, "");
	unit_test(s->size == 3, "");
	stackclear(&s);

	s = stacknew();
	unit_test(argparser(&s, argv3) == 0, "");
	stackclear(&s);

	return (OK);
}
