/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_specific_checks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:20:38 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/13 19:52:44 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

// static bool	inside_line(char *line, int col, int end)
// {
// 	printf("%s\n", line + col);
	
// 	if (line[col] != '1' || line[end] != '1')
// 		return (false);
// 	// while (col < end)
// 	// {
		
// 	// }
// 	return (true);
// }

bool	empty_space(t_data *data)
{
	int	row;
	// int	col;
	// int	end; //le bout de la ligne

	row = 1; //on se fiche qu'il y ait des espaces dans la 1ere ligne
	while (data->map_tab[row] && row < tab_line_nb(data->map_tab) - 1) //on se fiche de la derniere ligne
	{
		printf(YELLOW "%s\n" RESET, data->map_tab[row]);

		// end = ft_strlen(data->map_tab[row] - 1);
		// printf("%c\n", data->map_tab[row][end]);
		// // printf("end: %d", end);
		// while (end == ' ' || end == '\t')
		// 	end--;
		// // printf("debut: %d, fin: %d\n", col, end);
		
		// // if (inside_line(&data->map_string[row], col, end) == false)
		// // 	return (false);
		row++;
	}

	return (true);
}

bool	wall_outline(t_data *data)
{
	int	i;

	i = 0;
	//1ere ligne:
	while (data->map_string[i] != '\n')
	{
		if (data->map_string[i] != '1' && data->map_string[i] != ' '
			&& data->map_string[i] != '\t')
			return (false);
		i++;
	}
	i++; //sauter le \n de fin de 1ere ligne

	
	data->map_tab = ft_split(data->map_string, '\n');
	if (!data->map_tab)
		error("Malloc failure", data);
	//todo lignes du milieu

	//derniere ligne:
	i = ft_strlen(data->map_string) - 1;
	while (data->map_string[i] == '\n')
		i--;
	while (data->map_string[i] != '\n')
	{
		if (data->map_string[i] != '1' && data->map_string[i] != ' ')
			return (false);
		i--;
	}

	// printf("<%c>\n", data->map_string[i]); //debug
	return (true);
}
