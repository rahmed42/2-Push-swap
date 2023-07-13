/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:02:03 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/31 01:39:32 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_ra(t_stack *stack, size_t order)
{
	if (stack->len_a > 1)
	{
		stack->tmp = stack->a;
		stack->a = stack->a->next;
		stack->tmp->next = NULL;
		ft_lstadd_back(&stack->a, stack->tmp);
		if (order == RA)
			ft_putstr_fd("ra\n", 1);
	}
}

void	ft_rotate_rb(t_stack *stack, size_t order)
{
	if (stack->len_b > 1)
	{
		stack->tmp = stack->b;
		stack->b = stack->b->next;
		stack->tmp->next = NULL;
		ft_lstadd_back(&stack->b, stack->tmp);
		if (order == RB)
			ft_putstr_fd("rb\n", 1);
	}
}

void	ft_rotate_rr(t_stack *stack, size_t order)
{
	if ((stack->len_a > 1) && (stack->len_b > 1))
		ft_putstr_fd("rr\n", 1);
	else if ((stack->len_a == 0) && (stack->len_b > 1))
		order = RB;
	else if ((stack->len_a > 1) && (stack->len_b == 0))
		order = RA;
	ft_rotate_ra(stack, order);
	ft_rotate_rb(stack, order);
}
