/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:10:30 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/14 18:53:02 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	parse_texture(char *line, t_data *data, t_option option)
{
	(void)data;
	(void)option;
	(void)line;
	printf(GREEN "%s\n" RESET, line); //debug

	// if (option == NO)
	// {
	// 	data->no = mlx_load_png(line);
	// 	if (!data->no)
	// 		error("North texture loading failure", data, line, NULL);
	// }
	// else if (option == SO)
	// {
	// 	data->so = mlx_load_png(line);
	// 	if (!data->so)
	// 		error("South texture loading failure", data, line, NULL);
	// }
	// else if (option == WE)
	// {
	// 	data->we = mlx_load_png(line);
	// 	if (!data->we)
	// 		error("West texture loading failure", data, line, NULL);
	// }
	// else if (option == EA)
	// {
	// 	data->ea = mlx_load_png(line);
	// 	if (!data->ea)
	// 		error("East texture loading failure", data, line, NULL);
	// }
}
