/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:03:59 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/24 10:29:43 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* int	main(void)
{
	char s1[20] = "Hello world !";
	char s2[20] = "Hello world !";
	int c = 'o';
	size_t n = 5;

	printf ("Official memset : ");
	memset(s1, c, n);
	printf ("%s\n", s1);

	printf("Ft_memset       : ");
	ft_memset(s2, c, n);
	printf ("%s\n", s2);

	return (0);
} */
