/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:33:26 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/17 15:12:11 by lcollong         ###   ########.fr       */
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
		if (!data->map_string)
			error("Malloc failure", data, line, NULL);
		return ;
	}
	else
	{
		tmp = ft_strjoin(data->map_string, line);
		if (!tmp)
			error("Malloc failure", data, line, NULL);
		free(data->map_string);
		data->map_string = ft_strdup(tmp);
		if (!data->map_string)
			error("Malloc failure", data, line, tmp);
		free(tmp);
	}
}

void	parse_map_line(char *line, t_data *data, int *count)
{
	int			i;

	i = 0;
	(*count)++;
	if (data->in_map == 0)
		data->in_map = 1;
	else if (data->in_map == 2)
		error("Empty line in map", data, line, NULL);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E')
			error("Wrong character in map", data, line, NULL);
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
			data->character_nb++;
		if (data->character_nb > 1)
			error("Too many characters in map", data, line, NULL);
		i++;
	}
	realloc_line(data, line);
}
