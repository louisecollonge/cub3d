/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:23:01 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/18 20:09:02 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	main(int ac, char **av)
{
	t_game			game;
	t_data			*data;
	t_render_data	render_data;
	(void)ac;
	(void)av;
	//(void)game;
	data = parse_args(ac, av);
	init_game(&game, data);
	init_render_data(&game, &render_data);
	if (render_loop(&game, &render_data) == EXIT_FAILURE)
	{
		printf("renderloop error\n");
		cleanup(data);
		mlx_terminate(game.mlx);
		return (EXIT_FAILURE);
	}
	my_mlx_close(&game);
	printf("here\n");
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
