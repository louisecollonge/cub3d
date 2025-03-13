/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:10:30 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/13 10:48:49 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	parse_texture(char *line, t_tex *textures, t_option option)
{
	// printf(GREEN "%s\n" RESET, line); //debug
	if (option == NO)
	{
		textures->no = mlx_load_png(line);
		if (!textures->no)
			error("North texture error", textures->fd_map);
	}
	else if (option == SO)
	{
		textures->so = mlx_load_png(line);
		if (!textures->so)
			error("South texture error", textures->fd_map);
	}
	else if (option == WE)
	{
		textures->we = mlx_load_png(line);
		if (!textures->we)
			error("West texture error", textures->fd_map);
	}
	else if (option == EA)
	{
		textures->ea = mlx_load_png(line);
		if (!textures->ea)
			error("East texture error", textures->fd_map);
	}
}
