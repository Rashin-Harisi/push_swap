/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:23:32 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/09 13:38:37 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include "get_next_line/get_next_line.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0'
		&& (s1[index] == s2[index]))
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

static void	ss_bonus(t_stack **stack_A, t_stack **stack_B)
{
	swap(stack_A);
	swap(stack_B);
}

static void	rr_bonus(t_stack **stack_A, t_stack **stack_B)
{
	rotate(stack_A);
	rotate(stack_B);
}

static void	rrr_bonus(t_stack **stack_A, t_stack **stack_B)
{
	reverse_rotate(stack_A);
	reverse_rotate(stack_B);
}

int	get_action(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "pa\n") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "sa\n") == 0)
		swap(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss_bonus(stack_a, stack_b);
	else
		return (-1);
	return (0);
}
