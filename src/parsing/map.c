/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:33:26 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/20 16:58:02 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static char	*delete_end_spaces(char *line)
{
	int		i;

	i = ft_strlen(line) - 1;
	while (acceptable_char(line[i]) == false)
		line[i--] = '\0';
	line[i + 1] = '\n';
	return (line);
}

static void	realloc_line(t_data *data, char *line)
{
	char	*tmp;

	tmp = NULL;
	line = delete_end_spaces(line);
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

void	parse_map_line(t_data *data, int *count)
{
	int			i;

	i = 0;
	(*count)++;
	if (data->in_map == 0)
		data->in_map = 1;
	else if (data->in_map == 2)
		error("Empty line(s) in map", data, NULL, NULL);
	while (data->line[i])
	{
		if (data->line[i] == '\t')
			error("Replace tabs with spaces for correct alignment", data, NULL, NULL);
		if (data->line[i] != ' ' && data->line[i] != '\n'
			&& data->line[i] != '1' && data->line[i] != '0' && data->line[i] != 'N'
			&& data->line[i] != 'S' && data->line[i] != 'W' && data->line[i] != 'E')
				error("Wrong character in map", data, NULL, NULL);
		if (data->line[i] == 'N' || data->line[i] == 'S'
			|| data->line[i] == 'W' || data->line[i] == 'E')
			data->character_nb++;
		if (data->character_nb > 1)
			error("Too many characters in map", data, NULL, NULL);
		i++;
	}
	realloc_line(data, data->line);
}
