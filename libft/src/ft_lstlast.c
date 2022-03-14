/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:16:36 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 10:23:51 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}
