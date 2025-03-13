/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:10:30 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/13 13:28:28 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	parse_texture(char *line, t_data *data, t_option option)
{
	printf(GREEN "%s\n" RESET, line); //debug
	(void)data;
	(void)option;
	// if (option == NO)
	// {
	// 	data->no = mlx_load_png(line);
	// 	if (!data->no)
	// 		error("North texture loading failure", data->fd_map);
	// }
	// else if (option == SO)
	// {
	// 	data->so = mlx_load_png(line);
	// 	if (!data->so)
	// 		error("South texture loading failure", data->fd_map);
	// }
	// else if (option == WE)
	// {
	// 	data->we = mlx_load_png(line);
	// 	if (!data->we)
	// 		error("West texture loading failure", data->fd_map);
	// }
	// else if (option == EA)
	// {
	// 	data->ea = mlx_load_png(line);
	// 	if (!data->ea)
	// 		error("East texture loading failure", data->fd_map);
	// }
}
