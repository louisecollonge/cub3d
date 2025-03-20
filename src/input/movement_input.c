#include "../../cub3D.h"

void	move_forward(t_game *game, t_render_data *data, double move_speed)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		if(game->map[(int)(data->pos_y)][(int)(data->pos_x + data->dir_x * move_speed)] != '1')
			data->pos_x += data->dir_x * move_speed;
		if(game->map[(int)(data->pos_y + data->dir_y * move_speed)][(int)(data->pos_x)] != '1')
			data->pos_y += data->dir_y * move_speed;
	}

}

void	move_backward(t_game *game, t_render_data *data, double move_speed)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		if (game->map[(int)(data->pos_y)][(int)(data->pos_x - data->dir_x * move_speed)] != '1')
			data->pos_x -= data->dir_x * move_speed;
		if (game->map[(int)(data->pos_y - data->dir_y * move_speed)][(int)(data->pos_x)] != '1')
			data->pos_y -= data->dir_y * move_speed;
	}
}


void move_left(t_game *game, t_render_data *data, double move_speed)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		if(game->map[(int)(data->pos_y)][(int)(data->pos_x - data->plane_x * move_speed)] != '1')
			data->pos_x -= data->plane_x * move_speed;
		if(game->map[(int)(data->pos_y - data->plane_y * move_speed)][(int)(data->pos_x)] != '1')
			data->pos_y -= data->plane_y * move_speed;
	}
}


void move_right(t_game *game, t_render_data *data, double move_speed)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		if(game->map[(int)(data->pos_y)][(int)(data->pos_x + data->plane_x * move_speed)] != '1')
			data->pos_x += data->plane_x * move_speed;
		if(game->map[(int)(data->pos_y + data->plane_y * move_speed)][(int)(data->pos_x)] != '1')
			data->pos_y += data->plane_y * move_speed;
	}
}


