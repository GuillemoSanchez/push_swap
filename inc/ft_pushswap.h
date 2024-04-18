/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:45:59 by guisanch          #+#    #+#             */
/*   Updated: 2024/04/17 20:19:49 by guisanch         ###   ########.fr       */
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
	int				pos;
	struct s_stack	*next;
}					t_stack;

/*--- PARSE ---*/
t_stack		*process(int argc, char **argv, int *size);
void		white_space(char *str);
int			ft_atoi2(char *str);

/*--- FILL_STACK ---*/
t_stack		*stack_new(int con);
void		add_back(t_stack **lst, t_stack *new);

/*--- FREE ---*/
void		print_error(void);
void		free_split(char **str);
void		freestack(t_stack **s);

/*--- COMPROBATION ---*/
int			ft_dupcheck(t_stack *stack);
int			ft_sortcheck(t_stack *stack);

/*--- MOVEMENT ---*/
void		rotate(t_stack **list, char option);
void		reverse_rotate(t_stack **list, char option);
void		rr(t_stack *a, t_stack *b);
void		rrr(t_stack *a, t_stack *b);

/*--- SWAP ---*/
void		swap_stack(t_stack **list, char option);
void		swap_twice_stack(t_stack *a, t_stack *b);
void		push_to_stack(t_stack **origin, t_stack **des, char option);

/*--- SORT ---*/
void		sort_three_numbers(t_stack **a);
void		asig_indx(t_stack *a, int size);
void		ft_push_swap(t_stack **a, t_stack **b, int size);
void		sort_more_three(t_stack **a, t_stack **b, int size);

/*--- FUNCTION ---*/
void		push_except_three(t_stack **a, t_stack **b, int size);
void		push_and_decrease(t_stack **a, t_stack **b, int *current_size);
void		calculate_positions(t_stack *s);

#endif