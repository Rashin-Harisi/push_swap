/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:24:30 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/25 11:53:10 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*find_bottom(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = find_bottom(*stack);
	if (last == NULL)
		return ;
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack **stack_A)
{
	reverse_rotate(stack_A);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_B)
{
	reverse_rotate(stack_B);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_A, t_stack **stack_B)
{
	if (!stack_A || !*stack_A || !(*stack_A)->next
		|| !stack_B || !*stack_B || !(*stack_B)->next)
		return ;
	reverse_rotate(stack_A);
	reverse_rotate(stack_B);
	write(1, "rrr\n", 4);
}
