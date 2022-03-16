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
#include <limits.h>

#define MINUS	'-'
#define PLUS	'+'

/* Private functions */

/* Public API */

int	argparser(t_stack **s, const char *argv[])
{
	int		i;
	long	content;

	i = 1;
	while (argv[i] != NULL)
	{
		if (!(ft_isdigit(*argv[i]) || ft_isspace(*argv[i])
				|| *argv[i] == MINUS || *argv[i] == PLUS))
			return (0);
		if (ft_strlen(argv[i]) >= 12)
			return (0);
		content = ft_atol(argv[i]);
		if (content < INT_MIN || content > INT_MAX || stfindi((*s), (int)content))
			return (0);
		stadd_back(s, stnew((int)content));
		while (ft_isdigit(*argv[i]) || *argv[i] == MINUS || *argv[i] == PLUS)
			argv[i]++;
		if (ft_isspace(*argv[i]))
			argv[i]++;
		if (*argv[i] == '\0')
			++i;
	}
	return (1);
}
