/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:35:18 by lhaken            #+#    #+#             */
/*   Updated: 2024/02/01 21:41:59 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* INCLUDES */
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/* PRINTF */
int		ft_printf(const char *format, ...);

/* FORMATTING */
void	ft_putchar(char c, size_t *cnt);
void	ft_putstr(char *s, size_t *cnt);
void	ft_putnbr(int n, size_t *cnt);
void	ft_putunbr(unsigned int n, size_t *cnt);
void	ft_puthex(unsigned int n, char *base, size_t *cnt);
void	ft_putptr(void *ptr, size_t *cnt);

/* HELPER */
size_t	ft_strlen(const char *s);

#endif
