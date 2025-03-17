/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:23:01 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/17 22:03:02 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;
	t_data	*data;
	(void)ac;
	(void)av;
	//(void)game;
	// data = parse_args(ac, av);
	data = NULL;
	init_game(&game, data);
	if (render_loop(&game) == EXIT_FAILURE)
	{
		// cleanup(data);
		return (EXIT_FAILURE);
	}
	// cleanup(data);
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
