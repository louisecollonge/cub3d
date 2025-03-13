/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:24:20 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/13 17:57:32 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	parse_args(int ac, char **av)
{
	int	file_len;
	int	extension_len;

	if (ac != 2)
		error("Wrong argument: retry with: ./cub3D map.cub", -1);
	file_len = ft_strlen(av[1]); //map file path name
	extension_len = 4; //.cub
	if (file_len - extension_len <= 0
		|| ft_strncmp(av[1] + (file_len - extension_len), ".cub", 5))
		error("Wrong extension: must be .cub", -1);
}

static void	process_line(char *line, t_data *data)
{
	int	i;
	int	len;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(line + i, "\n", 2) == 0)
		return ;
	else if (ft_strncmp(line + i, "NO ", 3) == 0
		|| ft_strncmp(line + i, "SO ", 3) == 0
		|| ft_strncmp(line + i, "WE ", 3) == 0
		|| ft_strncmp(line + i, "EA ", 3) == 0)
	{
		len = ft_strlen(line);
		line[len - 1] = '\0';
		parse_texture(line + i + 3, data, NO);
	}
	else if (ft_strncmp(line + i, "F ", 2) == 0)
		parse_color(line + i + 2, data, FLOOR);
	else if (ft_strncmp(line + i, "C ", 2) == 0)
		parse_color(line + i + 2, data, CEILING);
	else
		parse_map(line + i, data);
}

static void	map_check(t_data *data)
{
	printf("%s\n", data->map_string); //debug
	if (data->character_nb != 1)
		error("No character in map", data->fd_map);
	// if (!data->no || !data->so || !data->we || !data->ea)
	// 	error("Missing texture", data->fd_map);
	if (data->ceiling_rgb == -1 || data->floor_rgb == -1)
		error("Missing color", data->fd_map);
	if (!data->map_string)
		error("No map", data->fd_map);
}

void	parse_file(char *map)
{
	char	*line;
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		error("Malloc failure", -1);
	data->character_nb = 0;
	data->map_string = NULL;
	data->ceiling = NULL;
	data->floor = NULL;
	data->ceiling_rgb = -1;
	data->floor_rgb = -1;
	data->fd_map = open(map, O_RDONLY);
	if (data->fd_map < 0)
		error("Map file opening failure", -1);
	while (data->fd_map >= 0)
	{
		line = get_next_line(data->fd_map);
		if (!line)
			break ;
		process_line(line, data);
		free(line);
	}
	map_check(data);
	close(data->fd_map);
}
