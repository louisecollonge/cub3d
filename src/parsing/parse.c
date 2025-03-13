/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:24:20 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/13 10:24:03 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	parse_args(int ac, char **av)
{
	int	file_len;
	int	extension_len;
	
	if (ac != 2)
		error("Argument error, retry with: ./cub3D map.cub");
	file_len = ft_strlen(av[1]); //map file path name
	extension_len = 4; //.cub
	if (file_len - extension_len <= 0
		|| ft_strncmp(av[1] + (file_len - extension_len), ".cub", 5))
		error("Wrong extension");
}

static void	process_line(char *line, int fd_map, t_tex *textures)
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
		// parse_texture(line + i + 3, textures, NO);
	}
	else if (ft_strncmp(line + i, "F ", 2) == 0)
		parse_color(line + i + 2, fd_map, textures, FLOOR);
	else if (ft_strncmp(line + i, "C ", 2) == 0)
		parse_color(line + i + 2, fd_map, textures, CEILING);
	else
		parse_map(line + i);
}

void	parse_file(char *map)
{
	int		fd_map;
	char	*line;
	t_tex	*textures;
	
	textures = malloc(sizeof(t_tex));
	if (!textures)
		error("Malloc error");
	fd_map = open(map, O_RDONLY);
	if (fd_map < 0)
		error("Map file error");
	while (fd_map >= 0)
	{
		line = get_next_line(fd_map);
		if (!line)
			break ;
		process_line(line, fd_map, textures);
		free(line);
	}
	close(fd_map);
}
