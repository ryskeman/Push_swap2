/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernafer <fernafer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:52:07 by fernafer          #+#    #+#             */
/*   Updated: 2025/11/24 23:05:17 by fernafer         ###   ########.fr       */
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

/* move_executor.c */

/* put_moves.c */

/* rotate_moves.c */

/* sort_process_utils.c */

/* sort_process.c */

/* sort_utils.c */

/* swap_moves.c */

/* target_in_a_finder.c */

#endif