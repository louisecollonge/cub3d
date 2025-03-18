/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:15:22 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/18 17:55:26 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	render_loop(t_game *game)
{
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
	{
		mlx_terminate(game->mlx);
		return (EXIT_FAILURE);
	}
	clear_image(game->img);
	draw_line(game->img, (t_coord){200, 200, 0, 400}, 0xFF0000FF);
	vertical_line(game->img, 150, (t_vertical){0, 400}, 0x00FF00FF);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_close_hook(game->mlx, &my_closehook, game);
	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, game->img);
	mlx_terminate(game->mlx);
	return (0);
}

/*
raycasting :
- lancer rayons a partir de la position du joueur
- detecter collisions avec murs
- dessiner murs avec texture et hauteur
*/
