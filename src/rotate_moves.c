/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 00:15:19 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/28 12:06:30 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotation stack */
void	rotate_stack(t_list	**stack, char *movement)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = (*stack)->next;
	last = *stack;
	last->next = NULL;
	ft_lstadd_back(&first, last);
	*stack = first;
	if (movement)
		ft_printf("%s", movement);
}

/* Rotate two stacks */
void	rotate_two_stacks(t_list **stack_a, t_list **stack_b)
{
	rotate_stack(stack_a, NULL);
	rotate_stack(stack_b, NULL);
	ft_printf("rr\n");
}

/* Make a reverse rotate */
void	reverse_rotate_stack(t_list	**stack, char *movement)
{
	t_list	*last;
	t_list	*aux;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	aux = *stack;
	while (aux && aux->next->next)
		aux = aux->next;
	last = aux->next;
	aux->next = NULL;
	ft_lstadd_front(stack, last);
	if (movement)
		ft_printf("%s", movement);
}

/* Double reverse rotate */
void	same_reverse_rotate(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_stack(stack_a, NULL);
	reverse_rotate_stack(stack_b, NULL);
	ft_printf("rrr\n");
}