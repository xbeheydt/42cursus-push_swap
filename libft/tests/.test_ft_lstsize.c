/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_lstsize.c                                 :+:      :+:    :+:   */
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
#include <string.h>

static void	del(void *content)
{
	(void)content;
}

int	test_ft_lstsize(void *args)
{
	(void)args;
	t_list	*lst;
	int		i;

	lst = NULL;
	i = 0;
	while (i++ < 10)
		ft_lstadd_back(&lst, ft_lstnew(NULL));
	unit_test(ft_lstsize(lst) == 10, "lst size == 10");
	ft_lstclear(&lst, del);
	return (OK);
}
