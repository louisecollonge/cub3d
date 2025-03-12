/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:13:20 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/24 11:37:55 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/* int	main(void)
{
	const char	*s = "Hello !";
	char	*dup;

	dup = ft_strdup(s);
	printf ("Original string : %s\n", s);
	printf ("After ft_strdup : %s\n", dup);
	printf ("After strdup    : %s\n", strdup(s));
	free(dup);
	return (0);
} */
