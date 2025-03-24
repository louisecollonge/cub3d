/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:20:52 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/24 19:43:31 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	init_minimap_data(t_game *game, t_minimap *minimap)
{
	minimap->map_width = get_map_width(game->map);
	minimap->map_height = get_map_height(game->map);
	minimap->width = 200;
	minimap->height = 200;
	minimap->tile_size = (minimap->width / minimap->map_width) * 2;
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

void	draw_minimap(mlx_image_t *img, t_game *game, t_render_data *data, t_minimap *minimap)
{
	int	x;
	int	y;
	int	map_x;
	int	map_y;

	update_offset(data, minimap);
	y = 0;
	while (y < minimap->height)
	{
		x = 0;
		while (x < minimap->width)
		{
			map_x = minimap->offset_x + (x / minimap->tile_size);
			map_y = minimap->offset_y + (y / minimap->tile_size);
			if (map_x >= 0 && map_x < minimap->map_width && map_y >= 0 && map_y < minimap->map_height)
			{
				if (game->map[map_y][map_x] == '1')
					my_mlx_pixel_put(img, x ,y , 0xFFFFFF);
				else
					my_mlx_pixel_put(img, x ,y , 0x000000);
			}
			x++;
		}
		y++;
	}

}

// void	minimap_loop(void *param)
// {
// 	t_ray_data	*data;

// 	data = (t_ray_data *)param;
// 	if (!data->minimap->img)
// 	{
// 		data->minimap->img = mlx_new_image(data->game->mlx, WIDTH, HEIGHT);
// 		if (!data->minimap->img)
// 			my_mlx_close(data->game->mlx);
// 		mlx_image_to_window(data->game->mlx, data->game->img, 0, 0);
// 	}
// 	data->render_data->current_time = mlx_get_time();
// 	data->render_data->frame_time
// 		= data->render_data->current_time - data->render_data->old_time;
// 	data->render_data->old_time = data->render_data->current_time;
// 	data->render_data->move_speed = data->render_data->frame_time * 2.5;
// 	data->render_data->rot_speed = data->render_data->frame_time * 3.0;
// 	update_keys(data->game, data->render_data,
// 		data->render_data->move_speed, data->render_data->rot_speed);
// 	clear_image(data->game->img);
// 	draw_ceiling(data->game->img, data->game->data->ceiling_rgb);
// 	draw_floor(data->game->img, data->game->data->floor_rgb);
// 	raycast(data->game, data->render_data);
// }