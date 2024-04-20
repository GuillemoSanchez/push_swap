/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:22:04 by guisanch          #+#    #+#             */
/*   Updated: 2024/04/20 10:15:24 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

void	push_and_decrease(t_stack **a, t_stack **b, int *current_size)
{
	push_to_stack(a, b, 'b');
	(*current_size)--;
}

void	push_except_three(t_stack **a, t_stack **b, int size)
{
	int	half;
	int	current_size;

	half = (size / 2) + 1;
	current_size = size;
	while (current_size > half && current_size >= 3)
	{
		if ((*a)->idx < half)
			push_and_decrease(a, b, &current_size);
		else
			rotate(a, 'a');
	}
	while (current_size > 3)
	{
		if ((*a)->idx == size || (*a)->idx == size - 1 || (*a)->idx == size - 2)
			rotate (a, 'a');
		else
			push_and_decrease(a, b, &current_size);
	}
	sort_three_numbers(a);
}

void	calculate_positions(t_stack *s)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = s;
	while (aux)
	{
		aux->pos = i;
		i++;
		aux = aux->next;
	}
}

void	assign_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*aux_b;

	aux_b = *b;
	while (aux_b)
	{
		assign_target_low_idx(a, &aux_b);
		aux_b = aux_b->next;
	}
}

void	exec_optimal(t_stack **a, t_stack **b, int *size_a, int *size_b)
{
	t_stack	*best;
	t_stack	*aux_b;

	aux_b = *b;
	best = *b;
	while (aux_b)
	{
		if ((absv(best->cost_a) + absv(best->cost_b))
			> (absv(aux_b->cost_a) + absv(aux_b->cost_b)))
			best = aux_b;
		aux_b = aux_b->next;
	}
	execute_move(a, b, best->cost_a, best->cost_b);
	push_to_stack(b, a, 'a');
	(*size_a)++;
	(*size_b)--;
}
