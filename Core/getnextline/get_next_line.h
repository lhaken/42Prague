/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:37:28 by lhaken            #+#    #+#             */
/*   Updated: 2024/02/05 14:15:49 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* INCLUDES */
# include <stdlib.h>
# include <unistd.h>

/* GNL */
char	*get_next_line(int fd);

/* UTILS */
void	*ft_modmemcpy(void *dest, const void *src, size_t len);
void	*ft_realloc(void *ptr, size_t size);

#endif
