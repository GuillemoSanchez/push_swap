/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:45:05 by guisanch          #+#    #+#             */
/*   Updated: 2023/12/13 19:42:35 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

/*
	Vamos a meter tode el parseo aquí
	Recomendan guardar todo con un split en la lista y hacer todas las comprobaciones
*/
int	white_space(char *str)
{

	while (str[cont] == ' ' || (str[cont] >= '\t' && str[cont] <= '\r'))
		
	return (cont);
}

int	ft_atoi2(char *str)
{
	int		num;
	int		sig;

	num = 0;
	sig = 1;
	while (white_space(str))
		str++;
	if (!*str)
		print_error();
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig *= -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			print_error();
		num = num * 10 + (*str - 48);
		str++;
	}
	if ((sig * num) > 2147483647 || (sig * num) < -2147483648)
		print_error();
	return (sig * num);
}

t_stack	*process(int argc, char **argv, int *size)
{
	t_stack	*a;
	int		i;
	int		j;
	int		pru;
	char	**tmp;

	i = 1;
	a = NULL;
	if (argc < 2)
		print_error();
	while (argc > i)
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j])
		{
			pru = ft_atoi2(tmp[j]);
			j++;
		}
	}
}
