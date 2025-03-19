/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:13:24 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/19 14:46:15 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

bool	end_of_map(t_data *data)
{
	if (data->ceiling_rgb == -1 || data->floor_rgb == -1 || !data->no
		|| !data->so || !data->we || !data->ea)
		return (false);
	else
		return (true);
}

bool	is_orientation(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0)
		return (true);
	else
		return (false);
}

t_option	get_option(char *line)
{
	t_option	option;

	if (ft_strncmp(line, "NO ", 3) == 0)
		option = NO;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		option = SO;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		option = WE;
	else
		option = EA;
	return (option);
}

bool	space(char **tab, size_t x, size_t y)
{
	if (x >= 1 && tab[x - 1][y])
	{
		if (!(tab[x - 1][y] == '\t' || tab[x - 1][y] == ' '
			|| tab[x - 1][y] == '1' || !tab[x - 1][y]))
		{
			printf("row %zu col %zu: pb on top\n", x, y);
			return (false);
		}
	}
	if (y >= 1 && tab[x][y - 1])
	{
		if (!(tab[x][y - 1] == '\t' || tab[x][y - 1] == ' '
			|| tab[x][y - 1] == '1' || !tab[x][y - 1]))
		{
			printf("row %zu col %zu: pb on the left\n", x, y);
			return (false);
		}
	}
	if (tab[x][y + 1])
	{
		if (!(tab[x][y + 1] == '\t' || tab[x][y + 1] == ' '
			|| tab[x][y + 1] == '1' || !tab[x][y + 1]))
		{
			printf("row %zu col %zu: pb on the right\n", x, y);
			return (false);
		}
	}
	if (tab[x + 1][y])
	{
		if (!(tab[x + 1][y] == '\t' || tab[x + 1][y] == ' '
			|| tab[x + 1][y] == '1' || !tab[x + 1][y]))
		{
			printf("row %zu col %zu: pb bellow\n", x, y);
			return (false);
		}
	}
	return (true);
}

bool	acceptable_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	else
		return (false);
}

bool	zero(char **tab, size_t x, size_t y)
{
	// print_tab(tab); //debug
	if ((x - 1) >= 0 && acceptable_char(tab[x - 1][y]) == false)
	{
		printf("Error\nproblem with 0 at row %zu col %zu, with char on top\n", x, y); //debug
		return (false);
	}
	if (y == 0)
		return (false);
	if ((y - 1) >= 0 && acceptable_char(tab[x][y - 1]) == false)
	{
		printf("Error\nproblem with 0 at row %zu col %zu, with char on the left\n", x, y); //debug
		return (false);
	}
	if ((y + 1) >= ft_strlen(tab[x]))
	{
		if (acceptable_char(tab[x][y + 1]) == false)
		{
			printf("Error\nproblem with 0 at row %zu col %zu, with char on the right\n", x, y); //debug
			return (false);
		}
	}
	if ((x + 1) >= tab_line_nb(tab))
	{
		if (acceptable_char(tab[x + 1][y]) == false)
		{
			printf("Error\nproblem with 0 at row %zu col %zu, with char bellow\n", x, y); //debug
			return (false);
		}
	}
	return (true);
}
