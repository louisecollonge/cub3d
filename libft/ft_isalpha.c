/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:05:04 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/23 15:03:56 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/* int main()
{
	int u;

	u = 'k';
	printf ("The char is '%c' : it ", u);
	if (ft_isalpha(u))
		printf ("is alphabetic.\n");
	else
		printf ("is not alphabetic.\n");
	return (0);
} */
