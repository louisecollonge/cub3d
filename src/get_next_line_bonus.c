/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:03:07 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/19 17:04:46 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	find_newline(char *remainder)
{
	int	i;

	i = 0;
	if (remainder)
	{
		while (remainder[i])
		{
			if (remainder[i] == '\n')
				return (i);
			i++;
		}
	}
	return (-1);
}

static char	*extract_line(char *remainder)
{
	char	*line;
	int		newline_index;

	newline_index = find_newline(remainder);
	if (newline_index >= 0)
	{
		line = malloc(newline_index + 2);
		if (!line)
			return (NULL);
		ft_strlcpy2(line, remainder, newline_index + 2);
	}
	else
	{
		line = malloc(ft_strlen2(remainder) + 1);
		if (!line)
			return (NULL);
		ft_strlcpy2(line, remainder, ft_strlen2(remainder) + 1);
	}
	return (line);
}

static char	*update_remainder(char **remainder)
{
	char	*new_remainder;
	int		newline_index;
	size_t	len_nl;

	if (!remainder || !*remainder)
		return (NULL);
	newline_index = find_newline(*remainder);
	len_nl = ft_strlen2(*remainder) - newline_index;
	if (newline_index >= 0)
	{
		if ((*remainder)[newline_index + 1] != '\0')
		{
			new_remainder = malloc(len_nl);
			if (!new_remainder)
				return (NULL);
			ft_strlcpy2(new_remainder, *remainder + newline_index + 1, len_nl);
		}
		else
			new_remainder = NULL;
	}
	else
		new_remainder = NULL;
	free(*remainder);
	*remainder = new_remainder;
	return (*remainder);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	str = malloc((ft_strlen2(s1) + ft_strlen2(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy2(str, s1, ft_strlen2(s1) + 1);
	ft_strlcpy2(str + ft_strlen2(s1), s2, ft_strlen2(s2) + 1);
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*remainders[1024];
	ssize_t		b;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	b = read(fd, buffer, BUFFER_SIZE);
	while (b > 0)
	{
		buffer[b] = '\0';
		remainders[fd] = ft_strjoin_gnl(remainders[fd], buffer);
		if (find_newline(remainders[fd]) >= 0)
			break ;
		b = read(fd, buffer, BUFFER_SIZE);
	}
	if (b < 0 || (b == 0 && (!remainders[fd] || !*remainders[fd])))
		return (free_mem(&remainders[fd], &buffer));
	line = extract_line(remainders[fd]);
	update_remainder(&remainders[fd]);
	return (free(buffer), line);
}
