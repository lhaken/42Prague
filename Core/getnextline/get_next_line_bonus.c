/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:33:17 by lhaken            #+#    #+#             */
/*   Updated: 2024/02/09 16:19:27 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *buff)
{
	char	*res;
	int		idx;

	idx = 0;
	if (!*buff)
		return (NULL);
	while (buff[idx] != '\n' && buff[idx] != '\0')
		idx++;
	if (buff[idx] == '\n')
		idx++;
	res = (char *)ft_calloc(idx + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (idx > 0)
	{
		idx--;
		res[idx] = buff[idx];
	}
	return (res);
}

char	*delete_line(char *buff)
{
	char	*eo_first_line;

	eo_first_line = ft_strchr(buff, '\n');
	if (eo_first_line == NULL)
	{
		free(buff);
		return (NULL);
	}
	else
	{
		eo_first_line = ft_strjoin(eo_first_line + 1, "");
		free(buff);
		return (eo_first_line);
	}
}

char	*read_fd(char *buff, int fd)
{
	int		read_len;
	char	*chunk;
	char	*used;

	read_len = 42;
	chunk = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!chunk)
		return (NULL);
	while (read_len != 0 && ft_strchr(buff, '\n') == NULL)
	{
		read_len = read(fd, chunk, BUFFER_SIZE);
		if (read_len < 0)
		{
			free(chunk);
			return (NULL);
		}
		chunk[read_len] = '\0';
		used = buff;
		if (used == NULL)
			used = (char *)ft_calloc(1, sizeof(char));
		buff = ft_strjoin(used, chunk);
		free(used);
	}
	free(chunk);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_fd(buff, fd);
	if (!buff)
		return (NULL);
	line = read_line(buff);
	buff = delete_line(buff);
	return (line);
}
