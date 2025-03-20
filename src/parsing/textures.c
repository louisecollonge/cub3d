/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:10:30 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/20 14:54:38 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	texture_duplicate_check(t_data *data, t_option option)
{
	if (option == NO && data->no != NULL)
		error("North texture duplicate", data, NULL, NULL);
	else if (option == SO && data->so != NULL)
		error("South texture duplicate", data, NULL, NULL);
	else if (option == WE && data->we != NULL)
		error("West texture duplicate", data, NULL, NULL);
	else if (option == EA && data->ea != NULL)
		error("East texture duplicate", data, NULL, NULL);
}

static char	*full_texture_path(char *line, t_data *data)
{
	char	*path;

	path = ft_strdup(line);
	if (!path)
		error("Malloc failure", data, NULL, NULL);
	return (path);
}

void	parse_texture(char *line, t_data *data, t_option option, int *count)
{
	int	len;

	len = ft_strlen(line);
	line[len - 1] = '\0';
	(*count)++;	
	texture_duplicate_check(data, option);
	if (option == NO)
		data->no = full_texture_path(line, data);
	else if (option == SO)
		data->so = full_texture_path(line, data);
	else if (option == WE)
		data->we = full_texture_path(line, data);
	else if (option == EA)
		data->ea = full_texture_path(line, data);
}
