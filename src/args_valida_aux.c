/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_valida_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:09:06 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/24 23:25:47 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Validates if a string is empty... */
int	is_string_empty(char *s)
{
	if (!s)
		return (1);
	while (*s)
	{
		if (!((*s >= 9 && *s <= 13) || *s == 32))
			return (0);
		s++;
	}
	return (1);
}

/* Free stack and matrix */
void	ft_free_stack(t_list **a, t_list **b, char **matrix)
{
	int	i;

	i = 0;
	if (matrix && matrix[i])
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
	if (a && *a)
		ft_lstclear(a);
	if (b && *b)
		ft_lstclear(b);
}
