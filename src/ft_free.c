/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:11:16 by guisanch          #+#    #+#             */
/*   Updated: 2023/12/14 19:32:39 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

void	print_error(void)
{
	ft_printf("\033[0;31m""Error\n");
	exit(EXIT_FAILURE);
}

void	free_split(char **str)
{
	char	*s1;

	if (!str)
		return ;
	while (*str)
	{
		s1 = *str,
		str++;
		free(s1);
	}
	*str = NULL;
}