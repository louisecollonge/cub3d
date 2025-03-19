/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render_data_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:04:04 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/19 18:38:48 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void set_starting_position(t_game *game, t_render_data *render_data)
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

void	set_starting_direction(t_game *game, t_render_data *render_data)
{
	int	x;
	int	y;

	x = (int)(render_data->pos_x);
	y = (int)(render_data->pos_y);
	if (game->map[y][x] == 'N')
	{
		render_data->dir_x = 0.0;
		render_data->dir_y = 1.0;
	}
	else if (game->map[y][x] == 'S')
	{
		render_data->dir_x = 0.0;
		render_data->dir_y = -1.0;
	}
	else if (game->map[y][x] == 'E')
	{
		render_data->dir_x = 1.0;
		render_data->dir_y = 0.0;
	}
	else if (game->map[y][x] == 'W')
	{
		render_data->dir_x = -1.0;
		render_data->dir_y = 0.0;
	}
}

void	set_camera_plane(t_render_data *render_data)
{
	// render_data->plane_x = render_data->dir_y;
	// render_data->plane_y = -render_data->dir_x;
	double		fov_rad;
	double		plane_length;
	double		fov_deg;

	fov_deg = 66;
	fov_rad = fov_deg * M_PI / 180.0;
	plane_length = tan(fov_rad / 2.0);
	render_data->plane_x = render_data->dir_y * plane_length;
	render_data->plane_y = -render_data->dir_x * plane_length;
}

void	init_time(t_render_data *render_data)
{
	render_data->time = 0.0;
	render_data->old_time = 0.0;
}
