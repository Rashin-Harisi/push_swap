/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_small_sorting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:09:18 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/25 12:17:03 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	number_nodes(t_stack *stack)
{
	int	num;

	if (!stack)
		return (0);
	num = 0;
	while (stack)
	{
		num++;
		stack = stack->next;
	}
	return (num);
}

int	max_value_index(t_stack *stack)
{
	int	max;
	int	max_index;
	int	index;

	index = 0;
	max_index = 0;
	if (!stack)
		return (0);
	max = stack->value;
	while (stack)
	{
		if (max < stack->value)
		{
			max = stack->value;
			max_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (max_index);
}

int	min_value_index(t_stack *stack)
{
	int	min;
	int	index;
	int	min_index;

	if (!stack)
		return (0);
	min = stack->value;
	index = 0;
	min_index = 0;
	while (stack)
	{
		if (min > stack->value)
		{
			min = stack->value;
			min_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (min_index);
}

void	move_to_top(t_stack **stack)
{
	int	index;
	int	nums;

	if (!stack || !*stack)
		return ;
	index = min_value_index(*stack);
	nums = number_nodes(*stack);
	if (index >= nums / 2)
	{
		while (index < nums)
		{
			rra(stack);
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			ra(stack);
			index--;
		}
	}
}
