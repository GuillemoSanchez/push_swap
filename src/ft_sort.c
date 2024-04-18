/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:27:48 by guisanch          #+#    #+#             */
/*   Updated: 2024/04/18 18:40:51 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

static t_stack	*get_idx_min(t_stack *a)
{
	t_stack	*min;
	t_stack	*aux;

	aux = a;
	while (aux && aux->idx != 0)
		aux = aux->next;
	min = aux;
	while (aux)
	{
		if (aux->value < min->value && aux->idx == 0)
			min = aux;
		aux = aux->next;
	}
	return (min);
}

void	asig_indx(t_stack *a, int size)
{
	int	index;

	index = 1;
	while (index <= size)
	{
		get_idx_min(a)->idx = index;
		index++;
	}
}

void	sort_three_numbers(t_stack **a)
{
	t_stack	*fir;
	t_stack	*sec;
	t_stack	*thi;

	fir = *a;
	sec = (*a)->next;
	thi = (*a)->next->next;
	if (fir->idx > sec->idx && fir->idx > thi->idx)
		rotate(a, 'a');
	else if (fir->idx < sec->idx && fir->idx > thi->idx)
		reverse_rotate(a, 'a');
	fir = *a;
	sec = (*a)->next;
	if (fir->idx > sec->idx)
		swap_stack(a, 'a');
}

void	sort_more_three(t_stack **a, t_stack **b, int size)
{
	int	size_a;
	int	size_b;
	
	push_except_three(a, b, size);
	size_a = 3;
	size_b = size - 3;
	(void) size_a;
	(void) size_b;
	while (*b)
	{
		calculate_positions(*a);
		calculate_positions(*b);
		assign_target_pos(a, b);
		assign_costs(b, size_a, size_b);
	}
}

void	ft_push_swap(t_stack **a, t_stack **b, int size)
{
	if(!ft_sortcheck(*a))
	{
		if (size == 3)
			sort_three_numbers(a);
		if (size > 3)
			sort_more_three(a, b, size);
	}
}
