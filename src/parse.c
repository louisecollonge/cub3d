/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:24:20 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/10 15:15:49 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	check_extension(char *file)
{
	int	file_len;
	int	extension_len;

	file_len = ft_strlen(file);
	extension_len = 4;
	if (file_len - extension_len <= 0
		|| (ft_strncmp(file + (file_len - extension_len), ".cub", 5) != 0))
	{
		printf("Wrong extension\n");
		exit(EXIT_FAILURE);
	}	
}

void	parsing(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Argument error, retry with: ./cub3D map.cub\n");
		exit(EXIT_FAILURE);
	}	
	check_extension(av[1]);
}

void	parse_map(char *file, t_game *game)
{
	int		fd;
	char	*line;

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
		process_line(line); //todo
		free(line);
	}
	close(fd);
}
