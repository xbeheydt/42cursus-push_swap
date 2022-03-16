/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_lstiter.c                                 :+:      :+:    :+:   */
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

static void	f(void *i)
{
	unit_test(*((int *)i) == 42, "f using in ft_lstiter");
}

int	test_ft_lstiter(void *args)
{
	(void)args;
	t_list	*lst;
	int	a, b;

	a = 42;
	b = 42;
	lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew(&a));
	ft_lstadd_front(&lst, ft_lstnew(&b));
	ft_lstiter(lst, f);
	ft_lstclear(&lst, f);
	return (OK);
}
