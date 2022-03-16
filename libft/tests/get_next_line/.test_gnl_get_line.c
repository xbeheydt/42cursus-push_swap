/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_gnl_get_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:05:43 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/03/09 11:48:48 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>
#include <get_next_line.h>
#include <string.h>
#include <stdlib.h>

static int	__read(t_buffer **buf, const char *s, size_t *offset, size_t bufsize)
{
	if ((*offset) >= strlen(s))
		return (0);
	(*buf)->flen = strlen(s + (*offset));
	if ((*buf)->flen < (int)bufsize)
		memcpy((*buf)->file, s + (*offset), (*buf)->flen);
	else
	{
		memcpy((*buf)->file, s + (*offset), bufsize);
		(*buf)->flen = bufsize;
	}
	(*buf)->fpos = 0;
	(*offset) += bufsize;
	return ((*buf)->flen);
}

static int	test_get_line(char *s, char *lines[], int nbline)
{
	t_buffer	*buf;
	int			i;
	size_t		offset;

	buf = NULL;
	i = 0;
	offset = 0;
	get_buffer(&buf);
	while (i < nbline)
	{
		if (buf->fpos == 0 && __read(&buf, s, &offset, BUFFER_SIZE) == 0)
		{
			unit_test(strcmp(buf->line, lines[i]) == 0, "");
			++i;
		}
		else if (get_line(&buf, BUFFER_SIZE) != GNL_NOLI)
		{
			unit_test(strcmp(buf->line, lines[i]) == 0, "");
			++i;
			get_buffer(&buf);
		}
	}
	clear_buffer(&buf);
	return (OK);
}

int	test_gnl_get_line1(void *args)
{
	(void)args;
	char		*s = "Ipsum\nLorem\n\nHello\nWorld";
	char		*lines[] = {
		"Ipsum\n",
		"Lorem\n",
		"\n",
		"Hello\n",
		"World"
	};
	int	nbline = 5;

	return (test_get_line(s, lines, nbline));
}

int	test_gnl_get_line2(void *args)
{
	(void)args;
	char		*s = "\nLorem\n\nHello\nWorld";
	char		*lines[] = {
		"\n",
		"Lorem\n",
		"\n",
		"Hello\n",
		"World"
	};
	int	nbline = 5;

	return (test_get_line(s, lines, nbline));
}

int	test_gnl_get_line3(void *args)
{
	(void)args;
	char		*s = "Ipsum Lorem";
	char		*lines[] = {
		"Ipsum Lorem",
	};
	int	nbline = 1;

	return (test_get_line(s, lines, nbline));
}

