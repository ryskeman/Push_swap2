/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:03:01 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/19 22:13:28 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	spand(size_t count, int found, const char *a, const char *s)
{
	while (*s)
	{
		while (*a)
		{
			if (*s == *a)
			{
				found = 1;
				break ;
			}
			a++;
		}
		if (found)
		{
			count++;
			s++;
		}
		else
			break ;
	}
}

size_t	ft_strspn(const char *s, const char *accept)
{
	int			found;
	const char	*a;
	size_t		count;

	found = 0;
	count = 0;
	a = accept;
	spand(count, found, a, s);
	return (count);
}
