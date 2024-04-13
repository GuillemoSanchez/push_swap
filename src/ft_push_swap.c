/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:26:42 by guisanch          #+#    #+#             */
/*   Updated: 2024/04/13 12:01:55 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

/*
	sa-> intercambia 2 primeros elementos de a(Check si hay 1 numero o menos >:()
	sb-> intercambia 2 primeros elementos de b(Check si hay 1 numero o menos >:()
	ss-> los dos a la ves quiere decir que sa y sb se ejecutan
	pa-> Toma el primer elemento del stack b y lo pone el primero del stack a
		 (si b esta vacio no hace nada)
	pb-> Toma el primer elemento del stack a y lo pone el primero del stack b
		 (si a esta vacio no hace nada)
	ra-> rota la lista a si tengo 1, 2, 3, 4 lo convierte en 4, 2, 3, 1
	rb-> rota la lista b si tengo 1, 2, 3, 4 lo convierte en 4, 2, 3, 1
	rr-> rota ambas listas
	rra-> lo hace al contrario rota la lista a si tengo 4, 3, 2, 1 lo convierte en 1, 4, 3, 2
	rrb-> lo hace al contrario rota la lista b si tengo 4, 3, 2, 1 lo convierte en 1, 4, 3, 2
	rrr-> aplica los dos
*/

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
		if (ft_dupcheck(a))
		{
			freestack(&a);
			print_error();
		}
		if (ft_sortcheck(a))
		{
			print_error();
		}
		asig_indx(a, size);
		ft_push_swap(a, b, size);
	}
}
