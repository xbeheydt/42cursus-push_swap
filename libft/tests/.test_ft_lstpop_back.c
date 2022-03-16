/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_lstpop_back.c                             :+:      :+:    :+:   */
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

int	test_ft_lstpop_back(void *args)
{
	(void)args;
	t_list	*lst = NULL;
	t_list	*ret = NULL;
	int		a = 1, b = 2, c = 3;

	ret = ft_lstpop_back(&lst);
	unit_test(ret == NULL, "pop in empty list");
	
	ft_lstadd_back(&lst, ft_lstnew(&a));
	ret = ft_lstpop_back(&lst);
	unit_test(ret->content == &a, "pop alone node in lst");
	unit_test(lst == NULL, "pop alone node in lst");
	ft_lstclear(&ret, del);

	ft_lstadd_back(&lst, ft_lstnew(&a));
	ft_lstadd_back(&lst, ft_lstnew(&b));
	ft_lstadd_back(&lst, ft_lstnew(&c));
	ret = ft_lstpop_back(&lst);
	unit_test(ret->content == &c, "pop last node");
	unit_test(lst->content == &a, "pop last node");
	unit_test(lst->next->content == &b, "pop last node");
	ft_lstclear(&ret, del);
	ft_lstclear(&lst, del);
	return (OK);
}
