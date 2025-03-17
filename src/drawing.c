/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:04:34 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/17 22:04:37 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	set_line_vars(t_line_vars *l_vars, t_coord coord)
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

void	my_mlx_pixel_put(mlx_image_t *img, int x, int y, uint32_t color)
{
	uint8_t	*pixel;

	if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
		return ;
	pixel = &img->pixels[(y * img->width + x) * 4];
	pixel[0] = (color >> 24) & 0xFF;
	pixel[1] = (color >> 16) & 0xFF;
	pixel[2] = (color >> 8) & 0xFF;
	pixel[3] = color & 0xFF;
}

void	draw_line(mlx_image_t *img, t_coord coord, uint32_t color)
{
	t_line_vars	l_vars;

	set_line_vars(&l_vars, coord);
	while (1)
	{
		if (coord.x0 >= 0 && coord.x0 < (int)img->width
			&& coord.y0 >= 0 && coord.y0 < (int)img->height)
			my_mlx_pixel_put(img, coord.x0, coord.y0, color);
		if (coord.x0 == coord.x1 && coord.y0 == coord.y1)
			break ;
		draw_line_loop_helper(&l_vars, &coord);
	}
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

void	clear_image(mlx_image_t *img)
{
	size_t	i;
	size_t	total_pixels;

	total_pixels = img->width * img->height;
	i = 0;
	while (i < total_pixels)
	{
		img->pixels[i * 4 + 0] = 0;
		img->pixels[i * 4 + 1] = 0;
		img->pixels[i * 4 + 2] = 0;
		img->pixels[i * 4 + 3] = 255;
		i++;
	}
}
