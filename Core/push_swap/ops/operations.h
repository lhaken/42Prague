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

/* SA and SB*/
void	op_swap(t_stack **stack);
/* SS */
void	op_swap_both(t_stack **stack_a, t_stack **stack_b);
/* PA and PB*/
void	op_push(t_stack **src, t_stack **dest);
/* RA and RB*/
void	op_rotate(t_stack **stack);
/* RR */
void	op_rotate_both(t_stack **stack_a, t_stack **stack_b);
/* RRA and RRB */
void	op_rev_rotate(t_stack **stack);
/* RRR */
void	op_rev_rotate_both(t_stack **stack_a, t_stack **stack_b);

#endif
