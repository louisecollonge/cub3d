/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:24:20 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/20 17:16:13 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_data	*parse_args(int ac, char **av)
{
	int	file_len;
	int	extension_len;

	if (ac != 2)
		error("Wrong argument: retry with: ./cub3D map.cub", NULL, NULL, NULL);
	file_len = ft_strlen(av[1]);
	extension_len = 4;
	if (file_len - extension_len <= 0
		|| ft_strncmp(av[1] + (file_len - extension_len), ".cub", 5))
		error("Wrong extension: must be .cub", NULL, NULL, NULL);
	return (parse_file(av[1]));
}

static void	process_line(t_data *data, int *count)
{
	int	i;

	i = 0;
	while (data->line[i] == ' ' || data->line[i] == '\t')
		i++;
	if (ft_strncmp(data->line + i, "\n", 2) == 0)
	{
		if (*count < 7)
			return ;
		else if (data->in_map == 1)
			data->in_map = 2;
	}
	else if (is_orientation(data->line + i))
		parse_texture(data->line + i + 3, data, get_opt(data->line + i), count);
	else if (ft_strncmp(data->line + i, "F ", 2) == 0)
		parse_color(data->line + i + 2, data, FLOOR, count);
	else if (ft_strncmp(data->line + i, "C ", 2) == 0)
		parse_color(data->line + i + 2, data, CEILING, count);
	else if (end_of_map(data) == true)
		parse_map_line(data, count);
	return ;
}

static void	data_check(t_data *data)
{
	if (data->ceiling_rgb == -1 && data->floor_rgb == -1
		&& !data->no && !data->so && !data->we && !data->ea
		&& !data->map_string)
		error("Missing textures, colors and/or map", data, NULL, NULL);
	else if (data->ceiling_rgb == -1 || data->floor_rgb == -1)
		error("Missing color", data, NULL, NULL);
	else if (!data->no || !data->so || !data->we || !data->ea)
		error("Missing texture", data, NULL, NULL);
	else if (!data->map_string)
		error("Doesn't follow rule of description then map", data, NULL, NULL);
	else if (data->character_nb != 1)
		error("No character in map", data, NULL, NULL);
	else if (wall_outline(data) == false)
		error("The outline of the map must be walls", data, NULL, NULL);
}

static t_data	*data_init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		error("Malloc failure", NULL, NULL, NULL);
	data->character_nb = 0;
	data->map_string = NULL;
	data->map_tab = NULL;
	data->ceiling = NULL;
	data->floor = NULL;
	data->ceiling_rgb = -1;
	data->floor_rgb = -1;
	data->in_map = 0;
	data->line = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	return (data);
}

t_data	*parse_file(char *map)
{
	t_data	*data;
	int		count;

	data = data_init();
	data->fd_map = open(map, O_RDONLY);
	if (data->fd_map < 0)
		error("Map file opening failure", data, NULL, NULL);
	count = 0;
	while (data->fd_map >= 0)
	{
		data->line = get_next_line(data->fd_map);
		if (!data->line)
			break ;
		process_line(data, &count);
		free(data->line);
	}
	data_check(data);
	close(data->fd_map);
	return (data);
}
