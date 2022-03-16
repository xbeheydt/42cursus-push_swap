/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_lstlast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:36:44 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/04 13:18:44 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <libft.h>
#include <stdlib.h>

static void	del(void *i)
{
	(void)i;
}

int	test_ft_lstlast(void *args)
{
	(void)args;
	t_list	*lst, *last;
	int	a, b, c;

	a = 1;
	b = 2;
	c = 42;
	lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew(&a));
	ft_lstadd_front(&lst, ft_lstnew(&b));
	ft_lstadd_back(&lst, ft_lstnew(&c));
	last = ft_lstlast(lst);
	unit_test(*((int *)last->content) == 42, "last is 42");
	ft_lstclear(&lst, del);
	return (OK);
}
