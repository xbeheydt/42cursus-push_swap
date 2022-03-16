/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:06:01 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 08:57:31 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stddef.h>

typedef struct s_st
{
	int			val;
	struct s_st	*next;
}	t_stack;

/* stack{,2,3} - stack handlers */
t_stack	*stnew(int val);
void	stadd_back(t_stack **s, t_stack *n);
void	stadd_front(t_stack **s, t_stack *n);
t_stack	*stpop_back(t_stack **s);
t_stack	*stpop_front(t_stack **s);
void	stclear(t_stack **s);
void	stswap(t_stack **a, t_stack **b);
void	strot(t_stack **s);
void	strevrot(t_stack **s);
void	stpush(t_stack **a, t_stack **b);
int		stissorted(t_stack *s, int way);
int		stfindi(t_stack *s, int i);

/* argparser.c - handling arguments */
int		argparser(t_stack **s, const char *argv[]);

/* push.c - pushes frontend */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/* swap.c - swaps frontend */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/* rotate.c - rotates frontend */
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/* rev_rotate.c - rev rotates frontend */
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif /* PUSH_SWAP_H */
