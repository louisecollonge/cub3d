/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:23:01 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/20 13:44:13 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	main(int ac, char **av)
{
	t_game			game;
	t_data			*data;
	t_render_data	render_data;
	t_ray_data		ray_data;

	data = parse_args(ac, av);
	init_game(&game, data); //contains texture loading
	init_render_data(&game, &render_data);
	// if (render_loop(&game, &render_data) == EXIT_FAILURE)
	// {
	// 	printf("renderloop error\n");
	// 	cleanup(data);
	// 	mlx_terminate(game.mlx);
	// 	return (EXIT_FAILURE);
	// }
	ray_data.game = &game;
	ray_data.render_data = &render_data;

	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_close_hook(game.mlx, &my_closehook, &game);

	mlx_loop_hook(game.mlx, render_loop, &ray_data);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	my_mlx_close(&game);
	printf(GREEN "finished main()\n" RESET); //debug
	return (0);
}


/*
Fonctions autorisees :

open, close, read
write
printf
perror, strerror
exit

toutes les fns de la lib math
toutes les fns de la MLX

*/
