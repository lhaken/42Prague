/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:30:23 by lhaken            #+#    #+#             */
/*   Updated: 2024/02/01 21:33:31 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle(va_list vars, char *format, size_t *cnt)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(vars, int), cnt));
	else if (*format == 's')
		return (ft_putstr(va_arg(vars, char *), cnt));
	else if (*format == 'p')
		return (ft_putptr(va_arg(vars, void *), cnt));
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr(va_arg(vars, int), cnt));
	else if (*format == 'u')
		return (ft_putunbr(va_arg(vars, unsigned int), cnt));
	else if (*format == 'x' || *format == 'X')
	{
		if (*format == 'x')
		{
			return (ft_puthex(va_arg(vars, unsigned int),
					"0123456789abcdef", cnt));
		}
		else
		{
			return (ft_puthex(va_arg(vars, unsigned int),
					"0123456789ABCDEF", cnt));
		}
	}
	else if (*format == '%')
		return (ft_putchar(*format, cnt));
}

int	ft_printf(const char *format, ...)
{
	va_list	vars;
	size_t	cnt;

	cnt = 0;
	if (!format)
		return (0);
	va_start(vars, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
			ft_handle(vars, (char *) format, &cnt);
		}
		else
			ft_putchar(*format, &cnt);
		format++;
	}
	va_end(vars);
	return (cnt);
}
