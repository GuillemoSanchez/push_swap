/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:45:05 by guisanch          #+#    #+#             */
/*   Updated: 2024/04/20 10:16:03 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

void	white_space(char *str)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (!*str)
		print_error();
}

int	ft_atoi2(char *str)
{
	long	num;
	int		sig;

	num = 0;
	sig = 1;
	white_space(str);
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
	char	**tmp;

	i = 0;
	a = NULL;
	while (argc > ++i)
	{
		j = 0;
		white_space(argv[i]);
		tmp = ft_split(argv[i], ' ');
		if (tmp == NULL)
			return (NULL);
		while (tmp[j])
		{
			if (tmp[j] == NULL)
				return (NULL);
			add_back(&a, stack_new(ft_atoi2(tmp[j++])));
			*size += 1;
		}
		free_split(tmp);
		free(tmp);
	}
	return (a);
}
