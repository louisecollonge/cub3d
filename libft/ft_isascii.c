/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:11:34 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/23 15:10:15 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* int main(void)
{
	int	a;

	a = 127;
	printf("The int '%d' ", a);
	if (ft_isascii(a))
		printf ("is part of the ASCII table.\n");
	else
		printf ("is not part of the ASCII table.\n");
	return (0);
} */
