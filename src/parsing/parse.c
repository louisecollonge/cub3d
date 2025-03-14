/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:24:20 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/14 19:28:17 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_data	*parse_args(int ac, char **av)
{
	int	file_len;
	int	extension_len;

	if (ac != 2)
		error("Wrong argument: retry with: ./cub3D map.cub", NULL, NULL, NULL);
	file_len = ft_strlen(av[1]); //map file path name
	extension_len = 4; //.cub
	if (file_len - extension_len <= 0
		|| ft_strncmp(av[1] + (file_len - extension_len), ".cub", 5))
		error("Wrong extension: must be .cub", NULL, NULL, NULL);
	return (parse_file(av[1]));
}

static bool	process_line(char *line, t_data *data, int count)
{
	int	i;
	int	len;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(line + i, "\n", 2) == 0) 
	{
		if (count < 7)
			return (false);
		else
			error("Empty line in map", data, line, NULL); //compteur qu'on incremente a chaque ligne non vide, jusqu'a la 7e qui est la 1ere ligne de la map: a partir de la, toute ligne vide est une erreur.
	}	
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
		parse_map(line, data);
	return (true);
}

/* static void	data_check(t_data *data)
{
	printf("%s\n", data->map_string); //debug
	if (data->ceiling_rgb == -1 || data->floor_rgb == -1)
		error("Missing color", data);
	// if (!data->no || !data->so || !data->we || !data->ea)
	// 	error("Missing texture", data);
	if (!data->map_string)
		error("No map", data);	
	if (wall_outline(data) == false)
		error("The outline of the map must be walls", data);
	if (data->character_nb != 1)
		error("No character in map", data);

	//todo pas d'espace vide dans le labyrinthe
} */

t_data	*parse_file(char *map)
{
	char	*line;
	t_data	*data;
	int		count;

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
	data->fd_map = open(map, O_RDONLY);
	if (data->fd_map < 0)
		error("Map file opening failure", data, NULL, NULL);
	count = 0;
	while (data->fd_map >= 0)
	{
		line = get_next_line(data->fd_map);
		if (!line)
			break ;
		if (process_line(line, data, count) == false)
			count++;
		free(line);
	}
	// data_check(data);
	close(data->fd_map);
	return (data);
}
