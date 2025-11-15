/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:52:09 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/15 23:17:14 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Print stack */
void    ft_print_stack(t_list *stack)
{
    while (stack)
    {
        ft_printf("%d\n", stack->content);
        stack = stack->next;
    }
}

/* Vaidate if stack is sorted */
int stack_sorted(t_list *stack)
{
    while (stack && stack->next)
    {
        if(stack->content > stack->next->content)
            return (0);
        stack = stack->next;
    }
    return (1);
}

/* Main */
int main(int ac, char **av)
{
    char    **numbers;
    char    *joined;
    t_list  *stack_a;
    t_list  *stack_b;

    numbers = NULL;
    stack_a = NULL;
    stack_b = NULL;
    if (ac < 2)
        ft_free_exit(numbers, &stack_a);
    //join_args(av, &joined); Join Arguments function.
    if (!joined || ft_strlen(joined) == 0 || ft_strspn(joined,
            "\t\n\r\f\v") == ft_strlen(joined))
        ft_free_exit(numbers, &stack_a);
    numbers = ft_split(joined, ' ');
    if (!numbers)
        ft_free_exit(numbers, &stack_a);
    //if (!fill stack_a)
        ft_free_exit(numbers, &stack_a);
    if (stack_sorted(stack_a))
        exit(EXIT_SUCCESS);
    // sort(&stack_a, &stack_b);
    free(joined);
    // Free stacks and matrix(&stack_a, &stack_b, numbers);
    return (0);
}
