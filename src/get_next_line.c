/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:56:43 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/13 10:53:31 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer == NULL)
		buffer = ft_calloc(1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	buffer = read_file(buffer, fd);
	if (!buffer || *buffer == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_get_line(buffer);
	buffer = remain(buffer);
	return (line);
}

char	*read_file(char *big_buf, int fd)
{
	char	*small_buf;
	int		cursor;

	small_buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!small_buf)
		return (free(big_buf), NULL);
	while (!ft_strchr(big_buf, '\n'))
	{
		cursor = read(fd, small_buf, BUFFER_SIZE);
		if (cursor <= 0)
		{
			free(small_buf);
			if (cursor == 0)
				return (big_buf);
			free(big_buf);
			return (NULL);
		}
		small_buf[cursor] = '\0';
		big_buf = add_buff(big_buf, small_buf);
		if (!big_buf)
			return (free(small_buf), NULL);
	}
	free(small_buf);
	return (big_buf);
}

char	*add_buff(char *big, char *small)
{
	char	*added;

	added = ft_strjoin(big, small);
	if (!added)
	{
		free(big);
		return (NULL);
	}
	free(big);
	return (added);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	ft_strncpy(line, str, i);
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*remain(char *str)
{
	char	*remain;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	i++;
	remain = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	if (!remain)
	{
		free(str);
		return (NULL);
	}
	while (str[i])
		remain[j++] = str[i++];
	remain[j] = '\0';
	free(str);
	return (remain);
}
