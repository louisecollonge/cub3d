/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:15:22 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/18 20:37:49 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	render_loop(t_game *game, t_render_data *render_data)
{
	(void)render_data;
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
	clear_image(game->img);


	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_close_hook(game->mlx, &my_closehook, game);


	mlx_loop(game->mlx);
	return (0);
}

/*
raycasting :
- lancer rayons a partir de la position du joueur
- detecter collisions avec murs
- dessiner murs avec texture et hauteur
*/
