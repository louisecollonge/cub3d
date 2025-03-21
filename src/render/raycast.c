/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:08:37 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/21 19:28:55 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	set_perp_wall_dist(t_render_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
	if (data->perp_wall_dist < 0.1)
		data->perp_wall_dist = 0.1;
}

static void	set_line_height(t_game *game, t_render_data *data)
{
	int	line_height;
	int	height;

	height = (int)game->img->height;
	line_height = (int)(height / data->perp_wall_dist);
	data->draw_start = -line_height / 2 + height / 2;
	data->draw_end = line_height / 2 + height / 2;
}

//sets the correct texture index for a wall
static void	set_texture_index(t_render_data *data)
{
	if (data->wall_dir == NORTH)
		data->texture_index = 0;
	else if (data->wall_dir == SOUTH)
		data->texture_index = 1;
	else if (data->wall_dir == EAST)
		data->texture_index = 2;
	else if (data->wall_dir == WEST)
		data->texture_index = 3;
}

//gives a value between 0.0 and 1.0 indicating
//where along the wall (horizontally) the ray hit
static void	set_wall_x(t_render_data *data)
{
	if (data->side == 0)
		data->wall_x
			= data->pos_y + data->perp_wall_dist * data->ray_direction_y;
	else
		data->wall_x
			= data->pos_x + data->perp_wall_dist * data->ray_direction_x;
	data->wall_x -= floor(data->wall_x);
}

void	raycast(t_game *game, t_render_data *data)
{
	int	x;

	x = 0;
	while (x < (int)game->img->width)
	{
		calc_ray_direction(game, data, x);
		set_map_cell(data);
		set_delta_dist(data);
		data->hit = 0;
		calculate_step(data);
		dda(game, data);
		set_perp_wall_dist(data);
		set_line_height(game, data);
		set_wall_x(data);
		set_texture_index(data);
		draw_texture_stripe(game->img, x, game, data);
		x++;
	}
}
