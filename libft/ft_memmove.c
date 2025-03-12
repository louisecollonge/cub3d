/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:48:14 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/24 10:06:45 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest <= src)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	return (dest);
}

/* int	main(void)
{
	char	dest[21] = "Bimo le lapin";
	char	*src = dest + 8;
	size_t	n = 4;

	printf ("___________MEMMOVE______________");
	printf ("\nBefore 		 : %s\n", dest);

	memmove(dest, src, n);
	printf ("Memmove after    : %s\n", dest);

	char	dest2[21] = "Bimo le lapin";
	char	*src2 = dest2 + 8;
	ft_memmove(dest2, src2, n);
	printf ("Ft_memmove after : %s\n\n", dest2);

	return 0;
} */
