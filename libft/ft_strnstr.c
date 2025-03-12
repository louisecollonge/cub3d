/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:54:51 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/24 17:43:57 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] != '\0' && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	const char	big[100] = "Hello World !";
	const char	little[100] = "lo";
	size_t	len = 5;
	printf ("Where \"%s\" starts in %zu char of \"%s\" :\n", little, len, big);
	printf ("Ft_strnstr : %s\n", ft_strnstr(big, little, len));
	printf ("Strnstr    : %s\n", strnstr(big, little, len));
	return (0);
} */
