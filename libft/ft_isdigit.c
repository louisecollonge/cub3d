/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:05:09 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/23 15:18:02 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* int main(void)
{
	int a;

	a = 'p';
	printf ("The char '%c' ", a);
	if (ft_isdigit(a))
		printf ("is a digit.\n");
	else
		printf ("is not a digit.\n");
	return (0);
} */
