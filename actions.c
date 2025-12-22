/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:24:30 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/22 13:53:26 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/////swap///
void    swap(t_stack **stack)
{
        t_stack *temp;
        t_stack *current;

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

void    sa(t_stack **stack_A)
{
        swap(stack_A);
        write(1,"sa\n",3);
}

void    sb(t_stack **stack_B)
{
        swap(stack_B);
        write(1,"sb\n",3);
}

void    ss(t_stack **stack_A, t_stack **stack_B)
{
        if (!stack_A || !*stack_A || !(*stack_A)->next ||
                !stack_B || !*stack_B || !(*stack_B)->next )
                return;
        swap(stack_A);
        swap(stack_B);
        write(1,"ss\n",3);
}
//////push////////
void    push(t_stack **stack_A, t_stack **stack_B)
{
        t_stack *temp;

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

void    pa(t_stack **stack_A, t_stack **stack_B)
{
        push(stack_A,stack_B);
        write(1,"pa\n",3);
}

void    pb(t_stack **stack_A, t_stack **stack_B)
{
        push(stack_B,stack_A);
        write(1,"pb\n",3);
}
///////rotation//////
void    rotate(t_stack **stack)
{       
        t_stack *first;
        t_stack *last;
        
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

void    ra(t_stack **stack_A)
{
        rotate(stack_A);
        write(1,"ra\n",3);
}

void    rb(t_stack **stack_B)
{
        rotate(stack_B);
        write(1,"rb\n",3);
}

void    rr(t_stack **stack_A, t_stack **stack_B)
{
        if (!stack_A || !*stack_A || !(*stack_A)->next ||
                !stack_B || !*stack_B || !(*stack_B)->next)
                return;
        rotate(stack_A);
        rotate(stack_B);
        write(1,"rr\n",3);
}
//////reverse rotation/////////
t_stack *find_bottom(t_stack *stack)
{       
        if (!stack)
                return (NULL);
        while (stack->next)
                stack = stack->next;
        return (stack);
}

void    reverse_rotate(t_stack **stack)
{
        t_stack *last;

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

void    rra(t_stack **stack_A)
{
        reverse_rotate(stack_A);
        write(1,"rra\n",4);
}

void    rrb(t_stack **stack_B)
{
        reverse_rotate(stack_B);
        write(1, "rrb\n", 4);
}

void    rrr(t_stack **stack_A, t_stack **stack_B)
{
        if (!stack_A || !*stack_A || !(*stack_A)->next ||
                !stack_B || !*stack_B || !(*stack_B)->next)
                return;
        reverse_rotate(stack_A);
        reverse_rotate(stack_B);
        write(1, "rrr\n", 4);
}

