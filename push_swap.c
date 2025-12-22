/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:47:41 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/22 10:37:49 by rabdolho         ###   ########.fr       */
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

//////////////////////////////Actions/////////////////////////////////
t_stack	*find_bottom(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
/////swap///
void	swap(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack || !*stack || !(*stack)->next)
		return;
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
	write(1,"sa\n",3);
}

void	sb(t_stack **stack_B)
{
	swap(stack_B);
	write(1,"sb\n",3);
}

void	ss(t_stack **stack_A, t_stack **stack_B)
{
	if (!stack_A || !*stack_A || !(*stack_A)->next ||
		!stack_B || !*stack_B || !(*stack_B)->next )
		return;
	swap(stack_A);
	swap(stack_B);
	write(1,"ss\n",3);
}
//////push////////
void	push(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*temp;

	if (!stack_A || !stack_B || !*stack_B)
		return;
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
	push(stack_A,stack_B);
	write(1,"pa\n",3);
}

void	pb(t_stack **stack_A, t_stack **stack_B)
{
	push(stack_B,stack_A);
	write(1,"pb\n",3);
}
///////rotation//////
void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack)
		return;
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
	write(1,"ra\n",3);
}

void	rb(t_stack **stack_B)
{
	rotate(stack_B);
	write(1,"rb\n",3);
}

void	rr(t_stack **stack_A, t_stack **stack_B)
{
	if (!stack_A || !*stack_A || !(*stack_A)->next ||
		!stack_B || !*stack_B || !(*stack_B)->next)
		return;
	rotate(stack_A);
	rotate(stack_B);
	write(1,"rr\n",3);
}
//////reverse rotation/////////
void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	last = find_bottom(*stack);
	if (last == NULL)
		return;
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack **stack_A)
{
	reverse_rotate(stack_A);
	write(1,"rra\n",4);
}

void	rrb(t_stack **stack_B)
{
	reverse_rotate(stack_B);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_A, t_stack **stack_B)
{
	if (!stack_A || !*stack_A || !(*stack_A)->next ||
		!stack_B || !*stack_B || !(*stack_B)->next)
		return;
	reverse_rotate(stack_A);
	reverse_rotate(stack_B);
	write(1, "rrr\n", 4);
}

///////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
	int	i;
	long	value;
	char	**result;
	t_stack	*stack_A;
	t_stack	*stack_B;
	int	j;

	stack_A = NULL;
	stack_B = NULL;
	i = 1;
	j = 0;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		result = ft_split(argv[1], ' ');
		while (result[j] != NULL)
		{
			if (!is_number(result[j]))
			{
				free_stack(&stack_A);
				write(2, "Error\n", 6);
				return (1);
			}
			value = ft_atoi(result[j]);
			if (value > INT_MAX || value < INT_MIN || is_douplicat(stack_A, (int) value))
			{
				free_stack(&stack_A);
                        	write(2,"Error\n",6);
                        	return (1);
			}
			add_to_bottom(&stack_A, new_node((int)value));
			j++;
		}
	}
	else
	{
		while (i < argc)
		{
			if (!is_number(argv[i]))
			{
				free_stack(&stack_A);
				write(2,"Error\n",6);
				return (1);
			}
			value = ft_atoi(argv[i]);
			//printf("value is : %ld\n",value);
			if (value > INT_MAX  || value < INT_MIN || is_douplicat(stack_A, (int) value))
			{
				free_stack(&stack_A);
				write(2,"Error\n",6);
				return (1);
			}
			add_to_bottom(&stack_A, new_node((int)value));
			i++;
		}
	}
	add_to_bottom(&stack_B, new_node(54));
	add_to_bottom(&stack_B, new_node(5));
	add_to_bottom(&stack_B, new_node(24));
	add_to_bottom(&stack_B, new_node(0));
	add_to_bottom(&stack_B, new_node(13));
	print_stack(stack_A , "stack_A");
	print_stack(stack_B, "stack_B");
/*
	ft_printf("---------------swap---------------\n");
	sa(&stack_A);
	print_stack(stack_A, "stack_A_SA");
	ss(&stack_A,&stack_B);
	print_stack(stack_A,"stack_A_SS");
	print_stack(stack_B,"stack_B_SS");
	ft_printf("---------------push--------------\n");
	pa(&stack_A, &stack_B);
	print_stack(stack_A , "stack_A_PA");
	print_stack(stack_B, "stack_B_PA");
	pb(&stack_A ,&stack_B);
	print_stack(stack_A , "stack_A_PB");
        print_stack(stack_B, "stack_B_PB");
        ft_printf("---------------rotate--------------\n");
	ra(&stack_A);
        print_stack(stack_A , "stack_A_RA");
	rb(&stack_B);
        print_stack(stack_B, "stack_B_RB");
	rr(&stack_A , &stack_B);
        print_stack(stack_A , "stack_A_RR");
        print_stack(stack_B , "stack_B_RR");
	ft_printf("---------------reverse_rotate--------------\n");
        rra(&stack_A);
        print_stack(stack_A , "stack_A_RRA");
        rrb(&stack_B);
        print_stack(stack_B, "stack_B_RRB");
        rrr(&stack_A , &stack_B);
        print_stack(stack_A , "stack_A_RRR");
        print_stack(stack_B , "stack_B_RRR");
	ft_printf("------------------------------------------\n");
*/
	return (0);
}
