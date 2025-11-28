/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 23:55:48 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/28 12:53:47 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the second element on top 'sa, sb' */
void	swap_two_on_top(t_list **stack, char *movement)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (movement)
		ft_printf("%s", movement);
}

/* Swap two stack at same time */
void	swap_at_same(t_list **stack_a, t_list **stack_b)
{
	swap_two_on_top(stack_a, NULL);
	swap_two_on_top(stack_b, NULL);
	ft_printf("ss\n");
}
