/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:01:43 by guisanch          #+#    #+#             */
/*   Updated: 2024/04/20 10:17:38 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

void	exec_duble(t_stack **a, t_stack **b, int *movsa, int *movsb)
{
	if ((*movsa) > 0 && (*movsb) > 0)
	{
		rr(a, b);
		(*movsa)--;
		(*movsb)--;
	}
	else if ((*movsa) < 0 && (*movsb) < 0)
	{
		rrr(a, b);
		(*movsa)++;
		(*movsb)++;
	}
}

void	execute_move(t_stack **a, t_stack **b, int movsa, int movsb)
{
	while (movsa != 0 || movsb != 0)
	{
		if ((movsa > 0 && movsb > 0) || (movsa < 0 && movsb < 0))
			exec_duble(a, b, &movsa, &movsb);
		else if (movsa < 0)
		{
			reverse_rotate(a, 'a');
			movsa++;
		}
		else if (movsb < 0)
		{
			reverse_rotate(b, 'b');
			movsb++;
		}
		else if (movsa > 0)
		{
			rotate(a, 'a');
			movsa--;
		}
		else if (movsb > 0)
		{
			rotate(b, 'b');
			movsb--;
		}
	}
}

static int	calc_rotates(t_stack **a, int size_a)
{
	t_stack	*aux_a;

	aux_a = *a;
	calculate_positions(*a);
	while (aux_a)
	{
		if (aux_a->idx == 1)
		{
			if ((aux_a->pos + 1) <= size_a / 2 + 1)
				return (aux_a->pos);
			else
				return (aux_a->pos - size_a);
		}
		aux_a = aux_a->next;
	}
	return (0);
}

void	rotate_sorted(t_stack **a, int size_a)
{
	int	n_rotates;

	n_rotates = calc_rotates(a, size_a);
	while (n_rotates != 0)
	{
		if (n_rotates < 0)
		{
			reverse_rotate(a, 'a');
			n_rotates++;
		}
		else
		{
			rotate(a, 'a');
			n_rotates--;
		}
	}
}
