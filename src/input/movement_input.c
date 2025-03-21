/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:35:22 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/21 18:42:09 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	move_forward(t_game *game, t_render_data *data, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = data->pos_x + data->dir_x * move_speed;
	new_y = data->pos_y + data->dir_y * move_speed;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		if (game->map[(int)(data->pos_y)][(int)(new_x + COLL_RAD)] != '1' &&
			game->map[(int)(data->pos_y)][(int)(new_x - COLL_RAD)] != '1')
			data->pos_x = new_x;
		if (game->map[(int)(new_y + COLL_RAD)][(int)(data->pos_x)] != '1' &&
			game->map[(int)(new_y - COLL_RAD)][(int)(data->pos_x)] != '1')
			data->pos_y = new_y;
	}
}

void	move_backward(t_game *game, t_render_data *data, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = data->pos_x - data->dir_x * move_speed;
	new_y = data->pos_y - data->dir_y * move_speed;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		if (game->map[(int)(data->pos_y)][(int)(new_x + COLL_RAD)] != '1' &&
			game->map[(int)(data->pos_y)][(int)(new_x - COLL_RAD)] != '1')
			data->pos_x = new_x;
		if (game->map[(int)(new_y + COLL_RAD)][(int)(data->pos_x)] != '1' &&
			game->map[(int)(new_y + COLL_RAD)][(int)(data->pos_x)] != '1')
			data->pos_y = new_y;
	}
}

void	move_left(t_game *game, t_render_data *data, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = data->pos_x - data->plane_x * move_speed;
	new_y = data->pos_y - data->plane_y * move_speed;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		if (game->map[(int)(data->pos_y)][(int)(new_x + COLL_RAD)] != '1' &&
			game->map[(int)(data->pos_y)][(int)(new_x - COLL_RAD)])
			data->pos_x = new_x;
		if (game->map[(int)(new_y + COLL_RAD)][(int)(data->pos_x)] != '1' &&
			game->map[(int)(new_y - COLL_RAD)][(int)(data->pos_x)] != '1')
			data->pos_y = new_y;
	}
}

void	move_right(t_game *game, t_render_data *data, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = data->pos_x + data->plane_x * move_speed;
	new_y = data->pos_y + data->plane_y * move_speed;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		if (game->map[(int)(data->pos_y)][(int)(new_x + COLL_RAD)] != '1' &&
			game->map[(int)(data->pos_y)][(int)(new_x - COLL_RAD)] != '1')
			data->pos_x = new_x;
		if (game->map[(int)(new_y + COLL_RAD)][(int)(data->pos_x)] != '1' &&
			game->map[(int)(new_y - COLL_RAD)][(int)(data->pos_x)] != '1')
			data->pos_y = new_y;
	}
}

void	push_player(t_game *game, t_render_data *data)
{
	if (game->map[(int)(data->pos_y)][(int)(data->pos_x + COLL_RAD)] == '1')
	{
		if (game->map
			[(int)(data->pos_y)][(int)(data->pos_x - COLL_RAD)] != '1')
			data->pos_x -= COLL_RAD;
	}
	if (game->map[(int)(data->pos_y)][(int)(data->pos_x - COLL_RAD)] == '1')
	{
		if (game->map
			[(int)(data->pos_y)][(int)(data->pos_x + COLL_RAD)] != '1')
			data->pos_x += COLL_RAD;
	}
	if (game->map[(int)(data->pos_y - COLL_RAD)][(int)(data->pos_x)] == '1')
	{
		if (game->map
			[(int)(data->pos_y + COLL_RAD)][(int)(data->pos_x)] != '1')
			data->pos_y += COLL_RAD;
	}
	if (game->map[(int)(data->pos_y + COLL_RAD)][(int)(data->pos_x)] == '1')
	{
		if (game->map
			[(int)(data->pos_y - COLL_RAD)][(int)(data->pos_x)] != '1')
			data->pos_y -= COLL_RAD;
	}
}
