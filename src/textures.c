/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:15:33 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/21 19:53:00 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	texture_error(char *str, t_data *data, t_game *game)
{
	mlx_terminate(game->mlx);
	error(str, data, NULL, NULL);
}

TEX	**load_textures(t_game *game, t_data *data)
{
	TEX	**tab;

	tab = malloc(sizeof(TEX *) * 4);
	if (!tab)
		texture_error("Malloc failure", data, game);
	tab[0] = mlx_load_png(data->no);
	if (!tab[0])
		texture_error("North texture cannot be loaded", data, game);
	tab[1] = mlx_load_png(data->so);
	if (!tab[1])
		texture_error("South texture cannot be loaded", data, game);
	tab[2] = mlx_load_png(data->we);
	if (!tab[2])
		texture_error("West texture cannot be loaded", data, game);
	tab[3] = mlx_load_png(data->ea);
	if (!tab[3])
		texture_error("East texture cannot be loaded", data, game);
	return (tab);
}
