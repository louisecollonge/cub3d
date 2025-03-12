/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:18:40 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/24 14:18:50 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if ((char)c == '\0')
		return ((char *)&s[i]);
	i--;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/* int	main(void)
{
	int c = 'o';
	const char str[1000] = "Hello World !";
	printf ("String     : %s\n", str);
	printf ("Char       : %c\n", c);
	printf ("Ft_strrchr : %s\n", ft_strrchr(str, c));
	// printf ("Pointeur   : %p\n", ft_strrchr(str, c));
	printf ("Strrchr    : %s\n", strrchr(str, c));
	// printf ("Pointeur   : %p\n", strrchr(str, c));
	return (0);
} */
