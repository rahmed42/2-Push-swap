/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:59:01 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/31 01:40:07 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_write_order_stack(t_stack *stack)
{
	int	i;

	stack->tmp = stack->a;
	while (stack->tmp != NULL)
	{
		i = 0;
		while (i < stack->stack_len)
		{
			if (ft_atoi(stack->tmp->content) == stack->sorted[i])
			{
				stack->tmp->content = ft_itoa(i);
				break ;
			}
			i++;
		}
		stack->tmp = stack->tmp->next;
	}
	free(stack->sorted);
}

void	sort_tab(t_stack *stack)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (i < stack->stack_len)
	{
		j = 0;
		while (j < i)
		{
			nb = stack->sorted[i];
			if (stack->sorted[j] > stack->sorted[i])
			{
				stack->sorted[i] = stack->sorted[j];
				stack->sorted[j] = nb;
			}
			j++;
		}
		i++;
	}
	stack->stack_val_mid = (i - 1) / 2;
}

void	ft_sort_push_a(t_stack *stack, int sort)
{
	int	val_b;

	val_b = ft_atoi(stack->b->content);
	if ((val_b > stack->stack_val_mid) || sort == 0)
	{
		if ((val_b > stack->max_a) && stack->len_a > 0)
		{
			ft_push_pa(stack);
			ft_rotate_ra(stack, RA);
		}
		else
			ft_push_pa(stack);
	}
	else
		ft_rotate_rb(stack, RB);
}

void	ft_sort_push_b(t_stack *stack, int sort)
{
	int	val_a;

	val_a = ft_atoi(stack->a->content);
	if ((val_a < stack->stack_val_mid) || sort == 0)
	{
		if ((val_a < stack->min_b) && stack->len_b > 0)
		{
			ft_push_pb(stack);
			ft_rotate_rb(stack, RB);
		}
		else
			ft_push_pb(stack);
	}
	else
		ft_rotate_ra(stack, RA);
}
