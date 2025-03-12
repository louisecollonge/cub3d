/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:43:06 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/23 18:40:58 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*p_src;
	unsigned char		*p_dest;
	size_t				i;

	i = 0;
	p_dest = dest;
	p_src = src;
	if (p_dest == NULL && p_src == NULL)
		return (NULL);
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char	dest[100] = "HELLO";
	char	*src = "BYEBYE";
	size_t	n = 6;
	
	char	*result_officiel = memcpy(dest, src, n);
	printf ("fn officielle : %s\n", result_officiel);

	char	dest2[100] = "HELLO";
	char	*my_result = ft_memcpy(dest2, src, n);
	printf ("ma fonction   : %s\n", my_result);

	return 0;
} */
