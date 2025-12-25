/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:13:13 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/25 18:17:08 by rabdolho         ###   ########.fr       */
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
	int	value;
	int	index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	swap(t_stack **stack);
void	sa(t_stack **stack_A);//
void	sb(t_stack **stack_B);//
void	ss(t_stack **stack_A, t_stack **stack_B);//
void	push(t_stack **stack_A, t_stack **stack_B);//
void	pa(t_stack **stack_A, t_stack **stack_B);//
void	pb(t_stack **stack_A, t_stack **stack_B);//
void	rotate(t_stack **stack);//
void	ra(t_stack **stack_A);//
void	rb(t_stack **stack_B);//
void	rr(t_stack **stack_A, t_stack **stack_B);//
t_stack	*find_bottom(t_stack *stack);//
void	reverse_rotate(t_stack **stack);//
void	rra(t_stack **stack_A);//
void	rrb(t_stack **stack_B);//
void	rrr(t_stack **stack_A, t_stack **stack_B);//
t_stack	*new_node(int value);//
void	add_to_bottom(t_stack **stack, t_stack *node);//
int		is_number(char *str);//
int		is_douplicat(t_stack *stack, int value);//
void	free_stack(t_stack **stack);//
int		number_nodes(t_stack *stack);//
int		max_value_index(t_stack *stack);//
int		min_value_index(t_stack *stack);//
void	move_to_top(t_stack **stack);//
void	action_forwards_together(t_stack **stack_A, t_stack **stack_B,
			t_stack *lowest, t_stack *position_B);//
void	actions_forwards(t_stack **stack_A, t_stack **stack_B,
			t_stack *lowest, t_stack *position_B);
t_stack	*find_bigger_node(t_stack *stack_A, int value);//
t_stack	*find_smallest_node(t_stack *stack_A);//
void	actions_backwards(t_stack **stack_A,
			t_stack **stack_B, t_stack *position_A);//
int		cost_calculating(t_stack *stack, int nums);//
t_stack	*find_smaller_node(t_stack *stack, int value);//
t_stack	*find_biggest_node(t_stack *stack);//
int		total_cost(t_stack *stack_A, t_stack *stack_B,
			int nums_A, int nums_B);//
t_stack	*find_low_cost_node(t_stack *stack_A, t_stack *stack_B);//
void	print_stack(t_stack *stack, char *name);//
int		is_sorted(t_stack *stack);//
void	create_node(t_stack **stack_A, char *str);//
void	create_stack_a(int argc, char *argv[], t_stack **stack_A);//
void	three_elements(t_stack **stack);//
void	four_elements(t_stack **stack_A, t_stack **stack_B);//
void	five_elements(t_stack **stack_A, t_stack **stack_B);//
void	set_index(t_stack *stack);//
void	final_check(t_stack **stack_A);
void	push_back(t_stack **stack_B, t_stack **stack_A);
void	turk_sorting(t_stack **stack_A, t_stack **stack_B);//

#endif
