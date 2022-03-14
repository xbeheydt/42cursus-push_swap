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

typedef struct s_stack
{
	t_list	*lst;
	t_list	*last;
	int		size;
}	t_stack;

/* stack.c - stack handlers */
t_stack	*stacknew(void);
void	stackadd_back(t_stack **s, int *val);
void	stackadd_front(t_stack **s, int *val);
void	stackclear(t_stack **s);

/* stack_operations.c - push, rotate, rev_rot and swap vals on stacks */
void	stack_rotate(t_stack **s);
void	stack_rev_rotate(t_stack **s);
void	stack_push(t_stack **a, t_stack **b);
void	stack_swap(t_stack **s);
int		stack_issorted(t_stack *s, int dir);

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
