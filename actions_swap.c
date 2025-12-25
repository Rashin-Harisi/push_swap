/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:24:30 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/25 12:01:08 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	current = *stack;
	temp = current->next;
	current->next = temp->next;
	if (temp->next)
		temp->next->prev = current;
	temp->prev = current->prev;
	temp->next = current;
	current->prev = temp;
	*stack = temp;
}

void	sa(t_stack **stack_A)
{
	swap(stack_A);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_B)
{
	swap(stack_B);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_A, t_stack **stack_B)
{
	if (!stack_A || !*stack_A || !(*stack_A)->next
		|| !stack_B || !*stack_B || !(*stack_B)->next)
		return ;
	swap(stack_A);
	swap(stack_B);
	write(1, "ss\n", 3);
}
