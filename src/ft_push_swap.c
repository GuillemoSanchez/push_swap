/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:26:42 by guisanch          #+#    #+#             */
/*   Updated: 2024/04/20 10:11:12 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

int	main(int argc, char *argv[])
{
	int		size;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	size = 0;
	if (argc > 1)
	{
		if (argc < 2)
			print_error();
		a = process(argc, argv, &size);
		if (a == NULL)
			print_error();
		if (ft_dupcheck(a))
		{
			freestack(a);
			print_error();
		}
		if (ft_sortcheck(a))
			print_error();
		asig_indx(a, size);
		ft_push_swap(&a, &b, size);
		freestack(a);
	}
}
