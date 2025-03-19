/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:03:25 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/19 18:24:36 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	vertical_line(mlx_image_t *img, int x, t_vertical vert, uint32_t color)
{
	int			y;

	if (x < 0 || x >= (int)img->width)
		return;
	if (vert.draw_start < 0)
		vert.draw_start = 0;
	if (vert.draw_end >= (int)img->height)
		vert.draw_end = img->height - 1;

	y = vert.draw_start;
	while (y <= vert.draw_end)
	{
		my_mlx_pixel_put(img, x, y, color);
		y++;
	}
}