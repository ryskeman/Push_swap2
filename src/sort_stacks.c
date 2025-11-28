/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:37:47 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/28 12:48:50 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sorting main function */
void	sort(t_list	**a, t_list	**b)
{
	if (ft_lstsize(*a) < 4)
	{
		if (ft_lstsize(*a) == 3)
			sort_three(a);
		else
			sort_two(a);
	}
	else
	{
		while (ft_lstsize(*a) > 3 && ft_lstsize(*b) < 2)
			put_in_stack(b, pop_stack(a), "pb\n");
		while (ft_lstsize(*a) > 3)
			put_a_to_b(a, b);
		sort_three(a);
		while (*b)
			put_b_to_a(b, a);
		assign_pos(a);
		min_on_top(a);
	}
}

/* Processing A to B */
void	put_a_to_b(t_list **a, t_list **b)
{
	put_in_stack(b, pop_stack(a), "pb\n");
}

/* Processing B ordered to A */
void	put_b_to_a(t_list **b, t_list **a)
{
	assign_pos(a);
	assign_pos(b);
	calculate_target(b, *a, 'b');
	find_cost(b, ft_lstsize(*b), ft_lstsize(*a), 'b');
	exec_movements(b, a, find_lowest_cost(*b), 'b');
	put_in_stack(a, pop_stack(b), "pa\n");
}

/* Put minimun value on top */
void	min_on_top(t_list **a)
{
	int	min_indx;
	int	size;
	int	i;

	min_indx = find_min_index(*a);
	size = ft_lstsize(*a);
	if (min_indx <= size / 2)
		while (min_indx-- > 0)
			rotate_stack(a, "ra\n");
	else
	{
		i = size - min_indx;
		while (i-- > 0)
			reverse_rotate_stack(a, "rra\n");
	}
}

/* Calculate cost of movements */
void	find_cost(t_list **node, int first_size, int second_size, char from)
{
	t_list	*head;

	head = *node;
	while (head)
	{
		find_cost_aux(from, head, first_size, second_size);
		head = head->next;
	}
}
