/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_general_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:47:41 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/08 13:22:21 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_stack(t_stack *stack, char *name)
{
	ft_printf("Stack %s\n", name);
	if (!stack)
	{
		ft_printf("Empty\n");
		return ;
	}
	ft_printf("[");
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("]\n");
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	create_node(t_stack **stack_A, char *str)
{
	long	value;

	if (!is_number(str))
	{
		free_stack(stack_A);
		write(2, "Error\n", 6);
		exit(1);
	}
	value = ft_atoi(str);
	if (value > INT_MAX || value < INT_MIN
		|| is_douplicat(*stack_A, (int)value))
	{
		free_stack(stack_A);
		write(2, "Error\n", 6);
		exit(1);
	}
	add_to_bottom(stack_A, new_node((int)value));
}

void	free_string(char **result)
{
	int	i;

	i = 0;
	if (!result)
		return ;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}
