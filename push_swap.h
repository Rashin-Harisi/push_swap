/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:13:13 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/23 16:51:36 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int		value;
	int		index;
	struct s_stack	*next;
	struct s_stack	*prev;
} t_stack;
void    swap(t_stack **stack);
void    sa(t_stack **stack_A);
void    sb(t_stack **stack_B);
void    ss(t_stack **stack_A, t_stack **stack_B);
void    push(t_stack **stack_A, t_stack **stack_B);
void    pa(t_stack **stack_A, t_stack **stack_B);
void    pb(t_stack **stack_A, t_stack **stack_B);
void    rotate(t_stack **stack);
void    ra(t_stack **stack_A);
void    rb(t_stack **stack_B);
void    rr(t_stack **stack_A, t_stack **stack_B);
t_stack *find_bottom(t_stack *stack);
void    reverse_rotate(t_stack **stack);
void    rra(t_stack **stack_A);
void    rrb(t_stack **stack_B);
void    rrr(t_stack **stack_A, t_stack **stack_B);
int     number_nodes(t_stack *stack);
void    two_elements(t_stack **stack);
void    three_elements(t_stack **stack);
void    four_elements(t_stack **stack_A, t_stack **stack_B);
void    five_elements(t_stack **stack_A, t_stack **stack_B);
int     max_value_index(t_stack *stack);
void    turk_sorting(t_stack **stack_A, t_stack **stack_B);

#endif
