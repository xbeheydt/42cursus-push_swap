/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:33:35 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 12:05:49 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*node;

	node = NULL;
	if (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		del(lst->content);
		lst->content = NULL;
		node->next = ft_lstmap(lst->next, f, del);
	}
	return (node);
}
