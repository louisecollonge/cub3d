/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:33:16 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/21 19:53:15 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	error(char *s, t_data *data, void *p1, void *p2)
{
	printf(BOLDRED "Error\n" RESET);
	printf(RED "%s\n" RESET, s);
	cleanup(data);
	if (p1)
		free(p1);
	if (p2)
		free(p2);
	exit(EXIT_FAILURE);
}

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	delete_texture_tab(TEX **textures)
{
	int	i;

	i = 0;
	if (textures)
	{
		while (i < 4)
		{
			if (textures[i])
				mlx_delete_texture(textures[i]);
			i++;
		}
		free(textures);
	}
}

void	cleanup(t_data *data)
{
	if (!data)
		return ;
	if (data->fd_map != -1)
		close(data->fd_map);
	if (data->map_string)
		free(data->map_string);
	if (data->map_tab)
		free_tab(data->map_tab);
	if (data->floor)
		free(data->floor);
	if (data->ceiling)
		free(data->ceiling);
	if (data->line)
		free(data->line);
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	free(data);
}
