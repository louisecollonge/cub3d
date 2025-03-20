/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:10:30 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/20 13:19:02 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	texture_duplicate_check(t_data *data, t_option option, char *line,
	int *count)
{
	int	len;

	len = ft_strlen(line);
	line[len - 1] = '\0';
	(*count)++;
	if (option == NO && data->no != NULL)
		error("North texture duplicate", data, NULL, NULL);
	else if (option == SO && data->so != NULL)
		error("South texture duplicate", data, NULL, NULL);
	else if (option == WE && data->we != NULL)
		error("West texture duplicate", data, NULL, NULL);
	else if (option == EA && data->ea != NULL)
		error("East texture duplicate", data, NULL, NULL);
}

void	parse_texture(char *line, t_data *data, t_option option, int *count)
{
	texture_duplicate_check(data, option, line, count);
	if (option == NO)
	{
		data->no = ft_strdup(line);
		if (!data->no)
			error("Malloc failure", data, NULL, NULL);
	}
	else if (option == SO)
	{
		data->so = ft_strdup(line);
		if (!data->so)
			error("Malloc failure", data, NULL, NULL);
	}
	else if (option == WE)
	{
		data->we = ft_strdup(line);
		if (!data->we)
			error("Malloc failure", data, NULL, NULL);
	}
	else if (option == EA)
	{
		data->ea = ft_strdup(line);
		if (!data->ea)
			error("Malloc failure", data, NULL, NULL);
	}
}
