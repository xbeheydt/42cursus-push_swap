/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_gnl_get_buffer.c                             :+:      :+:    :+:   */
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

int	test_gnl_get_buffer(void *args)
{
	(void)args;
	t_buffer	*buff = NULL;

	get_buffer(&buff);
	unit_test(buff->fpos == 0, "");
	unit_test(buff->flen == 0, "");
	unit_test(buff->line == NULL, "");
	unit_test(buff->llen == 0, "");
	free(buff);
	return (OK);
}
