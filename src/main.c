/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:23:01 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/10 15:15:24 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;
	
	parsing(ac, av);
	parse_map(av[1], &game);
	init_game(&game);
	mlx_loop(game.mlx);
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