/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:22:46 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/23 14:28:16 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

/* int	main(void)
{
	char s[7] = "Hello !";
	size_t	n = 2;
	size_t	i = 0;
	printf ("Before : %s\nAfter :\n", s);
	ft_bzero(s, n);
	while (i < 7)
	{
		printf ("%p = %c\n", &s[i], s[i]);
		i++;
	}
	return (0);
} */
