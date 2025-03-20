/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:15:33 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/20 16:11:36 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*
charger les textures
*/


static void	texture_error(char *str, t_data *data, t_game *game)
{
	mlx_terminate(game->mlx);
	error(str, data, NULL, NULL);
}

tex	**load_textures(t_game *game, t_data *data)
{
	tex	**tab;

	tab = malloc(sizeof(tex *) * 4); //4 murs
	if (!tab)
		texture_error("Malloc failure", data, game);
	// printf(YELLOW "%s\n" RESET, data->no); //debug
	tab[0] = mlx_load_png(data->no);
	if (!tab[0])
		texture_error("North texture cannot be loaded", data, game);
	// printf(YELLOW "%s\n" RESET,data->so); //debug
	tab[1] = mlx_load_png(data->so);
	if (!tab[1])
		texture_error("South texture cannot be loaded", data, game);
	// printf(YELLOW "%s\n" RESET,data->we); //debug
	tab[2] = mlx_load_png(data->we);
	if (!tab[2])
		texture_error("West texture cannot be loaded", data, game);
	// printf(YELLOW "%s\n" RESET,data->ea); //debug
	tab[3] = mlx_load_png(data->ea);
	if (!tab[3])
		texture_error("Eest texture cannot be loaded", data, game);
	return (tab);
}
