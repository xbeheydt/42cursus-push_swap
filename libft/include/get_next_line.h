/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 08:38:17 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/01/24 15:29:09 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>

# define GNL_NOLI 0
# define GNL_ENDL -1
# define GNL_NEWL 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif /* BUFFER_SIZE */

typedef struct s_buffer
{
	char	file[BUFFER_SIZE];
	int		fpos;
	int		flen;
	char	*line;
	size_t	llen;
}	t_buffer;

/* Buffer handlers */
void		get_buffer(t_buffer **buf);
void		*clear_buffer(t_buffer **buf);

/* Feature functions */
void		line_realloc(t_buffer **buf, size_t asize);

/* Core functions */
char		*get_next_line(int fd);
int			get_line(t_buffer **buf, size_t bufsize);

#endif /* GET_NEXT_LINE_H */
