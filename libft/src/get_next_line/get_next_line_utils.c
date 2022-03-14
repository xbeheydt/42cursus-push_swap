/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 08:38:20 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:36:35 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <stdlib.h>

void	line_realloc(t_buffer **buf, size_t nsize)
{
	char	*nline;

	nline = NULL;
	nline = malloc(nsize * sizeof (char));
	if (nline == NULL)
		return ;
	if ((*buf)->line)
	{
		ft_memmove(nline, (*buf)->line, (*buf)->llen);
		free((*buf)->line);
		(*buf)->line = NULL;
	}
	(*buf)->line = nline;
}

int	get_line(t_buffer **buf, size_t bufsize)
{
	int	ret;
	int	pos;

	ret = GNL_NOLI;
	pos = (*buf)->fpos;
	while (ret == GNL_NOLI && pos < (int)bufsize && pos < (*buf)->flen)
	{
		ret = ((*buf)->file[pos] == '\n');
		++pos;
	}
	if ((*buf)->flen < (int)bufsize && ret != GNL_NEWL)
	{
		pos = (*buf)->flen;
		ret = GNL_ENDL;
	}
	line_realloc(buf, (*buf)->llen + pos - (*buf)->fpos + 1);
	ft_memmove((*buf)->line + (*buf)->llen,
		(*buf)->file + (*buf)->fpos, pos - (*buf)->fpos);
	(*buf)->llen += pos - (*buf)->fpos;
	(*buf)->line[(*buf)->llen] = '\0';
	if (pos < (int)bufsize)
		(*buf)->fpos = pos;
	else
		(*buf)->fpos = 0;
	return (ret);
}
