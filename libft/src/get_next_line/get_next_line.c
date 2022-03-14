/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 08:38:19 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:29:35 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <stdlib.h>
#include <unistd.h>

void	get_buffer(t_buffer **buf)
{
	if ((*buf) == NULL)
	{
		(*buf) = (t_buffer *)malloc(sizeof(t_buffer));
		if ((*buf))
		{
			(*buf)->fpos = 0;
			(*buf)->flen = 0;
		}
		else
			return ;
	}
	(*buf)->llen = 0;
	(*buf)->line = NULL;
}

void	*clear_buffer(t_buffer **buf)
{
	if ((*buf))
	{
		if ((*buf)->line)
			free((*buf)->line);
		free((*buf));
		(*buf) = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_buffer	*buf;

	get_buffer(&buf);
	while (fd >= 0 && BUFFER_SIZE > 0)
	{
		if (buf->fpos == 0)
			buf->flen = read(fd, buf->file, BUFFER_SIZE);
		if (buf->flen > 0)
		{
			if (get_line(&buf, BUFFER_SIZE) != GNL_NOLI)
			{
				if (buf->llen)
					return (buf->line);
				else
					return (clear_buffer(&buf));
			}
		}
		else if (buf->flen == 0 && buf->llen)
			return (buf->line);
		else
			break ;
	}
	return (clear_buffer(&buf));
}
