/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:15:22 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/19 19:15:16 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	render_loop(t_game *game, t_render_data *render_data)
{
	if (!game->img)
	{
		game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
		if (!game->img)
		{
			mlx_terminate(game->mlx);
			return (EXIT_FAILURE);
		}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	}
	render_data->current_time = mlx_get_time() / 1000.0; // convert to seconds
	render_data->frame_time = render_data->current_time - render_data->old_time;
	render_data->old_time = render_data->current_time;

	render_data->move_speed = render_data->frame_time * 5.0;
	render_data->rot_speed = render_data->frame_time * 3.0;

	update_keys(game, render_data, render_data->move_speed, render_data->rot_speed);
	clear_image(game->img);
	raycast(game, render_data);

	return (0);
}

/*
raycasting :
- lancer rayons a partir de la position du joueur
- detecter collisions avec murs
- dessiner murs avec texture et hauteur
*/
