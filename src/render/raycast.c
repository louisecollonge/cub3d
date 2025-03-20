/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:08:37 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/20 19:17:56 by amonfret         ###   ########.fr       */
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
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x) * data->delta_dist_x;
	}
	if (data->ray_direction_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y) * data->delta_dist_y;
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

void	dda(t_game *game, t_render_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (game->map[data->map_y][data->map_x] == '1')
		{
			data->hit = 1;
			set_wall_direction(data);
		}
	}
}

void	set_perp_wall_dist(t_render_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
	if (data->perp_wall_dist < 0.2)
		data->perp_wall_dist = 0.2;
}

void	set_line_height(t_game *game, t_render_data *data)
{
	int	line_height;
	int	height;

	height = (int)game->img->height;

	line_height = (int)(height / data->perp_wall_dist);
	data->draw_start = -line_height / 2 + height / 2;
	// if(data->draw_start < 0)
	// 	data->draw_start = 0;
	data->draw_end = line_height / 2 + height / 2;
	// if (data->draw_end >= height)
	// 	data->draw_end = height - 1;
}

//sets the correct texture index for a wall
void	set_texture_index(t_render_data *data)
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

//!debug
void	print_data(t_render_data *data)
{
	printf("pos_x %f pos_y %f\n", data->pos_x, data->pos_y);
	printf("dir_x %f dir_y %f\n", data->dir_x, data->dir_y);
	printf("plane_x %f plane_y %f\n", data->plane_x, data->plane_y);
	printf("camera_x %f\n", data->camera_x);
	printf("ray_dir_x %f ray_dir_y %f\n", data->ray_direction_x, data->ray_direction_y);
	printf("map_x %d map_y %d\n", data->map_x, data->map_y);
	printf("side_dist_x %f side_dist_y %f\n", data->side_dist_x, data->side_dist_y);
	printf("delta_dist_x %f delta_dist_y %f\n", data->delta_dist_x, data->delta_dist_y);
	printf("perpendicular_wall_dist %f\n", data->perp_wall_dist);
	printf("step_x %f step_y %f\n", data->step_x, data->step_y);
	printf("hit %d\n", data->hit);
	printf("side %d\n", data->side);
	printf("draw_start %d draw_end %d\n", data->draw_start, data->draw_end);
	printf("wall_direction %d\n", data->wall_dir);
}

//gives a value between 0.0 and 1.0 indicating
//where along the wall (horizontally) the ray hit
void	set_wall_x(t_render_data *data)
{
	if (data->side == 0)
		data->wall_x = data->pos_y + data->perp_wall_dist * data->ray_direction_y;
	else
		data->wall_x = data->pos_x + data->perp_wall_dist * data->ray_direction_x;
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
		draw_texture_stripe(game->img, x,game, data);
		// vertical_line(game->img, x, (t_vertical){data->draw_start, data->draw_end}, data->color);
		x++;
	}
}