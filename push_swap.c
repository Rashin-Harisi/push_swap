/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:47:41 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/19 15:02:03 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_to_bottom(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!stack || !node)
		return;
	if (!*stack)
	{
		*stack = node;
		return;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = node;
	node->prev = last;	
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_douplicat(t_stack *stack,int value)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (!stack || !*stack)
		return;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	print_stack(t_stack *stack, char *name)
{
	ft_printf("Stack %s\n", name);
	if (!stack)
	{	
		ft_printf("Empty\n");
		return;
	}
	ft_printf("[");
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("]\n");
}

int main(int argc, char *argv[])
{
	int	i;
	long	value;
	t_stack	*stack_A;
//	t_stack	*stack_B;

	stack_A = NULL;
//	stack_B = NULL;
	i = 1;

	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			free_stack(&stack_A);
			write(2,"Error\n",6);
			return (1);
		}
		value = ft_atoi(argv[i]);
		if (value > INT_MAX || value < INT_MIN || is_douplicat(stack_A, (int) value))
		{
			free_stack(&stack_A);
			write(2,"Error\n",6);
			return (1);
		}
		add_to_bottom(&stack_A, new_node((int)value));
		i++;
	}
	print_stack(stack_A , "stack_A");
	return (0);
}
