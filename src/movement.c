/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:15:41 by guisanch          #+#    #+#             */
/*   Updated: 2023/12/27 20:10:51 by guisanch         ###   ########.fr       */
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

void	rrotate(t_stack **list, char option)
{
	t_stack	*tmp;
	t_stack	*change;
	int		save;

	tmp = (*list);
	while (tmp->next)
		tmp = tmp->next;
	save = tmp->value;
	if (option == 'a')
		ft_printf("rra\n");
	if (option == 'b')
		ft_printf("rrb\n");
}
