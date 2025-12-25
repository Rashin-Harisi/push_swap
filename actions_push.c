/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:24:30 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/25 11:47:35 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*temp;

	if (!stack_A || !stack_B || !*stack_B)
		return ;
	temp = *stack_B;
	*stack_B = (*stack_B)->next;
	if (*stack_B)
		(*stack_B)->prev = NULL;
	temp->next = *stack_A;
	if (*stack_A)
		(*stack_A)->prev = temp;
	*stack_A = temp;
	temp->prev = NULL;
}

void	pa(t_stack **stack_A, t_stack **stack_B)
{
	push(stack_A, stack_B);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_A, t_stack **stack_B)
{
	push(stack_B, stack_A);
	write(1, "pb\n", 3);
}
