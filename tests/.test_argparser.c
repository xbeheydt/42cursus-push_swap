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

static const char	*argv4[] = {
	"",
	"12",
	"-23",
	"42",
	"-23",
	NULL
};

static const char	*argv5[] = {
	"",
	"12",
	"43598435904353425234645734568768435968453",
	"42",
	"-23",
	NULL
};
static const char	*argv6[] = {
	"",
	"12",
	"2147483648",
	"42",
	"-23",
	NULL
};

int	test_argparser(void *args)
{
	(void)args;

	t_stack	*s = NULL;

	unit_test(argparser(&s, argv1) == 3, "");
	unit_test(s->val == 12, "");
	unit_test(s->next->val == 42, "");
	unit_test(s->next->next->val == -23, "");
	stclear(&s);

	unit_test(argparser(&s, argv2) == 3, "");
	unit_test(s->val == 12, "");
	unit_test(s->next->val == 42, "");
	unit_test(s->next->next->val == -23, "");
	stclear(&s);

	unit_test(argparser(&s, argv3) == 0, "");
	stclear(&s);

	unit_test(argparser(&s, argv4) == 0, "");
	stclear(&s);

	unit_test(argparser(&s, argv5) == 0, "");
	stclear(&s);

	unit_test(argparser(&s, argv6) == 0, "");
	stclear(&s);
	return (OK);
}
