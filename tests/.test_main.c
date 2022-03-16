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
int	test_stnew(void *);
int	test_stclear(void *);
int	test_stadd_back(void *);
int	test_stadd_front(void *);
int	test_stpop_back(void *);
int	test_stpop_front(void *);
int	test_stswap(void *);
int	test_strot(void *);
int	test_strevrot(void *);
int	test_stpush(void *);
int	test_stissorted(void *);
int	test_stfindi(void *);
int	test_argparser(void *);
int	test_push(void *);
int	test_ra(void *);
int	test_rb(void *);
int	test_rr(void *);
int	test_rra(void *);
int	test_rrb(void *);
int	test_rrr(void *);
int	test_sa(void *);
int	test_sb(void *);
int	test_ss(void *);

static unit_t	tests[] = {
	/* stack.c */
	{ TEST_FCN(test_stnew), NULL, NULL, RUN },
	{ TEST_FCN(test_stclear), NULL, NULL, RUN },
	{ TEST_FCN(test_stadd_back), NULL, NULL, RUN },
	{ TEST_FCN(test_stadd_front), NULL, NULL, RUN },
	{ TEST_FCN(test_stpop_back), NULL, NULL, RUN },
	{ TEST_FCN(test_stpop_front), NULL, NULL, RUN },
	{ TEST_FCN(test_stswap), NULL, NULL, RUN },
	{ TEST_FCN(test_strot), NULL, NULL, RUN },
	{ TEST_FCN(test_strevrot), NULL, NULL, RUN },
	{ TEST_FCN(test_stpush), NULL, NULL, RUN },
	{ TEST_FCN(test_stissorted), NULL, NULL, RUN },
	/* argparser.c */
	{ TEST_FCN(test_argparser), NULL, NULL, RUN },
	/* push.c */
	{ TEST_FCN(test_push), NULL, NULL, RUN },
	/* rotate.c */
	{ TEST_FCN(test_ra), NULL, NULL, RUN },
	{ TEST_FCN(test_rb), NULL, NULL, RUN },
	{ TEST_FCN(test_rr), NULL, NULL, RUN },
	/* rev_rotate.c */
	{ TEST_FCN(test_rra), NULL, NULL, RUN },
	{ TEST_FCN(test_rrb), NULL, NULL, RUN },
	{ TEST_FCN(test_rrr), NULL, NULL, RUN },
	/* swap.c */
	{ TEST_FCN(test_sa), NULL, NULL, RUN },
	{ TEST_FCN(test_sb), NULL, NULL, RUN },
	{ TEST_FCN(test_ss), NULL, NULL, RUN },
	TEST_END
};

int	main(int argc, const char *argv[])
{
	return (__main(argc, argv, tests));
}
