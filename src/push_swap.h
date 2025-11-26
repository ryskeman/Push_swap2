/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:52:07 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/27 00:25:42 by fernafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

/* args_validation.c */
int		is_valid_num(char *s);
int		exist_num_stack(int num, t_list *stack);
int		fill_up_stack_a(t_list **stack, char **matrix);
void	ft_free_exit(char **matrix, t_list **stack);
void	join_args(char **args, char **joined);

/* arg_valida_aux.c */
int		is_string_empty(char *s);
void	ft_free_stack(t_list **a, t_list **b, char **matrix);

/* main.c */
void	ft_print_stack(t_list *stack);
int		stack_sorted(t_list *stack);
int		main(int ac, char **av);

/* movements.c */

/* put_moves.c */
void	put_in_stack(t_list **stack, t_list **node, char *movement);

/* rotate_moves.c */
void	rotate_stack(t_list	**stack, char *movement);
void	rotate_two_stacks(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_stack(t_list	**stack, char *movement);
void	same_reverse_rotate(t_list **stack_a, t_list **stack_b);

/* sort_stacks_utils.c */
int		maximum(int a, int b);
int		absolute_val(int num);
void	sort_two(t_list	**stack);
void	sort_three(t_list **stack);
t_list	*pop(t_list **stack);

/* sort_stacks.c */
void	sort(t_list	**a, t_list	**b);
void	put_a_to_b(t_list **a, t_list **b);
void	put_b_to_a(t_list **b, t_list **a);
void	min_on_top();
void	find_cost(t_list **node, int first_size, int second_size, char from);

/* sort_utils.c */

/* swap_moves.c */
void	swap_two_on_top(t_list **stack, char *movement);
void	swap_at_same(t_list **stack_a, t_list **stack_b);

/* target_in_a_finder.c */

#endif