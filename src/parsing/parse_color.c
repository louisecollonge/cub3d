/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:11:55 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/12 18:52:45 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int	get_rgb(t_tex *textures, char *option, t_color OPT)
{
	int		i;
	int		r;
	int		g;
	int		b;
	(void)OPT;
	(void)textures;
	
	i = 0;
	r = ft_atoi(option);
	while (option[i] && option[i] != ',')
		i++;
	g = ft_atoi(&option[i + 1]);
	while (option[i])
		i++;
	b = ft_atoi(&option[i + 1]);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		error("Wrong color");
	
	// // debug
	// printf("%s : r : %d, g : %d, b : %d\n", option, r, g, b);
	return ((r << 16) | (g << 8) | b);
}

static void	parse_color_helper(t_tex *textures, char *line, int *i, t_color color)
{
	int	start;

	if (color == CEILING)
	{
		start = *i;
		while (line[*i])
			(*i)++;
		textures->ceiling = ft_substr(line, start, *i - 1);
		if (!textures->ceiling)
			error("Malloc error");
		
		textures->ceiling_rgb = get_rgb(textures, textures->ceiling, CEILING);
		printf("Ceiling color : %s. RGB = %d\n", textures->ceiling, textures->ceiling_rgb); //debug
	}
	else if (color == FLOOR)
	{
		start = *i;
		while (line[*i])
			(*i)++;
		textures->floor = ft_substr(line, start, *i - 1);
		if (!textures->floor)
			error("Malloc error");
		
		textures->floor_rgb = get_rgb(textures, textures->floor, FLOOR);
		printf("Floor color : %s. RGB = %d\n", textures->floor, textures->floor_rgb); //debug
	}
}

static void	color_error(int file_fd, t_color color)
{
	if (color == FLOOR)
		printf(RED "Wrong floor color\n" RESET);
	else if (color == CEILING)
		printf(RED "Wrong ceiling color\n" RESET);
	close(file_fd);
	exit(EXIT_FAILURE);
}

void	parse_color(char *line, int file_fd, t_color color)
{
	t_tex	*textures;
	int		i;

	textures = malloc(sizeof(t_tex));
	if (!textures)
		error("Malloc error");
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
				color_error(file_fd, color);
			else
				parse_color_helper(textures, line, &i, color);
		}
		i++;
	}
}
