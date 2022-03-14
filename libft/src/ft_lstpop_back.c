/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 08:57:31 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstpop_back(t_list **lst)
{
	t_list	*last;
	t_list	*cur;

	cur = (*lst);
	if ((*lst) == NULL)
		return (NULL);
	while (cur && cur->next && cur->next->next)
		cur = cur->next;
	if ((*lst)->next == NULL)
	{
		last = (*lst);
		(*lst) = NULL;
	}
	if ((*lst))
	{
		last = cur->next;
		cur->next = NULL;
	}
	return (last);
}
