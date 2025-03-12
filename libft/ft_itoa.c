/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:58:29 by lcollong          #+#    #+#             */
/*   Updated: 2024/11/13 16:43:53 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_nb(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n = -1 * n;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		dig;
	char	*nbr;
	int		var;
	long	nb;

	nb = n;
	var = 0;
	dig = ft_digit_nb(nb);
	nbr = malloc(dig + 1);
	if (nbr == NULL)
		return (NULL);
	nbr[dig] = '\0';
	if (nb < 0)
	{
		nbr[0] = '-';
		nb = -nb;
		var = 1;
	}
	while (dig > var)
	{
		dig--;
		nbr[dig] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (nbr);
}

/* int	main(void)
{
	int		n = -2147483648;
	char	*str_n;

	str_n = ft_itoa(n);
	printf ("%d en chaine : %s\n", n, str_n);
	free (str_n);
	return (0);
} */
