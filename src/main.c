/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:23:01 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/26 16:31:48 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	main(int ac, char **av)
{
	t_game			game;
	t_data			*data;
	t_render_data	render_data;
	t_ray_data		ray_data;
	t_minimap		minimap;

	data = parse_args(ac, av);
	init_game(&game, data, &minimap);
	init_render_data(&game, &render_data);
	init_minimap_data(&game, &minimap);
	ray_data.game = &game;
	ray_data.render_data = &render_data;
	ray_data.minimap = &minimap;
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_close_hook(game.mlx, &my_closehook, &game);
	mlx_loop_hook(game.mlx, render_loop, &ray_data);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	my_mlx_close(&game);
	return (0);
}
