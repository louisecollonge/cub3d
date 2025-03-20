/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_floor_ceiling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:11:55 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/20 17:15:27 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	check_number(char *option, size_t i, t_data *data)
{
	if (i > ft_strlen(option) - 1)
		error("Wrong color", data, NULL, NULL);
	if (!option[i] || !(option[i] == '+' || option[i] == ' '
			|| ft_isdigit(option[i])))
		error("Wrong color", data, NULL, NULL);
	if (option[i] == '+')
		if (!ft_isdigit(option[i + 1]))
			error("Wrong color", data, NULL, NULL);
}

static int	get_rgb(char *option, t_data *data)
{
	size_t	i;
	int		r;
	int		g;
	int		b;

	i = 0;
	check_number(option, i, data);
	r = ft_atoi(option);
	while (option[i] && option[i] != ',')
		i++;
	i++;
	check_number(option, i, data);
	g = ft_atoi(&option[i]);
	while (option[i] && option[i] != ',')
		i++;
	i++;
	check_number(option, i, data);
	b = ft_atoi(&option[i]);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		error("Wrong color", data, NULL, NULL);
	return ((r << 16) | (g << 8) | b);
}

static char	*parse_color_helper(t_data *data, char *line, int start_index,
	t_option option)
{
	int	i;

	i = 0;
	if (option == CEILING)
	{
		while (line[i])
			(i)++;
		data->ceiling = ft_substr(line, start_index, i - 1);
		if (!data->ceiling)
			error ("Malloc failure", data, NULL, NULL);
		data->ceiling_rgb = get_rgb(data->ceiling, data);
	}
	else if (option == FLOOR)
	{
		while (line[i])
			(i)++;
		data->floor = ft_substr(line, start_index, i - 1);
		if (!data->floor)
			error ("Malloc failure", data, NULL, NULL);
		data->floor_rgb = get_rgb(data->floor, data);
	}
	return (NULL);
}

void	parse_color(char *line, t_data *data, t_option option, int *count)
{
	int		i;
	int		start_index;
	char	*failure;

	i = 0;
	(*count)++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	start_index = i;
	while (line[i] && line[i] != '\n')
	{
		if (!(ft_isdigit(line[i]) || line[i] == ',' || line[i] == '\t'
				|| line[i] == ' ' || line[i] == '+'))
		{
			if (option == FLOOR)
				error("Wrong floor color", data, NULL, NULL);
			else if (option == CEILING)
				error("Wrong ceiling color", data, NULL, NULL);
		}
		i++;
	}
	failure = parse_color_helper(data, line, start_index, option);
	if (failure)
		error(failure, data, NULL, NULL);
}
