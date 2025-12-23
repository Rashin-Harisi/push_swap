/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 10:03:28 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/23 16:50:27 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	index;

	index = 0;
	if (!stack)
		return;
	while(stack)
	{
		stack->index = index;
		stack = stack->next;
		index++;
	}
}

int	cost_calculating(t_stack *stack, int nums)
{
	int	cost;

	cost = 0;
	if (!stack)
		return (0);
	if(stack->index <= nums / 2)
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
	while(i < index)
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
	int	cost_A;
	int	cost_B;
	t_stack	*temp;

	cost_A = cost_calculating(stack_A, nums_A);
	temp = find_smaller_node(stack_B, stack_A->value);
	if (!temp)
		temp = find_biggest_node(stack_B);
	cost_B = cost_calculating(temp, nums_B);
	if ((stack_A->index <= nums_A / 2 && temp->index <= nums_B / 2) ||
		(stack_A->index > nums_A / 2 && temp->index > nums_B / 2))
	{
		if (cost_A > cost_B)
			return (cost_A);
		else
			return (cost_B);
	}
	return (cost_A + cost_B);
}

t_stack	*find_low_cost_node(t_stack *stack_A , t_stack *stack_B)
{
	t_stack	*low_cost_node;
	t_stack	*current_A;
	int	nums_A;
	int	nums_B;
	int	min;
	int	current_cost;
	
	if (!stack_A || !stack_B)
		return (NULL);
	set_index(stack_A);
	set_index(stack_B);
	nums_A = number_nodes(stack_A);
	nums_B = number_nodes(stack_B);
	current_A = stack_A;
	low_cost_node = stack_A;
	min = INT_MAX;
	while (current_A)
	{
		current_cost = total_cost(current_A, stack_B, nums_A, nums_B);
		if (current_cost < min)
		{
			min = current_cost;
			low_cost_node = current_A;
		}
		current_A = current_A->next;
	}
	return (low_cost_node);
}

void	actions_forwards(t_stack **stack_A, t_stack **stack_B, t_stack *lowest, t_stack *position_B)
{
	int	nums_A;
	int	nums_B;

	nums_A = number_nodes(*stack_A);
	nums_B = number_nodes(*stack_B);
	if (lowest->index <= nums_A / 2 && position_B->index <= nums_B / 2)
	{
		while (*stack_A != lowest && *stack_B != position_B)
			rr(stack_A, stack_B);
	}
	else if (lowest->index >nums_A / 2 && position_B->index > nums_B / 2)
	{
		while (*stack_A != lowest && *stack_B != position_B)
			rrr(stack_A , stack_B);
	}
	while (*stack_A != lowest)
	{
		if (lowest->index <= nums_A / 2)
			ra(stack_A);
		else
			rra(stack_A);
	}
	while (*stack_B != position_B)
	{
		if (position_B->index <= nums_B / 2)
			rb(stack_B);
		else
			rrb(stack_B);
	}
	pb(stack_A, stack_B);
}

t_stack	*find_bigger_node(t_stack *stack_A, int value)
{
        t_stack *temp;
        long    best_biggest;

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
	int	min;
	t_stack	*temp;

	if(!stack_A)
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

void actions_backwards(t_stack **stack_A, t_stack **stack_B, t_stack *position_A)
{
	int	nums_A;

	nums_A = number_nodes(*stack_A);
	if (position_A->index <= nums_A / 2)
	{
		while (*stack_A != position_A)
			ra(stack_A);
	}
	else if (position_A->index > nums_A / 2)
	{
		while (*stack_A != position_A)
			rra(stack_A);
	}
	pa(stack_A, stack_B);
}

void	final_check(t_stack **stack_A)
{
	t_stack	*smallest;
	int	nums_A;

	set_index(*stack_A);
	nums_A = number_nodes(*stack_A);
	smallest = find_smallest_node(*stack_A);
	while (*stack_A != smallest)
	{
		if (smallest->index <= nums_A / 2)
			ra(stack_A);
		else if (smallest->index > nums_A / 2)
			rra(stack_A);
	}
}

void	turk_sorting(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*lowest;
	t_stack	*position_B;
	t_stack	*position_A;

	if (!stack_A || !stack_B || !*stack_A)
		return;
	pb(stack_A, stack_B);
	pb(stack_A, stack_B);
	while (number_nodes(*stack_A) > 3)
	{
		lowest = find_low_cost_node(*stack_A, *stack_B);
		position_B = find_smaller_node(*stack_B , lowest->value);
		if (!position_B)
			position_B = find_biggest_node(*stack_B);
		actions_forwards(stack_A, stack_B, lowest, position_B);
	}
	three_elements(stack_A);
	while (*stack_B)
	{
		set_index(*stack_A);
		set_index(*stack_B);
		position_A = find_bigger_node(*stack_A, (*stack_B)->value);
		if (!position_A)
			position_A = find_smallest_node(*stack_A);
		actions_backwards(stack_A, stack_B, position_A);
	}
	final_check(stack_A);
}
