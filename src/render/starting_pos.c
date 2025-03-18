/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:04:04 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/18 19:15:30 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int get_map_height(char **map)
{
	int height;
	height = 0;
	while (map[height])
		height++;
	return (height);
}

static int get_map_width(char **map)
{
	int width;
	int row_length;

	width = 0;
	int i;
	i = 0;
	while (map[i])
	{
		row_length = ft_strlen(map[i]);
		if (row_length > width)
			width = row_length;
		i++;
	}
	return (width);
}

void set_starting_pos(t_game *game, t_render_data *render_data)
{
	int	width;
	int	height;
	int	x;
	int	y;

	width = get_map_width(game->map);
	height = get_map_height(game->map);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width && game->map[y][x])
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
			{
				render_data->pos_x = x + 0.5;
				render_data->pos_y = y + 0.5;
				return;
			}
			x++;
		}
		y++;
	}
}

