/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_turk_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 10:03:28 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/25 13:02:51 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	cost_calculating(t_stack *stack, int nums)
{
	int	cost;

	cost = 0;
	if (!stack)
		return (0);
	if (stack->index <= nums / 2)
		cost = stack->index;
	else
		cost = nums - stack->index;
	return (cost);
}

t_stack	*find_smaller_node(t_stack *stack, int value)
{
	t_stack	*temp;
	long	best_smallest;

	if (!stack)
		return (NULL);
	temp = NULL;
	best_smallest = LONG_MIN;
	while (stack)
	{
		if (stack->value < value && stack->value > best_smallest)
		{
			best_smallest = stack->value;
			temp = stack;
		}
		stack = stack->next;
	}
	return (temp);
}

t_stack	*find_biggest_node(t_stack *stack)
{
	int	index;
	int	i;

	i = 0;
	if (!stack)
		return (NULL);
	index = max_value_index(stack);
	while (i < index)
	{
		stack = stack->next;
		i++;
	}
	if (i == index)
		return (stack);
	return (NULL);
}

int	total_cost(t_stack *stack_A, t_stack *stack_B, int nums_A, int nums_B)
{
	int		cost_a;
	int		cost_b;
	t_stack	*temp;

	cost_a = cost_calculating(stack_A, nums_A);
	temp = find_smaller_node(stack_B, stack_A->value);
	if (!temp)
		temp = find_biggest_node(stack_B);
	cost_b = cost_calculating(temp, nums_B);
	if ((stack_A->index <= nums_A / 2 && temp->index <= nums_B / 2)
		|| (stack_A->index > nums_A / 2 && temp->index > nums_B / 2))
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	return (cost_a + cost_b);
}

t_stack	*find_low_cost_node(t_stack *stack_A, t_stack *stack_B)
{
	t_stack	*low_cost_node;
	t_stack	*current_a;
	int		min;
	int		current_cost;

	if (!stack_A || !stack_B)
		return (NULL);
	set_index(stack_A);
	set_index(stack_B);
	current_a = stack_A;
	low_cost_node = stack_A;
	min = INT_MAX;
	while (current_a)
	{
		current_cost = total_cost(current_a, stack_B,
				number_nodes(stack_A), number_nodes(stack_B));
		if (current_cost < min)
		{
			min = current_cost;
			low_cost_node = current_a;
		}
		current_a = current_a->next;
	}
	return (low_cost_node);
}
