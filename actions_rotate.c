/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:24:30 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/25 11:57:09 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack **stack_A)
{
	rotate(stack_A);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_B)
{
	rotate(stack_B);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_A, t_stack **stack_B)
{
	if (!stack_A || !*stack_A || !(*stack_A)->next
		|| !stack_B || !*stack_B || !(*stack_B)->next)
		return ;
	rotate(stack_A);
	rotate(stack_B);
	write(1, "rr\n", 3);
}
