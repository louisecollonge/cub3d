/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:11:55 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/13 10:57:00 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int	get_rgb(char *option, int fd_map)
{
	int		i;
	int		r;
	int		g;
	int		b;

	i = 0;
	r = ft_atoi(option);
	while (option[i] && option[i] != ',')
		i++;
	g = ft_atoi(&option[i + 1]);
	while (option[i])
		i++;
	b = ft_atoi(&option[i + 1]);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		error("Wrong color", fd_map);
	return ((r << 16) | (g << 8) | b);
}

static char	*parse_color_helper(t_tex *textures, char *line, int *i,
	t_option option)
{
	int	start;

	if (option == CEILING)
	{
		start = *i;
		while (line[*i])
			(*i)++;
		textures->ceiling = ft_substr(line, start, *i - 1);
		if (!textures->ceiling)
			return ("Malloc error");
		textures->ceiling_rgb = get_rgb(textures->ceiling, textures->fd_map);
		printf(YELLOW "Ceiling color : %s. RGB = %#08x.\n" RESET, textures->ceiling, textures->ceiling_rgb); //debug
	}
	else if (option == FLOOR)
	{
		start = *i;
		while (line[*i])
			(*i)++;
		textures->floor = ft_substr(line, start, *i - 1);
		if (!textures->floor)
			return ("Malloc error");
		textures->floor_rgb = get_rgb(textures->floor, textures->fd_map);
		printf(YELLOW "Floor color : %s. RGB = %#08x.\n" RESET, textures->floor, textures->floor_rgb); //debug
	}
	return (NULL);
}

static void	color_error(int fd_map, t_option option)
{
	if (option == FLOOR)
		printf(RED "Wrong floor color\n" RESET);
	else if (option == CEILING)
		printf(RED "Wrong ceiling color\n" RESET);
	close(fd_map);
	exit(EXIT_FAILURE);
}

void	parse_color(char *line, t_tex *textures, t_option option)
{
	int		i;
	char	*failure;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ',')
		{
			line = &line[i + 1];
			i = 0;
		}
		else
		{
			if (!(ft_isdigit(line[i]) || line[i] == ','))
				color_error(textures->fd_map, option);
			else
			{
				failure = parse_color_helper(textures, line, &i, option);
				if (failure)
					error(failure, textures->fd_map);
			}
		}
		i++;
	}
}
