/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:05:43 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/03/09 11:48:48 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>

/* define unit test functions HERE */
/* push_swap */
int	test_stacknew(void *);
int	test_stackadd_back(void *);
int	test_stackadd_front(void *);
int	test_stackclear(void *);
int	test_stack_rotate(void *);
int	test_stack_rev_rotate(void *);
int	test_stack_push(void *);
int	test_stack_swap(void *);
int	test_stack_issorted(void *);
int	test_argparser(void *);

static unit_t	tests[] = {
	/* stack.c */
	{ TEST_FCN(test_stacknew), NULL, NULL, RUN },
	{ TEST_FCN(test_stackadd_back), NULL, NULL, RUN },
	{ TEST_FCN(test_stackadd_front), NULL, NULL, RUN },
	{ TEST_FCN(test_stackclear), NULL, NULL, RUN },
	/* stack_operations.c */
	{ TEST_FCN(test_stack_rotate), NULL, NULL, RUN },
	{ TEST_FCN(test_stack_rev_rotate), NULL, NULL, RUN },
	{ TEST_FCN(test_stack_push), NULL, NULL, RUN },
	{ TEST_FCN(test_stack_swap), NULL, NULL, RUN },
	{ TEST_FCN(test_stack_issorted), NULL, NULL, RUN },
	/* argparser.c */
	{ TEST_FCN(test_argparser), NULL, NULL, RUN },
	TEST_END
};

int	main(int argc, const char *argv[])
{
	return (__main(argc, argv, tests));
}
