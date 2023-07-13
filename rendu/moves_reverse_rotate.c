/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:03:26 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/31 01:39:29 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_rra(t_stack *stack, size_t order)
{
	if (stack->len_a > 1)
	{
		stack->tmp = stack->a;
		while (stack->tmp->next->next != NULL)
			stack->tmp = stack->tmp->next;
		ft_lstadd_front(&stack->a, stack->tmp->next);
		stack->tmp->next = NULL;
		if (order == RRA)
			ft_putstr_fd("rra\n", 1);
	}
}

void	ft_reverse_rotate_rrb(t_stack *stack, size_t order)
{
	if (stack->len_b > 1)
	{
		stack->tmp = stack->b;
		while (stack->tmp->next->next != NULL)
			stack->tmp = stack->tmp->next;
		ft_lstadd_front(&stack->b, stack->tmp->next);
		stack->tmp->next = NULL;
		if (order == RRB)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	ft_reverse_rotate_rrr(t_stack *stack, size_t order)
{
	if ((stack->len_a > 1) && (stack->len_b > 1))
		ft_putstr_fd("rrr\n", 1);
	else if ((stack->len_a == 0) && (stack->len_b > 1))
		order = RRB;
	else if ((stack->len_a > 1) && (stack->len_b == 0))
		order = RRA;
	ft_reverse_rotate_rra(stack, order);
	ft_reverse_rotate_rrb(stack, order);
}
