/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:59:54 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/29 01:29:03 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Find cheapest movement */
t_list	*find_lowest_cost(t_list *stack)
{
	t_list	*cheap;
	int		min_cost;
	int		cost_a;
	int		cost_b;
	int		total;

	cheap = stack;
	min_cost = INT_MAX;
	while (stack)
	{
		cost_a = stack->cost_a;
		cost_b = stack->cost_b;
		if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
			total = maximum(absolute_val(cost_a), absolute_val(cost_b));
		else
			total = absolute_val(cost_a) + absolute_val(cost_b);
		if (total < min_cost)
		{
			min_cost = total;
			cheap = stack;
		}
		stack = stack->next;
	}
	return (cheap);
}

/* Find min value */
int	find_min_index(t_list *node)
{
	int		min;
	int		indx;
	t_list	*tmp;

	tmp = node;
	min = tmp->content;
	indx = 0;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			indx = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (indx);
}

/* Find max index */
int	find_max_indx(t_list *node)
{
	int		min;
	int		indx;
	t_list	*tmp;

	tmp = node;
	min = tmp->content;
	indx = 0;
	while (tmp)
	{
		if (tmp->content > min)
		{
			min = tmp->content;
			indx = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (indx);
}

/* Assing the element position */
void	assign_pos(t_list **stack)
{
	int		i;
	t_list	*head;

	i = 0;
	head = *stack;
	while (head)
	{
		head->pos = i;
		head = head->next;
		i++;
	}
}

/* Find cost of moves */
void	find_cost_aux(char from, t_list *head, int first_size, int second_size)
{
	if (from == 'a')
	{
		if (head->pos <= first_size / 2)
			head->cost_a = head->pos;
		else
			head->cost_a = (first_size - head->pos) * -1;
		if (head->target_pos <= second_size / 2)
			head->cost_b = head->target_pos;
		else
			head->cost_b = (second_size - head->target_pos) * -1;
	}
	else
	{
		if (head->pos <= first_size / 2)
			head->cost_b = head->pos;
		else
			head->cost_b = (first_size - head->pos) * -1;
		if (head->target_pos <= second_size / 2)
			head->cost_a = head->target_pos;
		else
			head->cost_a = (second_size - head->target_pos) * -1;
	}
}
