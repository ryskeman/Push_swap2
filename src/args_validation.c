/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:20:25 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/25 00:17:01 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Validate if number only accept one sign */
int	is_valid_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/* Validate if number already exist */
int	exist_num_stack(int num, t_list *stack)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/* Fill up the stack_a */
int	fill_up_stack_a(t_list **stack, char **matrix)
{
	int		i;
	long	l_num;
	t_list	*new_node;

	i = 0;
	while (matrix[i])
	{
		if (!is_valid_num(matrix[i]))
			return (0);
		l_num = ft_atoi(matrix[i]);
		if (l_num < INT_MIN || l_num >= INT_MAX)
			return (0);
		if (exist_num_stack(l_num, *stack))
			return (0);
		new_node = ft_lstnew(l_num);
		ft_lstadd_back(stack, new_node);
		i++;
	}
	return (1);
}

/* Free matrix and exit */
void	ft_free_exit(char **matrix, t_list **stack)
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
	if (stack && *stack)
		ft_lstclear(stack);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

/* Take args and join it into a single string */
void	join_args(char **args, char **joined)
{
	char	*tmp;
	int		i;

	i = 1;
	*joined = NULL;
	while (args[i])
	{
		if (!joined)
			*joined = ft_strdup(args[i]);
		else
		{
			if (is_string_empty(args[i]))
			{
				free(*joined);
				joined = NULL;
				break ;
			}
			tmp = ft_strjoin(*joined, " ");
			free(*joined);
			*joined = ft_strjoin(tmp, args[i]);
			free (tmp);
		}
		i++;
	}
}
