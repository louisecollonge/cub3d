/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:15:51 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/17 21:08:24 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	print_tab(char **tab) //debug
{
	int	i = 0;

	while(tab[i])
		printf("%s\n", tab[i++]);
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
		free(data->floor); //! cause invalid free et je ne sais pas pourquoi
	if (data->ceiling)
		free(data->ceiling);
	//! faut-il free ou close les textures ?
	if (data)
		free(data);
}

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

int	tab_line_nb(char **tab)
{
	int	i;

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
