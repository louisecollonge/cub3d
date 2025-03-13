/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:15:51 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/13 10:24:46 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	error(char *s)
{
	printf(BOLDRED "Error\n" RESET);
	printf(RED "%s\n" RESET, s);
	exit(EXIT_FAILURE);
}
