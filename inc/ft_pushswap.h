/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:45:59 by guisanch          #+#    #+#             */
/*   Updated: 2023/12/23 12:19:26 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H
# include "../libft/libft.h"
# include <unistd.h>
# include <string.h>

typedef struct s_stack
{
	int				value;
	int				idx;
	struct s_stack	*next;
}					t_stack;

// void	sa(t_stack a, t_stack b);
/*--- PARSE ---*/
t_stack	*process(int argc, char **argv, int *size);

/*--- FILL_STACK ---*/
t_stack	*stack_new(int con);
void	add_back(t_stack **lst, t_stack *new);

/*--- FREE ---*/
void	print_error(void);
void	free_split(char **str);

/*--- COMPROBATION ---*/
int		ft_dupcheck(t_stack *stack);
void	freestack(t_stack **s);
#endif