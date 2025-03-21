/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:03:25 by amonfret          #+#    #+#             */
/*   Updated: 2025/03/21 17:20:29 by amonfret         ###   ########.fr       */
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

static void	stripe_loop(mlx_image_t *img, int x,t_render_data *data, tex *texture)
{
	int				y;

	y = data->draw_start;
	while (y < data->draw_end)
	{
		data->tex_y = (int)data->tex_pos & (texture->height - 1);
		data->tex_pos += data->step;
		data->color = *((uint32_t *)(texture->pixels + (data->tex_y * texture->width + data->tex_x) * 4));
		my_mlx_pixel_put_texture(img, x, y, data->color);
		y++;
	}
}

void	draw_texture_stripe(mlx_image_t *img, int x, t_game *game, t_render_data *render_data)
{
	tex				*texture;

	texture = game->textures[render_data->texture_index];
	render_data->tex_x = (int)(render_data->wall_x * (double)texture->width);
	if (render_data->tex_x < 0)
		render_data->tex_x = 0;
	if (render_data->tex_x >= (int)texture->width)
		render_data->tex_x = texture->width - 1;
	render_data->step = (double)texture->height /
		(render_data->draw_end - render_data->draw_start);
	render_data->tex_pos = (render_data->draw_start - HEIGHT / 2 +
		(render_data->draw_end - render_data->draw_start) / 2.0) * render_data->step;
	stripe_loop(img, x, render_data, texture);

}