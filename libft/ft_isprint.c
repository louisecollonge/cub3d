/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:49:12 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/23 15:23:43 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* int	main(void)
{
	int c;

	c = '\t';
	printf ("The char '%c' ", c);
	if (ft_isprint(c))
		printf ("is printable.\n");
	else
		printf ("is not printable.\n");
	return (0);
} */
