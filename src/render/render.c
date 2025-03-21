/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:15:22 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/21 19:30:33 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	render_loop(void *param)
{
	t_ray_data	*data;

	data = (t_ray_data *)param;
	if (!data->game->img)
	{
		data->game->img = mlx_new_image(data->game->mlx, WIDTH, HEIGHT);
		if (!data->game->img)
			my_mlx_close(data->game->mlx);
		mlx_image_to_window(data->game->mlx, data->game->img, 0, 0);
	}
	data->render_data->current_time = mlx_get_time();
	data->render_data->frame_time
		= data->render_data->current_time - data->render_data->old_time;
	data->render_data->old_time = data->render_data->current_time;
	data->render_data->move_speed = data->render_data->frame_time * 2.5;
	data->render_data->rot_speed = data->render_data->frame_time * 3.0;
	update_keys(data->game, data->render_data,
		data->render_data->move_speed, data->render_data->rot_speed);
	clear_image(data->game->img);
	draw_ceiling(data->game->img, data->game->data->ceiling_rgb);
	draw_floor(data->game->img, data->game->data->floor_rgb);
	raycast(data->game, data->render_data);
}

/*
raycasting :
- lancer rayons a partir de la position du joueur
- detecter collisions avec murs
- dessiner murs avec texture et hauteur
*/
