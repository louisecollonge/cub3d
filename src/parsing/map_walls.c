/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:20:38 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/14 18:55:18 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

// static bool	space(char **tab, int row, int col)
// {
// 	printf("tab[%d][%d] = <%c>\n", row, col, tab[row][col]);
// 	return (true);
// }

bool	wall_outline(t_data *data)
{
	int	row;
	int	col;

	col = 0;
	data->map_tab = ft_split(data->map_string, '\n');
	if (!data->map_tab)
		error("Malloc failure", data, NULL, NULL);
	print_tab(data->map_tab); //debug

	//1ere ligne:
	while (data->map_tab[0][col])
	{
		if (data->map_tab[0][col] != '1' && data->map_tab[0][col] != ' '
			&& data->map_tab[0][col] != '\t')
			return (false);
		col++;
	}

	//de la 2e ligne a l'avant-derniere:
	// row = 1;
	// col = 0;
	// while (data->map_tab[row] && row <= tab_line_nb(data->map_tab) - 1)
	// {
	// 	while (data->map_tab[row][col])
	// 	{
	// 		if (data->map_tab[row][col] == ' ')
	// 			if (space(data->map_tab, row, col) == false)
	// 				return (false);
	// 		col++;
	// 	}
	// 	row++;
	// }


	//derniere ligne:
	row = tab_line_nb(data->map_tab) - 1;
	col = 0;
	while (data->map_tab[row][col] != '\n')
	{
		if (data->map_tab[row][col] != '1' && data->map_tab[row][col] != ' ')
			return (false);
		row++;
	}
	return (true);
}
