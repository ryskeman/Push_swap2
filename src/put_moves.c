/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 23:50:19 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/28 12:04:53 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Put on top of the another stack*/
void	put_in_stack(t_list **stack, t_list *node, char *movement)
{
	if (!node)
		return ;
	ft_lstadd_front(stack, node);
	if (movement)
		ft_printf("%s", movement);
}