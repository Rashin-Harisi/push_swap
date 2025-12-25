/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_general_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:47:41 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/25 18:16:09 by rabdolho         ###   ########.fr       */
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
		return ;
	}
	value = ft_atoi(str);
	if (value > INT_MAX || value < INT_MIN || is_douplicat(*stack_A, (int)value))
	{
		free_stack(stack_A);
		write(2, "Error\n", 6);
		return ;
	}
	add_to_bottom(stack_A, new_node((int)value));
}

void	create_stack_a(int argc, char *argv[], t_stack **stack_A)
{
	char	**result;
	int		i;

	if (argc == 2)
	{
		i = 0;
		result = ft_split(argv[1], ' ');
		while (result[i] != NULL)
		{
			create_node(stack_A, result[i]);
			i++;
		}
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			create_node(stack_A, argv[i]);
			i++;
		}
	}
}
