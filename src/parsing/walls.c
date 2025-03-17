/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:20:38 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/17 16:35:57 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static bool	space(char **tab, int x, int y)
{
	if ((tab[x - 1][y] == '\t' || tab[x - 1][y] == ' ' || tab[x - 1][y] == '1' || !tab[x - 1][y])
	&& (tab[x][y - 1] == '\t' || tab[x][y - 1] == ' ' || tab[x][y - 1] == '1' || !tab[x][y - 1])
	&& (tab[x][y + 1] == '\t' || tab[x][y + 1] == ' ' || tab[x][y + 1] == '1' || !tab[x][y + 1])
	&& ((tab[x + 1][y] == '\t' || tab[x + 1][y] == ' ' || tab[x + 1][y] == '1' || !tab[x + 1][y])))
		return (true);
	printf("Wrong space at row = %d and col = %d\n", x, y); //debug
	return (false);
}

static bool	first_line(t_data *data, int *col)
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

static bool	last_line(t_data *data, int *row)
{
	int	col;

	col = 0;
	while (data->map_tab[*row][col])
	{
		if (data->map_tab[*row][col] != '1' && data->map_tab[*row][col] != ' ')
			return (false);
		col++;
	}
	return (true);
}

bool	wall_outline(t_data *data)
{
	int	row;
	int	col;

	col = 0;
	data->map_tab = ft_split(data->map_string, '\n');
	if (!data->map_tab)
		error("Malloc failure", data, NULL, NULL);
	if (first_line(data, &col) == false)
		return (false);
	row = 1;
	while (data->map_tab[row] && row < tab_line_nb(data->map_tab) - 1)//de la 2e ligne a l'avant-derniere:
	{
		col = 0;
		while (data->map_tab[row][col])
		{
			if (data->map_tab[row][col] == ' ')
				if (space(data->map_tab, row, col) == false)
					return (false);
			col++;
		}
		row++;
	}
	if (last_line(data, &row) == false)
		return (false);
	return (true);
}
