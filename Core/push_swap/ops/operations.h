/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:45:03 by lhaken            #+#    #+#             */
/*   Updated: 2024/10/17 15:45:04 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

/* INCLUDES */
# include "../pushswap.h"

/* WRITE OP */
void	write_op(char *op, char let);
/* SA and SB*/
void	op_swap(t_stack **stack, char let);
/* SS */
void	op_swap_both(t_stack **stack_a, t_stack **stack_b);
/* PA and PB*/
void	op_push(t_stack **src, t_stack **dest, char let);
/* RA and RB*/
void	op_rotate(t_stack **stack, char let);
/* RR */
void	op_rotate_both(t_stack **stack_a, t_stack **stack_b);
/* RRA and RRB */
void	op_rev_rotate(t_stack **stack, char let);
/* RRR */
void	op_rev_rotate_both(t_stack **stack_a, t_stack **stack_b);

#endif
