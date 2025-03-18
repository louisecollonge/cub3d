/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:20:38 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/18 10:31:58 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static bool	space(char **tab, int x, int y)
{
	if (tab[x - 1][y])
	{
		if (!(tab[x - 1][y] == '\t' || tab[x - 1][y] == ' ' || tab[x - 1][y] == '1' || !tab[x - 1][y]))
		{
			printf("Wrong space at row %d and col %d ", x, y); //debug
			printf("because of the char on the top of it\n"); //debug
			return (false);
		}	
	}
	if (tab[x][y - 1])
	{
		if (!(tab[x][y - 1] == '\t' || tab[x][y - 1] == ' ' || tab[x][y - 1] == '1' || !tab[x][y - 1]))
		{
			printf("Wrong space at row %d and col %d ", x, y); //debug
			printf("because of the char on the left of it\n"); //debug
			return (false);
		}
	}
	if (tab[x][y + 1])
	{
		if (!(tab[x][y + 1] == '\t' || tab[x][y + 1] == ' ' || tab[x][y + 1] == '1' || !tab[x][y + 1]))
		{
			printf("Wrong space at row %d and col %d ", x, y); //debug
			printf("because of the char on the right of it\n"); //debug
			return (false);
		}
	}
	if (tab[x + 1][y])
	{
		if (!(tab[x + 1][y] == '\t' || tab[x + 1][y] == ' ' || tab[x + 1][y] == '1' || !tab[x + 1][y]))
		{
			printf("Wrong space at row %d and col %d ", x, y); //debug
			printf("because of the char on the bottom of it\n"); //debug
			return (false);
		}
	}
	return (true);
}

static bool	first_tab_line(t_data *data, int *col)
{
	while (data->map_tab[0][*col])
	{
		if (data->map_tab[0][*col] != '1' && data->map_tab[0][*col] != ' '
			&& data->map_tab[0][*col] != '\t')
		{
			printf("Wrong space at row 0 and col %d ", *col); //debug
			printf("because of the char on the bottom of it\n"); //debug
			return (false);
		}
		(*col)++;
	}
	return (true);
}

static bool	middle_tab_lines(t_data *data, int *row)
{
	int	col;

	while (data->map_tab[*row] && *row < tab_line_nb(data->map_tab) - 1)
	{
		col = 0;
		while (data->map_tab[*row][col])
		{
			if (data->map_tab[*row][col] == ' ')
				if (space(data->map_tab, *row, col) == false)
					return (false);
			col++;
		}
		(*row)++;
	}
	return (true);
}

static bool	last_tab_line(t_data *data, int *row)
{
	int	col;

	col = 0;
	while (data->map_tab[*row][col])
	{
		if (data->map_tab[*row][col] != '1' && data->map_tab[*row][col] != ' '
			&& data->map_tab[*row][col] != '\t')
		{
			printf("Wrong space at row %d and col %d ", *row, col); //debug
			printf("because of the char on the bottom of it\n"); //debug
			return (false);
		}
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
	if (first_tab_line(data, &col) == false)
		return (false);
	row = 1;
	if (middle_tab_lines(data, &row) == false)
		return (false);
	if (last_tab_line(data, &row) == false)
		return (false);
	return (true);
}
