/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:15:41 by guisanch          #+#    #+#             */
/*   Updated: 2024/04/19 21:50:23 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

void	rotate(t_stack **list, char option)
{
	t_stack	*tmp;

	tmp = (*list);
	if (!tmp)
		return ;
	while ((*list)->next)
		*list = (*list)->next;
	(*list)->next = tmp;
	*list = tmp->next;
	tmp->next = NULL;
	if (option == 'a')
		ft_printf("ra\n");
	if (option == 'b')
		ft_printf("rb\n");
}

void	reverse_rotate(t_stack **list, char option)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*pre;

	pre = (*list);
	last = (*list)->next;
	if (last != NULL)
	{
		while (last->next)
			last = last->next;
		while (pre->next->next)
			pre = pre->next;
		tmp = (*list);
		(*list) = last;
		last->next = tmp;
		pre->next = NULL;
		if (option == 'a')
			ft_printf("rra\n");
		if (option == 'b')
			ft_printf("rrb\n");
	}
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 'x');
	rotate(b, 'x');
	ft_printf("rr\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 'x');
	reverse_rotate(b, 'x');
	ft_printf("rrr\n");
}
