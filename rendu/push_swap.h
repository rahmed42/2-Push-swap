/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:08:10 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/31 01:39:36 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int		len_a;
	int		len_b;
	int		stack_len;
	int		stack_val_mid;
	int		*sorted;
	int		max_a;
	int		min_a;
	int		max_b;
	int		min_b;
	t_list	*a;
	t_list	*b;
	t_list	*tmp;
	int		val1;
	int		val2;
	int		val3;
}	t_stack;

enum	e_order
{
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

void	ft_push_swap(char **argv, t_stack *stack);
void	ft_case_sort(t_stack *stack);
void	ft_write_order_stack(t_stack *stack);
void	sort_tab(t_stack *stack);
void	ft_sort_push_a(t_stack *stack, int sort);
void	ft_sort_push_b(t_stack *stack, int sort);
void	ft_sort_3_a_stack(t_stack *stack);
void	ft_case_sort_3(t_stack *stack);
void	ft_case_sort_5(t_stack *stack);
void	ft_case_sort_radix(t_stack *stack);
void	ft_get_ordered_stack(t_stack *stack);
void	ft_get_values(t_stack *stack);
void	ft_get_a_values(t_stack *stack);
void	ft_get_b_values(t_stack *stack);
void	ft_make_stack_a(char **argv, t_stack *stack);
int		ft_stack_a_sorted(t_stack *stack);
int		ft_stack_b_sorted(t_stack *stack);
int		ft_check_numb(char **argv);
int		ft_check_duplicate(char **argv);
void	ft_swap_sa(t_stack *stack, size_t order);
void	ft_swap_sb(t_stack *stack, size_t order);
void	ft_swap_ss(t_stack *stack, size_t order);
void	ft_push_pa(t_stack *stack);
void	ft_push_pb(t_stack *stack);
void	ft_rotate_ra(t_stack *stack, size_t order);
void	ft_rotate_rb(t_stack *stack, size_t order);
void	ft_rotate_rr(t_stack *stack, size_t order);
void	ft_reverse_rotate_rra(t_stack *stack, size_t order);
void	ft_reverse_rotate_rrb(t_stack *stack, size_t order);
void	ft_reverse_rotate_rrr(t_stack *stack, size_t order);

#endif
