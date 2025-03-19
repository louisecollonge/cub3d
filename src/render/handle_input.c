/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:05:48 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/19 21:33:20 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	move_forward(t_game *game, t_render_data *data, double move_speed)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
	{
		if(game->map[(int)(data->pos_x + data->dir_x * move_speed)][(int)(data->pos_y)]!= '1')
			data->pos_x += data->dir_x * move_speed;
		if(game->map[(int)(data->pos_x)][(int)(data->pos_y + data->dir_y * move_speed)] != '1')
			data->pos_y += data->dir_y * move_speed;
	}

}

static void	move_backward(t_game *game, t_render_data *data, double move_speed)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
		if (game->map[(int)(data->pos_x - data->dir_x * move_speed)][(int)(data->pos_y)] != '1')
			data->pos_x -= data->dir_x * move_speed;
		if (game->map[(int)(data->pos_x)][(int)(data->pos_y - data->dir_y * move_speed)] != '1')
			data->pos_y -= data->dir_y * move_speed;
	}
}

static void	rotate_right(t_game *game, t_render_data *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(-rot_speed) - data->dir_y * sin(-rot_speed);
		data->dir_y = old_dir_x * sin(-rot_speed) + data->dir_y * cos(-rot_speed);
		old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(-rot_speed) - data->plane_y * sin(-rot_speed);
		data->plane_y = old_plane_x * sin(-rot_speed) + data->plane_y * cos(-rot_speed);
	}

}

static void	rotate_left(t_game *game, t_render_data *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(rot_speed) - data->dir_y * sin(rot_speed);
		data->dir_y = old_dir_x * sin(rot_speed) + data->dir_y * cos(rot_speed);
		old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(rot_speed) - data->plane_y * sin(rot_speed);
		data->plane_y = old_plane_x * sin(rot_speed) + data->plane_y * cos(rot_speed);
	}
}

void update_keys(t_game *game, t_render_data *data, double move_speed, double rot_speed)
{
	move_forward(game, data, move_speed);
	move_backward(game, data, move_speed);
	rotate_right(game, data, rot_speed);
	rotate_left(game, data, rot_speed);
}