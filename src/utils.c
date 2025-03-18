/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:15:51 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/18 16:34:09 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	print_tab(char **tab) //debug
{
	int	i = 0;

	while (tab[i])
		printf("%s\n", tab[i++]);
}

size_t	tab_line_nb(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	c;

	c = n;
	i = 0;
	while (src[i] && n >= 1)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	while (i < c)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
