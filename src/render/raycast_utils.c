/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:20:11 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/21 19:28:39 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	calc_ray_direction(t_game *game, t_render_data *data, int x)
{
	data->camera_x = 2 * x / (double)game->img->width - 1;
	data->ray_direction_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_direction_y = data->dir_y + data->plane_y * data->camera_x;
}

void	set_map_cell(t_render_data *data)
{
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
}

void	set_delta_dist( t_render_data *data)
{
	if (data->ray_direction_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1.0 / data->ray_direction_x);
	if (data->ray_direction_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1.0 / data->ray_direction_y);
}

void	calculate_step(t_render_data *data)
{
	if (data->ray_direction_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x
			= (data->map_x + 1.0 - data->pos_x) * data->delta_dist_x;
	}
	if (data->ray_direction_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y
			= (data->map_y + 1.0 - data->pos_y) * data->delta_dist_y;
	}
}

void	set_wall_direction(t_render_data *data)
{
	if (data->side == 0)
	{
		if (data->step_x > 0)
			data->wall_dir = EAST;
		else
			data->wall_dir = WEST;
	}
	else
	{
		if (data->step_y > 0)
			data->wall_dir = SOUTH;
		else
			data->wall_dir = NORTH;
	}
}
