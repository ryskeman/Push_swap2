/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 23:42:15 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/27 00:37:12 by fernafer         ###   ########.fr       */
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

/* Reverse rotations */

/* Simple rotations */