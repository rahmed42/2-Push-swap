/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:00:34 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/31 01:39:28 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_sa(t_stack *stack, size_t order)
{
	if (stack->len_a > 1)
	{
		stack->tmp = stack->a;
		stack->a = stack->a->next;
		stack->tmp->next = stack->a->next;
		stack->a->next = stack->tmp;
		if (order == SA)
			ft_putstr_fd("sa\n", 1);
	}
}

void	ft_swap_sb(t_stack *stack, size_t order)
{
	if (stack->len_b > 1)
	{
		stack->tmp = stack->b;
		stack->b = stack->b->next;
		stack->tmp->next = stack->b->next;
		stack->b->next = stack->tmp;
		if (order == SB)
			ft_putstr_fd("sb\n", 1);
	}
}

void	ft_swap_ss(t_stack *stack, size_t order)
{
	if ((stack->len_a > 1) && (stack->len_b > 1))
		ft_putstr_fd("ss\n", 1);
	else if ((stack->len_a == 0) && (stack->len_b > 1))
		order = SB;
	else if ((stack->len_a > 1) && (stack->len_b == 0))
		order = SA;
	ft_swap_sa(stack, order);
	ft_swap_sb(stack, order);
}

void	ft_push_pa(t_stack *stack)
{
	if (stack->len_b > 0)
	{
		stack->tmp = stack->b;
		stack->b = stack->b->next;
		stack->tmp->next = stack->a;
		stack->a = stack->tmp;
		stack->len_a++;
		stack->len_b--;
		ft_get_values(stack);
		ft_putstr_fd("pa\n", 1);
	}
}

void	ft_push_pb(t_stack *stack)
{
	if (stack->len_a > 0)
	{
		stack->tmp = stack->a;
		stack->a = stack->a->next;
		stack->tmp->next = stack->b;
		stack->b = stack->tmp;
		stack->len_b++;
		stack->len_a--;
		ft_get_values(stack);
		ft_putstr_fd("pb\n", 1);
	}
}
