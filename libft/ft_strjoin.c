/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:43:35 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/24 13:40:19 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*joined_str;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	joined_str = malloc(i + ft_strlen(s2) + 1);
	if (joined_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joined_str[i] = s2[j];
		i++;
		j++;
	}
	joined_str[i] = '\0';
	return (joined_str);
}

/* int	main(void)
{
	const char	s1[100] = "Born T";
	const char	s2[100] = "o Code";
	char	*res = ft_strjoin(s1, s2);
	printf ("%s\n", res);
	free (res);
	return (0);
} */
