/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:15:41 by guisanch          #+#    #+#             */
/*   Updated: 2023/12/28 19:57:14 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

void	rotate(t_stack **list, char option)
{
	t_stack	*tmp;
	int		save;

	tmp = (*list);
	save = tmp->value;
	while (tmp->next)
	{
		tmp->value = tmp->next->value;
		tmp = tmp->next;
	}
	tmp->value = save;
	if (option == 'a')
		ft_printf("ra\n");
	if (option == 'b')
		ft_printf("rb\n");
}

void	reverse_rotate(t_stack **list, char option)
{
	t_stack	*tmp;
	int		change;
	int		save;

	tmp = (*list);
	while (tmp->next)
		tmp = tmp->next;
	save = tmp->value;
	tmp = (*list);
	change = tmp->value;
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp->idx = tmp->value;
		tmp->value = change;
		change = tmp->idx;
	}
	tmp = (*list);
	tmp->value = save;
	if (option == 'a')
		ft_printf("rra\n");
	if (option == 'b')
		ft_printf("rrb\n");
}

void	rr(t_stack *a, t_list *b)
{
	rotate(&a, 'x');
	rotate(&b, 'x');
	ft_printf("rr\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(&a, 'x');
	reverse_rotate(&b, 'x');
	ft_printf("rrr\n");
}
