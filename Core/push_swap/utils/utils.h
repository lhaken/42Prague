/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:48:43 by lhaken            #+#    #+#             */
/*   Updated: 2024/10/17 15:49:11 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* INCLUDES */
# include "../pushswap.h"

/* LIB */
int		ft_atoi(const char *nptr);
void	ft_swap(int *a, int *b);
char	**ft_split(char const *s, char c);

/* STRUCT MANAGEMENT */
t_stack	*create_node(int data);
void	move_node(t_stack **stack, int data);
void	init_stack(t_stack **stack, char **argv, int idx);
void	free_stack(t_stack **stack);

/* ERROR */
int		check_dup(int argc, char **argv);
int		is_valid(char *str);
int		check_valid(int argc, char **argv);
void	check_error(int argc, char **argv);

/* UTILS */
void	print_stack(t_stack **stack);
int		get_stack_size(t_stack **stack);
int		check_sort(t_stack *stack);
int		get_last(t_stack *stack);
void	check_last(t_stack **stack, int low, int size);
int		get_lowest(t_stack *stack);
void	push_lowest(t_stack **stack_a, t_stack **stack_b, int size);
void	worst_case(t_stack **stack_a, t_stack **stack_b);
int		*listize(t_stack *stack_a, int size);
void	move_chunks(t_stack **stack_a, t_stack **stack_b, int mid, int idx);
int		push_back(t_stack **stack_a, t_stack **stack_b, int *list, int size);

#endif
