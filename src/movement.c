/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:15:41 by guisanch          #+#    #+#             */
/*   Updated: 2023/12/26 20:31:46 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

void	rotate(t_stack **list, char option)
{
	t_stack	*tmp;
	int		auxf;
	int		auxs;

	tmp = (*list);
	auxf = tmp->value;
	while (tmp->next->value != 0)
		tmp = tmp->next;
	exit (0);
	auxs = tmp->value;
	tmp->value = auxf;
	*list = tmp;
	(*list)->value = auxs;
	if (option == 'a')
		ft_printf("ra\n");
	if (option == 'b')
		ft_printf("rb\n");
}
