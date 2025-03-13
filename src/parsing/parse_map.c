/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:33:26 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/13 10:27:08 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	parse_map(char *line)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '1' && line[i] != '0' && line[i] != 'N')
			error("Wrong character in map");
		i++;
	}
}
