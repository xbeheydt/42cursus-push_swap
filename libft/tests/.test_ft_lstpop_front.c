/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_lstpop_front.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:05:43 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/03/09 11:48:48 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <stdlib.h>
#include <libft.h>

static void	del(void *i)
{
	(void)i;
}

int	test_ft_lstpop_front(void *args)
{
	(void)args;
	t_list	*lst = NULL;
	t_list	*ret = NULL;
	int		a = 1, b = 2, c = 3;

	ret = ft_lstpop_front(&lst);
	unit_test(ret == NULL, "pop in empty list");
	
	ft_lstadd_back(&lst, ft_lstnew(&a));
	ret = ft_lstpop_front(&lst);
	unit_test(ret->content == &a, "pop alone node in lst");
	unit_test(lst == NULL, "pop alone node in lst");
	ft_lstclear(&ret, del);

	ft_lstadd_back(&lst, ft_lstnew(&a));
	ft_lstadd_back(&lst, ft_lstnew(&b));
	ft_lstadd_back(&lst, ft_lstnew(&c));
	ret = ft_lstpop_front(&lst);
	unit_test(ret->content == &a, "pop first node");
	unit_test(lst->content == &b, "pop first node");
	unit_test(lst->next->content == &c, "pop first node");
	ft_lstclear(&ret, del);
	ft_lstclear(&lst, del);
	return (OK);
}
