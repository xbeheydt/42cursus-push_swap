/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_lstmap.c                                  :+:      :+:    :+:   */
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

static void	*f(void *i)
{
	int	*val;
	val = NULL;
	if (i)
	{
		val = malloc(sizeof(int));
		if (val)

		*(int *)val = *(int *)i + 1;
	}
	return (val);
}

static void	del(void *i)
{
	if (i)
		free(i);
	i = NULL;
}

int	test_ft_lstmap(void *args)
{
	(void)args;
	t_list	*lst, *map;

	lst = NULL, map = NULL;
	int *a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	if (a && b)
	{
		*a = 1;
		*b = 42;
		ft_lstadd_back(&lst, ft_lstnew(a));
		ft_lstadd_back(&lst, ft_lstnew(NULL));
		ft_lstadd_back(&lst, ft_lstnew(b));
		ft_lstadd_back(&lst, ft_lstnew(NULL));
		map = ft_lstmap(lst, f, del);
		unit_test(lst->content == NULL, "first node content cleared");
		unit_test(lst->next->content == NULL, "second node content cleared");
		unit_test(lst->next->next->content == NULL, "third node content cleared");
		unit_test(lst->next->next->next->content == NULL, "fourth node content cleared");

		unit_test(*((int *)map->content) == 2, "first node content == 2");
		unit_test(map->next->content == NULL, "second node content is NULL");
		unit_test(*((int *)map->next->next->content) == 43, "third node content == 43");
		unit_test(map->next->next->next->content == NULL, "fourth node content is NULL");

		ft_lstclear(&lst, del);
		ft_lstclear(&map, del);
	}
	return (OK);
}
