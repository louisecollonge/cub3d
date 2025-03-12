/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:24:20 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/12 17:51:46 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	check_extension(char *file)
{
	int	file_len;
	int	extension_len;

	file_len = ft_strlen(file);
	extension_len = 4; //.cub
	if (file_len - extension_len <= 0
		|| ft_strncmp(file + (file_len - extension_len), ".cub", 5))
	{
		printf(RED "Wrong extension\n" RESET);
		exit(EXIT_FAILURE);
	}	
}

void	parse_args(int ac, char **av)
{
	if (ac != 2)
	{
		printf(RED "Argument error, retry with: ./cub3D map.cub\n" RESET);
		exit(EXIT_FAILURE);
	}	
	check_extension(av[1]);
}

static void	process_line(char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(line + i, "\n", 2) == 0)
		return ;
	else if (ft_strncmp(line + i, "NO ", 3) == 0)
		parse_north_texture(line + i + 3);
	else if (ft_strncmp(line + i, "SO ", 3) == 0)
		parse_south_texture(line + i + 3);
	else if (ft_strncmp(line + i, "WE ", 3) == 0)
		parse_west_texture(line + i + 3);
	else if (ft_strncmp(line + i, "EA ", 3) == 0)
		parse_east_texture(line + i + 3);
	else if (ft_strncmp(line + i, "F ", 2) == 0)
		parse_color(line + i + 2, fd, FLOOR);
	else if (ft_strncmp(line + i, "C ", 2) == 0)
		parse_color(line + i + 2, fd, CEILING);
	else
		parse_map(line + i);
}

void	parse_file(char *file, t_game *game)
{
	int		fd;
	char	*line;
	(void)file; //debug
	(void)game; //debug
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("File error\n");
		exit (EXIT_FAILURE);
	}
	while (fd >= 0)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		process_line(line, fd);
		free(line);
	}
	close(fd);
}
