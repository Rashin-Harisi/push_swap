/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:47:41 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/25 18:08:30 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	numbs;

	numbs = number_nodes(*stack_a);
	if (numbs == 2)
		sa(stack_a);
	else if (numbs == 3)
		three_elements(stack_a);
	else if (numbs == 4)
		four_elements(stack_a, stack_b);
	else if (numbs == 5)
		five_elements(stack_a, stack_b);
	else
		turk_sorting(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	create_stack_a(argc, argv, &stack_a);
	if (is_sorted(stack_a))
		ft_printf("the list is sorted\n");
	else
		push_swap(&stack_a, &stack_b);
	print_stack(stack_a, "stack_A");
	print_stack(stack_b, "stack_B");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
