/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:20:21 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/20 17:21:16 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

bool	space(char **tab, size_t x, size_t y)
{
	if (x >= 1 && tab[x - 1][y])
	{
		if (!(tab[x - 1][y] == '\t' || tab[x - 1][y] == ' '
			|| tab[x - 1][y] == '1' || !tab[x - 1][y]))
			return (false);
	}
	if (y >= 1 && tab[x][y - 1])
	{
		if (!(tab[x][y - 1] == '\t' || tab[x][y - 1] == ' '
			|| tab[x][y - 1] == '1' || !tab[x][y - 1]))
			return (false);
	}
	if (tab[x][y + 1])
	{
		if (!(tab[x][y + 1] == '\t' || tab[x][y + 1] == ' '
			|| tab[x][y + 1] == '1' || !tab[x][y + 1]))
			return (false);
	}
	if (tab[x + 1][y])
	{
		if (!(tab[x + 1][y] == '\t' || tab[x + 1][y] == ' '
			|| tab[x + 1][y] == '1' || !tab[x + 1][y]))
			return (false);
	}
	return (true);
}

bool	zero(char **tab, size_t x, size_t y)
{
	if ((x - 1) >= 0 && acceptable_char(tab[x - 1][y]) == false)
		return (false);
	if (y == 0)
		return (false);
	if ((y - 1) >= 0 && acceptable_char(tab[x][y - 1]) == false)
		return (false);
	if ((y + 1) >= ft_strlen(tab[x]))
	{
		if (acceptable_char(tab[x][y + 1]) == false)
			return (false);
	}
	if ((x + 1) >= tab_line_nb(tab))
	{
		if (acceptable_char(tab[x + 1][y]) == false)
			return (false);
	}
	return (true);
}
