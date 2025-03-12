/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:42:03 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/24 11:49:37 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	j = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	while (dst[i])
		i++;
	while (src[j] && i < (size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}

/* int	main(void)
{
	char	dst[100] = "Hello ";
	char	dst2[100] = "Hello ";
	char	*src = "world !";
	size_t	size = 14;
	size_t	r = strlcat(dst, src, size);
	size_t	r2 = ft_strlcat(dst2, src, size);

	printf ("\n_______________STRLCAT____________________\n");
	printf ("Strlcat : %zu, size : %zu\n", r, size);
	if (size < r + 1)
		printf ("String truncated, not fully concatenated : ");
	else 
		printf ("String fully concatenated : ");
	printf ("\"%s\"\n\n", dst);
	
	printf ("____________FT_STRLCAT____________________\n");
	printf ("Ft_strlcat : %zu, size : %zu\n", r2, size);
		if (size < r2 + 1)
		printf ("String truncated, not fully concatenated : ");
	else 
		printf ("String fully concatenated : ");
	printf ("\"%s\"\n\n", dst2);
	
	return 0;
} */
