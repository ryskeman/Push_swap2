/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_valida_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:09:06 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/19 22:11:29 by fernafer         ###   ########.fr       */
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
