/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:23:32 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/09 10:21:34 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include "get_next_line/get_next_line.h"

int	get_action(char *line, t_stack **stack_a, t_stack **stack_b)
{

}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	create_stack_a(argc, argv, &stack_a);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if ((get_action(line,&stack_a, &stack_b)) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			free(line);
			free_stack(&stack_a);
			free_stack(&stack_b);
			exit(1);
		}
		free(line);
	}
	if (is_sorted(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
