/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 08:57:31 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstpop_front(t_list **lst)
{
	t_list	*front;

	front = (*lst);
	if ((*lst))
	{
		(*lst) = (*lst)->next;
		front->next = NULL;
	}
	else
		(*lst) = NULL;
	return (front);
}
