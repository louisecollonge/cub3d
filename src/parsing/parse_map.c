/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:33:26 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/13 18:01:12 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	realloc_line(t_data *data, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (!data->map_string)
	{
		data->map_string = ft_strdup(line);
		return ;
	}
	else
	{
		tmp = malloc(ft_strlen(data->map_string) + ft_strlen(line) + 1);
		if (!tmp)
			error("Malloc failure", data->fd_map);
		tmp = ft_strjoin(data->map_string, line);
		if (!tmp)
			error("Malloc failure", data->fd_map);
		free(data->map_string);
		data->map_string = ft_strdup(tmp);
		if (!data->map_string)
		{
			free(tmp);
			error("Malloc failure", data->fd_map);
		}
		free(tmp);
	}
}

void	parse_map(char *line, t_data *data)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E')
			error("Wrong character in map", data->fd_map);
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
			data->character_nb++;
		if (data->character_nb > 1)
			error("Too many characters in map", data->fd_map);
		i++;
	}
	realloc_line(data, line);
}
