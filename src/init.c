/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:15:01 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/20 14:04:49 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*
- charger map .cub
- initialiser MLX42
- charger les textures
*/

void	init_game(t_game *game, t_data *data)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!game->mlx)
	{
		cleanup(data);
		exit(EXIT_FAILURE);
	}
	game->map = data->map_tab;
	game->img = NULL;
	game->data = data;
	game->textures = load_textures(game, data);
}
