/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:15:42 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/18 17:46:54 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	printf("keydata.os_key = %d\n", keydata.os_key);
	printf("keydata.key = %d\n", keydata.key);
	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
}

void	my_closehook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_close_window(game->mlx);
}

/*
Gestion des entrees : fleches, echap, WASD : key_hook
*/
