/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:01:46 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/20 16:03:17 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	rotate_right(t_game *game, t_render_data *data, double rot_speed)
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

void	rotate_left(t_game *game, t_render_data *data, double rot_speed)
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
