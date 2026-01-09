/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_general_third.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:47:41 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/09 13:42:06 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	fill_stack(t_stack **stack_a, char **value, int i, int is_split)
{
	while (value[i])
	{
		create_node(stack_a, value[i]);
		i++;
	}
	if (is_split)
		free_string(value);
}

void	create_stack_a(int argc, char *argv[], t_stack **stack_A)
{
	char	**result;
	int		i;

	result = NULL;
	if (argc == 2)
	{
		result = ft_split(argv[1], ' ');
		if (!result)
			return ;
		fill_stack(stack_A, result, 0, 1);
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
