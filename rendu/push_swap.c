/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:08:28 by rahmed            #+#    #+#             */
/*   Updated: 2022/01/04 16:29:05 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**my_arg;

	if (argc > 1)
	{
		stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
		if (stack == NULL)
			return (0);
		my_arg = &argv[1];
		if (argc == 2)
			my_arg = ft_split(argv[1], ' ');
		ft_push_swap(my_arg, stack);
		if (argc == 2)
			ft_free_tab(my_arg);
		free(stack);
	}
	return (0);
}

void	ft_push_swap(char **argv, t_stack *stack)
{
	if (ft_check_numb(argv) && ft_check_duplicate(argv))
	{
		ft_make_stack_a(argv, stack);
		stack->len_a = ft_lstsize(stack->a);
		stack->stack_len = stack->len_a;
		ft_get_ordered_stack(stack);
		ft_write_order_stack(stack);
		if (ft_stack_a_sorted(stack) == 0)
			ft_case_sort(stack);
		ft_lstclear(&stack->a, free);
		if (stack->b != NULL)
			ft_lstclear(&stack->b, free);
	}
	else
		ft_putstr_fd("Error\n", 2);
}

void	ft_case_sort(t_stack *stack)
{
	if (stack->len_a <= 3)
		ft_case_sort_3(stack);
	else if (stack->len_a <= 5)
		ft_case_sort_5(stack);
	else
		ft_case_sort_radix(stack);
}
