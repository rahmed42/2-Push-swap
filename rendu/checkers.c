/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:36:36 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/31 01:39:17 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_stack_a(char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	while (argv[i])
		ft_lstadd_back(&stack->a, ft_lstnew(argv[i++]));
	ft_get_values(stack);
}

int	ft_stack_a_sorted(t_stack *stack)
{
	t_list	*tmpa;

	if ((stack->a == NULL) || (stack->len_a == 0))
		return (1);
	tmpa = stack->a;
	while (tmpa->next)
	{
		if (ft_atoi(tmpa->content) > ft_atoi(tmpa->next->content))
			return (0);
		tmpa = tmpa->next;
	}
	return (1);
}

int	ft_stack_b_sorted(t_stack *stack)
{
	t_list	*tmpb;

	if ((stack->b == NULL) || (stack->len_b == 0))
		return (1);
	tmpb = stack->b;
	while (tmpb->next)
	{
		if (ft_atoi(tmpb->content) < ft_atoi(tmpb->next->content))
			return (0);
		tmpb = tmpb->next;
	}
	return (1);
}

int	ft_check_numb(char **argv)
{
	int			i;
	int			j;
	long long	num;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((j == 0 && argv[i][j] == '-' && argv[i][j + 1]) \
			|| ft_isdigit(argv[i][j]))
				j++;
			else
				return (0);
		}
		num = ft_atoll(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
