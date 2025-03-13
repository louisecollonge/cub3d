/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:15:51 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/13 10:54:00 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	error(char *s, int fd)
{
	printf(BOLDRED "Error\n" RESET);
	printf(RED "%s\n" RESET, s);
	if (fd != -1)
		close(fd);
	exit(EXIT_FAILURE);
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
