/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:22:57 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/29 12:59:24 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Find position in the stack */
int	find_pos(t_list *stack)
{
	int	value;
	int	pos;

	if (!stack)
		return (-1);
	value = INT_MAX;
	pos = -1;
	while (stack)
	{
		if (stack->content < value)
		{
			value = stack->content;
			pos = stack->pos;
		}
		stack = stack->next;
	}
	return (pos);
}

/* Find node's target */
int	target_position(t_list *node_cmp, t_list *lst_cmp, char from,
			int target_pos)
{
	t_list	*head;
	int		match;

	if (from == 'a')
		match = INT_MIN;
	else
		match = INT_MAX;
	head = lst_cmp;
	while (head)
	{
		if (from == 'a' && (head->content < node_cmp->content
			&& head->content > match))
		{
			match = head->content;
			target_pos = head->pos;
		}
		else if (from == 'b' && (head->content > node_cmp->content
			&& head->content < match))
		{
			match = head->content;
			target_pos = head->pos;
		}
		head = head->next;
	}
	return (target_pos);
}

/* Calculate to find the target*/
void	calculate_target(t_list **list, t_list *node, char from)
{
	t_list	*head;
	int		target_pos;

	head = *list;
	while (head)
	{
		target_pos = target_position(head, node, from, -1);
		if (target_pos == -1)
			target_pos = find_pos(node);
		head->target_pos = target_pos;
		head = head->next;
	}
}
