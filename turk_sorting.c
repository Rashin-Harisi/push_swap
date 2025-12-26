/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 10:03:28 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/26 10:11:34 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	index;

	index = 0;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = index;
		stack = stack->next;
		index++;
	}
}

void	final_check(t_stack **stack_A)
{
	t_stack	*smallest;
	int		nums_a;

	set_index(*stack_A);
	nums_a = number_nodes(*stack_A);
	smallest = find_smallest_node(*stack_A);
	while (*stack_A != smallest)
	{
		if (smallest->index <= nums_a / 2)
			ra(stack_A);
		else if (smallest->index > nums_a / 2)
			rra(stack_A);
	}
}

void	push_back(t_stack **stack_B, t_stack **stack_A)
{
	t_stack	*position_a;

	while (*stack_B)
	{
		set_index(*stack_A);
		set_index(*stack_B);
		position_a = find_bigger_node(*stack_A, (*stack_B)->value);
		if (!position_a)
			position_a = find_smallest_node(*stack_A);
		actions_backwards(stack_A, stack_B, position_a);
	}
}

void	turk_sorting(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*lowest;
	t_stack	*position_b;

	if (!stack_A || !stack_B || !*stack_A)
		return ;
	pb(stack_A, stack_B);
	pb(stack_A, stack_B);
	while (number_nodes(*stack_A) > 3)
	{
		lowest = find_low_cost_node(*stack_A, *stack_B);
		position_b = find_smaller_node(*stack_B, lowest->value);
		if (!position_b)
			position_b = find_biggest_node(*stack_B);
		actions_forwards(stack_A, stack_B, lowest, position_b);
	}
	three_elements(stack_A);
	push_back(stack_B, stack_A);
	final_check(stack_A);
}
