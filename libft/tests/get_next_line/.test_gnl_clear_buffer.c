/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_gnl_clear_buffer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:05:43 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/03/09 11:48:48 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <get_next_line.h>
#include <stdlib.h>

int	test_gnl_clear_buffer(void *args)
{
	(void)args;
	t_buffer	*buff = NULL;

	get_buffer(&buff);
	buff->line = malloc(10);
	clear_buffer(&buff);
	unit_test(buff == NULL, "");
	return (OK);
}
