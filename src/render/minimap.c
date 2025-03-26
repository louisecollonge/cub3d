/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:20:52 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/26 16:33:18 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	init_minimap_data(t_game *game, t_minimap *minimap)
{
	minimap->map_width = get_map_width(game->map);
	minimap->map_height = get_map_height(game->map);
	minimap->width = 200;
	minimap->height = 200;
	minimap->tile_size = (minimap->width / (double)minimap->map_width) * 1.5;
	minimap->img = NULL;
	minimap->tiles_x = minimap->width / minimap->tile_size;
	minimap->tiles_y = minimap->height / minimap->tile_size;
}

static void	update_offset(t_render_data *data, t_minimap *minimap)
{
	minimap->offset_x = data->pos_x - (minimap->tiles_x / 2.0);
	minimap->offset_y = data->pos_y - (minimap->tiles_y / 2.0);
	if (minimap->offset_x < 0)
		minimap->offset_x = 0;
	if (minimap->offset_y < 0)
		minimap->offset_y = 0;
	if (minimap->offset_x > minimap->map_width - minimap->tiles_x)
		minimap->offset_x = minimap->map_width - minimap->tiles_x;
	if (minimap->offset_y > minimap->map_height - minimap->tiles_y)
		minimap->offset_y = minimap->map_height - minimap->tiles_y;
}

void	draw_walls(int x, int y, t_minimap *minimap, t_game *game )
{
	int		map_x;
	int		map_y;
	double	map_x_f;
	double	map_y_f;

	map_x_f = minimap->offset_x + ((double)x / minimap->tile_size);
	map_y_f = minimap->offset_y + ((double)y / minimap->tile_size);
	map_x = (int)floor(map_x_f);
	map_y = (int)floor(map_y_f);
	if (map_x >= 0 && map_x < minimap->map_width
		&& map_y >= 0 && map_y < minimap->map_height)
	{
		if (map_x < get_line_width(game->map, map_y))
		{
			if (game->map[map_y][map_x] == '1')
				my_mlx_pixel_put(minimap->img, x, y, 0xFFFFFF);
			else
				my_mlx_pixel_put(minimap->img, x, y, 0x000000);
		}
	}
}

void	draw_player(t_minimap *minimap, t_render_data *data)
{
	int	player_screen_x;
	int	player_screen_y;
	int	x1;
	int	y1;

	player_screen_x = (data->pos_x - minimap->offset_x) * minimap->tile_size;
	player_screen_y = (data->pos_y - minimap->offset_y) * minimap->tile_size;
	x1 = player_screen_x + data->dir_x * minimap->tile_size;
	y1 = player_screen_y + data->dir_y * minimap->tile_size;
	draw_line(minimap->img, (t_coord){player_screen_x,
		x1,
		player_screen_y,
		y1},
		0xFFFFFFFF);
	draw_square(minimap->img, (t_coord){
		player_screen_x - minimap->tile_size / 3,
		player_screen_x + minimap->tile_size / 3,
		player_screen_y - minimap->tile_size / 3,
		player_screen_y + minimap->tile_size / 3},
		0xFF0000);
}

void	draw_minimap(t_game *game, t_render_data *data, t_minimap *minimap)
{
	int	x;
	int	y;

	update_offset(data, minimap);
	y = 0;
	while (y < minimap->height)
	{
		x = 0;
		while (x < minimap->width)
		{
			draw_walls(x, y, minimap, game);
			x++;
		}
		y++;
	}
	draw_player(minimap, data);
}
