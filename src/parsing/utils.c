/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:13:24 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/20 17:20:37 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

bool	end_of_map(t_data *data)
{
	if (data->ceiling_rgb == -1 || data->floor_rgb == -1 || !data->no
		|| !data->so || !data->we || !data->ea)
		return (false);
	else
		return (true);
}

bool	is_orientation(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0)
		return (true);
	else
		return (false);
}

t_option	get_opt(char *line)
{
	t_option	option;

	option = -1;
	if (ft_strncmp(line, "NO ", 3) == 0)
		option = NO;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		option = SO;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		option = WE;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		option = EA;
	return (option);
}

bool	acceptable_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	else
		return (false);
}
