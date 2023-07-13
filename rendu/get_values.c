/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:03:49 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/31 01:39:19 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_ordered_stack(t_stack *stack)
{
	int	i;

	i = 0;
	stack->sorted = ft_calloc(stack->stack_len, sizeof(int));
	stack->tmp = stack->a;
	while (stack->tmp != NULL)
	{
		stack->sorted[i] = ft_atoi(stack->tmp->content);
		stack->tmp = stack->tmp->next;
		i++;
	}
	sort_tab(stack);
}

void	ft_get_values(t_stack *stack)
{
	ft_get_a_values(stack);
	ft_get_b_values(stack);
}

void	ft_get_a_values(t_stack *stack)
{
	if (stack->len_a)
	{
		stack->tmp = stack->a;
		stack->min_a = ft_atoi(stack->tmp->content);
		stack->max_a = stack->min_a;
		while (stack->tmp != NULL)
		{
			if (ft_atoi(stack->tmp->content) > stack->max_a)
				stack->max_a = ft_atoi(stack->tmp->content);
			if (ft_atoi(stack->tmp->content) < stack->min_a)
				stack->min_a = ft_atoi(stack->tmp->content);
			stack->tmp = stack->tmp->next;
		}
	}
}

void	ft_get_b_values(t_stack *stack)
{
	if (stack->len_b)
	{
		stack->tmp = stack->b;
		stack->min_b = ft_atoi(stack->tmp->content);
		stack->max_b = stack->min_b;
		while (stack->tmp != NULL)
		{
			if (ft_atoi(stack->tmp->content) > stack->max_b)
				stack->max_b = ft_atoi(stack->tmp->content);
			if (ft_atoi(stack->tmp->content) < stack->min_b)
				stack->min_b = ft_atoi(stack->tmp->content);
			stack->tmp = stack->tmp->next;
		}
	}
}
