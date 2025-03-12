/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:38:38 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/24 14:18:25 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/* int	main(void)
{
	const char str[1000] = "Hello World !";
	int	c = 'o';
	printf ("String     : %s\n", str);
	printf ("Char       : %c\n", c);
	printf ("Ft_strchr  : %s\n", ft_strchr(str, c));
	// printf ("Pointeur %p\n", ft_strchr(str, c));
	printf ("Strchr     : %s\n", strchr(str, c));
	// printf ("Pointeur %p\n", ft_strchr(str, c));
	return (0);
} */
