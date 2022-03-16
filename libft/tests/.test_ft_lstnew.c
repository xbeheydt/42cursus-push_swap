/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_lstnew.c                                  :+:      :+:    :+:   */
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

int	test_ft_lstnew(void *args)
{
	(void)args;
	t_list	*lst;
	char	*content = "Ipsum";

	lst = NULL;
	lst = ft_lstnew(content);
	unit_test(lst != NULL, "lst != NULL");
	unit_test(lst->next == NULL, "lst-> == NULL");
	unit_test(strcmp((char *)lst->content, "Ipsum") == 0, "lst->content == 'Ipsum'");
	free(lst);
	return (OK);
}
