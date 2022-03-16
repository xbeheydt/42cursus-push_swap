/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_gnl_line_realloc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:33:55 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:33:58 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <get_next_line.h>
#include <libft.h>
#include <stdlib.h>

int	test_gnl_line_realloc(void *args)
{
	(void)args;
    t_buffer	*buf;

	buf = NULL;
	get_buffer(&buf);
    line_realloc(&buf, 6);
    ft_memcpy(buf->line, "Hello", 5);
	buf->llen = 5;
    unit_test(ft_memcmp(buf->line, "Hello", buf->llen) == 0, "");

    line_realloc(&buf, 12);
    ft_memcpy(buf->line + 5, " World", 6);
	buf->llen = 11;
    unit_test(ft_memcmp(buf->line, "Hello World", buf->llen) ==  0, "");

    line_realloc(&buf, 22);
    ft_memcpy(buf->line + 11, "IpsumLorem", 10);
	buf->llen = 21;
    unit_test(ft_memcmp(buf->line, "Hello WorldIpsumLorem", buf->llen) ==  0, "");

	clear_buffer(&buf);
    return (OK);
}
