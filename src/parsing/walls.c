/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:20:38 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/20 17:10:12 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static bool	first_tab_line(t_data *data, size_t *col)
{
	while (data->map_tab[0][*col])
	{
		if (data->map_tab[0][*col] != '1' && data->map_tab[0][*col] != ' '
			&& data->map_tab[0][*col] != '\t')
			return (false);
		(*col)++;
	}
	return (true);
}

static bool	middle_tab_lines(t_data *data, size_t *row)
{
	size_t	col;

	while (data->map_tab[*row] && *row < tab_line_nb(data->map_tab) - 1)
	{
		col = 0;
		while (data->map_tab[*row][col])
		{
			if (data->map_tab[*row][col] == ' ')
			{
				if (space(data->map_tab, *row, col) == false)
					return (false);
			}
			else if (data->map_tab[*row][col] == '0')
			{
				if (zero(data->map_tab, *row, col) == false)
					return (false);
			}
			col++;
		}
		(*row)++;
	}
	return (true);
}

static bool	last_tab_line(t_data *data, size_t *row)
{
	size_t	col;

	col = 0;
	while (data->map_tab[*row][col])
	{
		if (data->map_tab[*row][col] != '1' && data->map_tab[*row][col] != ' '
			&& data->map_tab[*row][col] != '\t')
			return (false);
		col++;
	}
	return (true);
}

bool	wall_outline(t_data *data)
{
	size_t	row;
	size_t	col;

	col = 0;
	data->map_tab = ft_split(data->map_string, '\n');
	if (!data->map_tab)
		error("Malloc failure", data, NULL, NULL);
	if (first_tab_line(data, &col) == false)
		return (false);
	row = 1;
	if (middle_tab_lines(data, &row) == false)
		return (false);
	if (last_tab_line(data, &row) == false)
		return (false);
	return (true);
}
