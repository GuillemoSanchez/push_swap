/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:27:48 by guisanch          #+#    #+#             */
/*   Updated: 2024/02/04 11:04:08 by guisanch         ###   ########.fr       */
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
