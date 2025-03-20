/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:05:48 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/20 19:53:21 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void update_keys(t_game *game, t_render_data *data, double move_speed, double rot_speed)
{
	move_forward(game, data, move_speed);
	move_backward(game, data, move_speed);
	move_left(game, data, move_speed);
	move_right(game, data, move_speed);
	rotate_right(game, data, rot_speed);
	rotate_left(game, data, rot_speed);
	push_player(game,data);
}