/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:20:05 by guisanch          #+#    #+#             */
/*   Updated: 2024/01/21 13:26:13 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

void	swap_stack(t_stack **list, char option)
{
	t_stack	*tmp;
	int		save;

	tmp = (*list);
	if (!tmp->next)
		return ;
	save = tmp->value;
	tmp->value = tmp->next->value;
	tmp = tmp->next;
	tmp->value = save;
	if (option == 'a')
		ft_printf("sa\n");
	if (option == 'b')
		ft_printf("sb\n");
}

void	swap_stack(t_stack *a, t_stack *b)
{
	swap_stack(&a, 'x');
	swap_stack(&b, 'x');
	ft_printf("ss\n");
}

void	push_to_stack(t_stack *a, t_stack *b)
{
	
}
