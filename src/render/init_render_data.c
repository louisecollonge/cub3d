/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:25:07 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/21 17:40:55 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void init_render_data(t_game *game, t_render_data *render_data)
{
	set_starting_position(game, render_data);
	set_starting_direction(game, render_data);
	set_camera_plane(render_data);
	init_time(render_data);
}
