/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:38:03 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/24 13:18:55 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	const char s1[1000] = "Hello";
	const char s2[1000] = "HellO";
	size_t	n = 5;
	
	printf("Ft_strncmp : difference entre \"%s\" et \"%s\" ", s1, s2);
	printf("sur %zu bits = %d\n", n, ft_strncmp(s1, s2, n));
	
	printf("Strncmp    : difference entre \"%s\" et \"%s\" ", s1, s2);
	printf("sur %zu bits = %d\n", n, strncmp(s1, s2, n));
	return (0);
} */
