/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:46:30 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/21 19:06:04 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	set_line_vars(t_line_vars *l_vars, t_coord coord)
{
	l_vars->dx = abs(coord.x1 - coord.x0);
	l_vars->dy = abs(coord.y1 - coord.y0);
	if (coord.x0 < coord.x1)
		l_vars->sx = 1;
	else
		l_vars->sx = -1;
	if (coord.y0 < coord.y1)
		l_vars->sy = 1;
	else
		l_vars->sy = -1;
	l_vars->err = l_vars->dx - l_vars->dy;
	l_vars->x_start = coord.x0;
	l_vars->y_start = coord.y0;
}

void	draw_line_loop_helper(t_line_vars *l_vars, t_coord *coord)
{
	l_vars->err2 = 2 * l_vars->err;
	if (l_vars->err2 > -l_vars->dy)
	{
		l_vars->err -= l_vars->dy;
		coord->x0 += l_vars->sx;
	}
	if (l_vars->err2 < l_vars->dx)
	{
		l_vars->err += l_vars->dx;
		coord->y0 += l_vars->sy;
	}
}
