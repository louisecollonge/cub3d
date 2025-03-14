/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:33:26 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/14 19:29:36 by lcollong         ###   ########.fr       */
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

void	parse_map(char *line, t_data *data)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E')
			error("Wrong character in map", data, NULL, NULL);
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
			data->character_nb++;
		if (data->character_nb > 1)
			error("Too many characters in map", data, NULL, NULL);
		i++;
	}
	realloc_line(data, line);
}
