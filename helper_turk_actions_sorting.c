/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_turk_actions_sorting.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 10:03:28 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/25 12:42:37 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	action_forwards_together(t_stack **stack_A, t_stack **stack_B,
	t_stack *lowest, t_stack *position_B)
{
	int	nums_a;
	int	nums_b;

	nums_a = number_nodes(*stack_A);
	nums_b = number_nodes(*stack_B);
	if (lowest->index <= nums_a / 2 && position_B->index <= nums_b / 2)
	{
		while (*stack_A != lowest && *stack_B != position_B)
			rr(stack_A, stack_B);
	}
	else if (lowest->index > nums_a / 2 && position_B->index > nums_b / 2)
	{
		while (*stack_A != lowest && *stack_B != position_B)
			rrr(stack_A, stack_B);
	}
}

void	actions_forwards(t_stack **stack_A, t_stack **stack_B,
	t_stack *lowest, t_stack *position_B)
{
	int	nums_a;
	int	nums_b;

	nums_a = number_nodes(*stack_A);
	nums_b = number_nodes(*stack_B);
	action_forwards_together(stack_A, stack_B, lowest, position_B);
	while (*stack_A != lowest)
	{
		if (lowest->index <= nums_a / 2)
			ra(stack_A);
		else
			rra(stack_A);
	}
	while (*stack_B != position_B)
	{
		if (position_B->index <= nums_b / 2)
			rb(stack_B);
		else
			rrb(stack_B);
	}
	pb(stack_A, stack_B);
}

t_stack	*find_bigger_node(t_stack *stack_A, int value)
{
	t_stack	*temp;
	long	best_biggest;

	if (!stack_A)
		return (NULL);
	temp = NULL;
	best_biggest = LONG_MAX;
	while (stack_A)
	{
		if (stack_A->value > value && stack_A->value < best_biggest)
		{
			best_biggest = stack_A->value;
			temp = stack_A;
		}
		stack_A = stack_A->next;
	}
	return (temp);
}

t_stack	*find_smallest_node(t_stack *stack_A)
{
	t_stack	*temp;
	int		min;

	if (!stack_A)
		return (NULL);
	min = stack_A->value;
	temp = stack_A;
	while (stack_A)
	{
		if (min > stack_A->value)
		{
			min = stack_A->value;
			temp = stack_A;
		}
		stack_A = stack_A->next;
	}
	return (temp);
}

void	actions_backwards(t_stack **stack_A,
	t_stack **stack_B, t_stack *position_A)
{
	int	nums_a;

	nums_a = number_nodes(*stack_A);
	if (position_A->index <= nums_a / 2)
	{
		while (*stack_A != position_A)
			ra(stack_A);
	}
	else if (position_A->index > nums_a / 2)
	{
		while (*stack_A != position_A)
			rra(stack_A);
	}
	pa(stack_A, stack_B);
}
