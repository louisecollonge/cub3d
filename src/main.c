/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:23:01 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/14 18:44:48 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;
	t_data	*data;

	(void)game;
	data = parse_args(ac, av);
	// init_game(&game);
	// mlx_loop(game.mlx);
	cleanup(data);
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
