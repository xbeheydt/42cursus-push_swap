/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_lstadd_front.c                            :+:      :+:    :+:   */
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

int	test_ft_lstadd_front(void *args)
{
	(void)args;
	t_list	*lst;
	int	a, b;

	a = 1;
	b = 2;
	lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew(&a));
	ft_lstadd_front(&lst, ft_lstnew(&b));
	unit_test(*((int *)lst->content) == 2, "lst->content == 1");
	unit_test(*((int *)lst->next->content) == 1, "lst->content == 2");
	free(lst->next);
	free(lst);
	return (OK);
}
