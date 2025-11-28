/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 23:42:15 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/27 23:52:55 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute movements */
void	exec_movements(t_list **stack_from, t_list **stack_to, t_list *node,
		char move)
{
	if (move == 'a')
	{
		if (node->cost_a >= 0 && node->cost_b >= 0)
			ft_rr(stack_from, stack_to, node);
		else if (node->cost_a < 0 && node->cost_b < 0)
			ft_rrr(stack_from, stack_to, node);
		else
			handle_moves(stack_from, stack_to, node);
	}
	else
	{
		if (node->cost_a >= 0 && node->cost_b >= 0)
			ft_rr(stack_to, stack_from, node);
		else if (node->cost_a < 0 && node->cost_b < 0)
			ft_rrr(stack_to, stack_from, node);
		else
			handle_moves(stack_to, stack_from, node);
	}
}

/* Handle movements */
void	handle_moves(t_list **a, t_list **b, t_list *node)
{
	if (node->cost_a > 0)
		while (node->cost_a-- > 0)
			rotate_stack(a, "ra\n");
	else
		while (node->cost_a++ < 0)
			reverse_rotate_stack(a, "rra\n");
	if (node->cost_b-- > 0)
		while (node->cost_b-- > 0)
			rotate_stack(b, "rb\n");
	else
		while (node->cost_b++ < 0)
			reverse_rotate_stack(b, "rrb\n");
}

/* Reverse rotations */
void	ft_rrr(t_list **a, t_list **b, t_list *node)
{
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		same_reverse_rotate(a, b);
		node->cost_a++;
		node->cost_b++;
	}
	while (node->cost_a++ < 0)
		reverse_rotate_stack(a, "rra\n");
	while (node->cost_b++ < 0)
		reverse_rotate_stack(b, "rrb\n");
}

/* Simple rotations */
void	ft_rr(t_list **a, t_list **b, t_list *node)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		rotate_two_stacks(a, b);
		node->cost_a--;
		node->cost_b--;
	}
	while (node->cost_a-- > 0)
		rotate_stack(a, "ra\n");
	while (node->cost_b-- > 0)
		rotate_stack(b, "rb\n");
}
