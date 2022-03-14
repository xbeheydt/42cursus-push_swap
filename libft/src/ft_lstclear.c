/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:53:06 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 11:28:26 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if ((*lst) == NULL)
		return ;
	ft_lstclear(&((*lst)->next), del);
	if ((*lst)->content)
		del((*lst)->content);
	free((*lst));
	(*lst) = NULL;
}
