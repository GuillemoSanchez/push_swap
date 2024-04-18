/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_target.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:23:25 by guisanch          #+#    #+#             */
/*   Updated: 2024/04/18 18:39:08 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

int	biggest_index(t_stack **a)
{
	t_stack	*aux_a;
	int		biggest;

	aux_a = *a;
	biggest = aux_a->idx;
	while (aux_a)
	{
		if (aux_a->idx > biggest)
			biggest = aux_a->idx;
		aux_a = aux_a->next;
	}
	return (biggest);
}

void	assign_target_low_idx(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	int		closer_idx;
	int		target_pos;

	aux_a = *a;
	closer_idx = biggest_index(&aux_a);
	while (aux_a)
	{
		if ((*b)->idx < aux_a->idx && closer_idx > aux_a->idx)
		{
			closer_idx = aux_a->idx;
			target_pos = aux_a->pos;
		}
		aux_a = aux_a->next;
	}
	(*b)->target_pos = target_pos;
}
