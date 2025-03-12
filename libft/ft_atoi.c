/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:49:28 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/26 14:39:57 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	i;
	long	nb;
	int		sign;

	i = 0;
	sign = 1;
	nb = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = nb * 10 + (nptr[i++] - '0');
	return (sign * nb);
}

/* int	main(void)
{
	const char	str[] = "-123Hello World 42 !";
	int	a = atoi(str);
	int	f = ft_atoi(str);
	printf ("Official atoi : ");
	printf ("\"%s\" becomes %d\n", str, a);
	printf ("Ft_atoi : ");
	printf ("\"%s\" becomes %d\n", str, f);
	return 0;
} */
