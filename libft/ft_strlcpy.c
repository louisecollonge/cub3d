/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:23:40 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/24 11:03:29 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

/* int	main(void)
{
	char	dst[100] = "Hello world";
	char	dst2[100] = "Hello world";
	char	*src = "It's-a me, Mario !";
	size_t	size = 19;

	printf ("Strlcpy    : %zu, %s\n", strlcpy(dst, src, size), dst);
	printf ("Ft_strlcpy : %zu, %s\n", ft_strlcpy(dst2, src, size), dst2);
	return 0;
} */
