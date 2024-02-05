/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:33:17 by lhaken            #+#    #+#             */
/*   Updated: 2024/02/05 15:04:46 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	read_char;
	char	*line;
	int		res_control;
	int		len;

	len = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *) malloc (sizeof(char) * (len));
	if (!line)
		return (NULL);

	res_control = read(fd, &read_char, 1);
	while (res_control > 0)
	{
		if (read_char == '\n')
			break ;
		line[len - 1] = read_char;
		len++;
		line = ft_realloc(line, len);
		res_control = read(fd, &read_char, 1);
	}
	line[len - 1] = '\0';
	return (line);
}
