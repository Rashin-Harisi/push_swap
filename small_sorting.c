/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:09:18 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/25 14:37:20 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//////////////////////////////////////////////////////////////////////////
void	three_elements(t_stack **stack)
{
	int	index;

	if (!stack || !*stack)
		return ;
	index = max_value_index(*stack);
	if (index == 0)
	{
		ra(stack);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	}
	else if (index == 1)
	{
		rra(stack);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	}
	else
		sa(stack);
}

void	four_elements(t_stack **stack_A, t_stack **stack_B)
{
	if (!stack_A || !*stack_A ||!stack_B)
		return ;
	move_to_top(stack_A);
	pb(stack_A, stack_B);
	three_elements(stack_A);
	pa(stack_A, stack_B);
}

void	five_elements(t_stack **stack_A, t_stack **stack_B)
{
	if (!stack_A || !*stack_A ||!stack_B)
		return ;
	move_to_top(stack_A);
	pb(stack_A, stack_B);
	four_elements(stack_A, stack_B);
	pa(stack_A, stack_B);
}
