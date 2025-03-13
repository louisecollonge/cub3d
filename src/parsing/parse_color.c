/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:11:55 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/13 17:34:58 by lcollong         ###   ########.fr       */
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
	i++;
	while (option[i] && option[i] != ',')
		i++;
	b = ft_atoi(&option[i + 1]);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		error("Wrong color", fd_map);
	return ((r << 16) | (g << 8) | b);
}

static char	*parse_color_helper(t_data *data, char *line, t_option option)
{
	int	start;
	int	i;

	i = 0;
	if (option == CEILING)
	{
		start = i;
		while (line[i])
			(i)++;
		data->ceiling = ft_substr(line, start, i - 1);
		if (!data->ceiling)
			return ("Malloc failure");
		// printf("ceiling: <%s>\n", data->ceiling); //debug
		data->ceiling_rgb = get_rgb(data->ceiling, data->fd_map);
		printf(YELLOW "Ceiling color : %s. RGB = %#08x.\n" RESET, data->ceiling, data->ceiling_rgb); //debug
	}
	else if (option == FLOOR)
	{
		start = i;
		while (line[i])
			(i)++;
		data->floor = ft_substr(line, start, i - 1);
		if (!data->floor)
			return ("Malloc failure");
		// printf("floor: <%s>\n", data->floor); //debug
		data->floor_rgb = get_rgb(data->floor, data->fd_map);
		printf(YELLOW "Floor color : %s. RGB = %#08x.\n" RESET, data->floor, data->floor_rgb); //debug
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

void	parse_color(char *line, t_data *data, t_option option)
{
	int		i;
	char	*failure;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!(ft_isdigit(line[i]) || line[i] == ','))
			color_error(data->fd_map, option);
		i++;
	}
	failure = parse_color_helper(data, line, option);
	if (failure)
		error(failure, data->fd_map);
}
