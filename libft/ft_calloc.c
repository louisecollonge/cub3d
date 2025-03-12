/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:43:18 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/24 10:48:03 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*data;

	if (size != 0 && nmemb > __SIZE_MAX__ / size)
		return (NULL);
	data = malloc (nmemb * size);
	if (data == NULL)
		return (NULL);
	ft_bzero(data, nmemb * size);
	return (data);
}

/* int	main(void)
{
	size_t		nmemb;
	size_t		size;
	char	*data;

	nmemb = 9;
	size = 0;
	data = ft_calloc(nmemb, size);
	if (data == NULL)
	{
		printf ("Allocation failed.");
		free(data);
		return 0;
	}
	printf ("Allocation succeeded.");
	free (data);
	return 0;
} */
