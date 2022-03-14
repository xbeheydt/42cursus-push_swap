/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:20:00 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 10:46:33 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*current;

	current = (*alst);
	while (current != NULL && current->next != NULL)
		current = current->next;
	if ((*alst) == NULL)
		(*alst) = new;
	else
		current->next = new;
}
