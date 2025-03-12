/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_F_C.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:11:55 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/12 17:43:30 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	parse_color_helper(t_tex *textures, char *line, int *i, t_color color)
{
	int	start;

	if (color == CEILING)
	{
		start = *i;
		while (line[*i])
			(*i)++;
		textures->ceiling = ft_substr(line, start, *i - 1);
		printf("Ceiling color : %s\n", textures->ceiling); //debug
	}
	else if (color == FLOOR)
	{
		start = *i;
		while (line[*i])
			(*i)++;
		textures->floor = ft_substr(line, start, *i - 1);
		printf("Floor color : %s\n", textures->floor); //debug
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
