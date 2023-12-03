#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* INCLUDES */
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/* PRINTF */
int	ft_printf(const char *, ...);

/* FORMATTING */
void	ft_putchar(char c, int *cnt);
void	ft_putstr(char *s, int *cnt);
void	ft_putnbr(int n, int *cnt);
void	ft_putunbr(unsigned int n, int *cnt);
void	ft_puthex(unsigned int n, char *base, int *cnt);
void	ft_putptr(void *ptr, int *cnt);

/* HELPER */
size_t	ft_strlen(const char *s);

#endif
