/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_lstdelone.c                               :+:      :+:    :+:   */
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
	unit_test(*((int *)i) == 42, "del using in ft_lst_clear");
}

int	test_ft_lstdelone(void *args)
{
	(void)args;
	t_list	*lst;
	int	a, b;

	a = 42;
	b = 42;
	lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew(&a));
	ft_lstadd_front(&lst, ft_lstnew(&b));
	ft_lstdelone(lst->next, del);
	unit_test(lst->next != NULL, "lst->next is cleared but not address");
	ft_lstdelone(lst, del);
	unit_test(lst != NULL, "lst is cleared but not address");
	return (OK);
}
