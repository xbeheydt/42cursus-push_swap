/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 08:57:31 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <stdlib.h>

#define MINUS	'-'
#define PLUS	'+'

/* Private functions */

static int	*lstadd_content(int i)
{
	int	*val;

	val = NULL;
	val = malloc(sizeof(int));
	if (val)
	{
		*val = i;
	}
	return (val);
}

/* Public API */

int	argparser(t_stack **s, const char *argv[])
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (!(ft_isdigit(*argv[i]) || ft_isspace(*argv[i])
				|| *argv[i] == MINUS || *argv[i] == PLUS))
			return (0);
		stackadd_back(s, lstadd_content(ft_atoi(argv[i])));
		while (ft_isdigit(*argv[i]) || *argv[i] == MINUS || *argv[i] == PLUS)
			argv[i]++;
		if (ft_isspace(*argv[i]))
			argv[i]++;
		if (*argv[i] == '\0')
			++i;
	}
	return (1);
}
