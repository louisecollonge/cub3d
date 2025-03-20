/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:15:42 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/20 14:08:42 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	my_mlx_close(void *param)
{
	//!
	printf("my_mlx_close()\n");
	t_game	*game;

	game = (t_game *)param;
	delete_texture_tab(game->textures);
	mlx_close_window(game->mlx);
	mlx_delete_image(game->mlx, game->img);
	mlx_terminate(game->mlx);
	cleanup(game->data);
	exit(0);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	// //!
	// printf("keydata.os_key = %d\n", keydata.os_key);
	// printf("keydata.key = %d\n", keydata.key);
	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		my_mlx_close(game);
}

void	my_closehook(void *param)
{
	//!
	printf("Close hook\n");
	t_game	*game;

	game = (t_game *)param;
	my_mlx_close(game);
	exit(0);
}

/*
Gestion des entrees : fleches, echap, WASD : key_hook
*/
