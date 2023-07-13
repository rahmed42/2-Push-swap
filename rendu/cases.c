/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:47:37 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/31 14:56:39 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3_a_stack(t_stack *stack)
{
	stack->val1 = ft_atoi(stack->a->content);
	stack->val2 = ft_atoi(stack->a->next->content);
	stack->val3 = ft_atoi(stack->a->next->next->content);
	if (stack->val1 > stack->val2)
	{
		if ((stack->val2 < stack->val3) && (stack->val3 > stack->val1))
			ft_swap_sa(stack, SA);
		else if ((stack->val2 > stack->val3) && (stack->val3 < stack->val1))
		{
			ft_swap_sa(stack, SA);
			ft_reverse_rotate_rra(stack, RRA);
		}
		else if ((stack->val2 < stack->val3) && (stack->val3 < stack->val1))
			ft_rotate_ra(stack, RA);
	}
	else if (stack->val2 > stack->val3)
	{
		if (stack->val3 > stack->val1)
		{
			ft_swap_sa(stack, SA);
			ft_rotate_ra(stack, RA);
		}
		else
			ft_reverse_rotate_rra(stack, RRA);
	}
}

void	ft_case_sort_3(t_stack *stack)
{
	if (stack->len_a == 3)
		ft_sort_3_a_stack(stack);
	else if (stack->len_a == 2)
		ft_swap_sa(stack, SA);
}

void	ft_case_sort_5(t_stack *stack)
{
	while (stack->len_a > 3)
		ft_sort_push_b(stack, 1);
	ft_sort_3_a_stack(stack);
	if (ft_stack_b_sorted(stack) == 0)
		ft_swap_sb(stack, SB);
	while (stack->len_b > 0)
		ft_sort_push_a(stack, 0);
}

void	ft_case_sort_radix(t_stack *stack)
{
	int	nbit;
	int	istack;
	int	max_bits;

	nbit = 0;
	max_bits = 0;
	while ((stack->stack_len >> max_bits) != 0)
		++max_bits;
	while (nbit < max_bits)
	{
		istack = 0;
		while (istack < stack->stack_len)
		{
			if (((ft_atoi(stack->a->content) >> nbit) & 1) == 1)
				ft_rotate_ra(stack, RA);
			else
				ft_push_pb(stack);
			++istack;
		}
		while (stack->len_b > 0)
			ft_push_pa(stack);
		++nbit;
	}
}
