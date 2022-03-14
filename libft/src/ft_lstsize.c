/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:08:47 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 10:14:11 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 1;
	if (lst == NULL)
		return (0);
	while (lst && lst->next && ++size)
		lst = lst->next;
	return (size);
}
