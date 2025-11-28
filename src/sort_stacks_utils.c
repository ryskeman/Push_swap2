/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 23:49:31 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/28 01:01:18 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Find biggest number */
int	maximum(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/* Find absolute value */
int	absolute_val(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

/* Sort two elements */
void	sort_two(t_list	**stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	if ((*stack)->content > (*stack)->next->content)
		swap_two_on_top(stack, "sa\n");
}

/* Sort three elements */
void	sort_three(t_list **stack)
{
	int	max_pos;

	assign_pos(stack);
	max_pos = find_max_indx(*stack);
	if (max_pos == 0)
		rotate_stack(stack, "ra\n");
	else if (max_pos == 1)
		reverse_rotate_stack(stack, "rra\n");
	if ((*stack)->content > (*stack)->next->content)
		swap_two_on_top(stack, "sa\n");
}

/* Pop on top of a stack */
t_list	*pop(t_list **stack)
{
	t_list	*popped_node;

	if (!stack || !*stack)
		return (NULL);
	popped_node = *stack;
	*stack = (*stack)->next;
	popped_node->next = NULL;
	return (popped_node);
}