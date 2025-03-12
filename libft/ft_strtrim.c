/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:03:49 by lcollong          #+#    #+#             */
/*   Updated: 2024/11/13 16:41:46 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*trim;

	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_is_set(s1[i], set))
		i++;
	while (ft_is_set(s1[j], set))
		j--;
	trim = ft_substr(s1, i, (j - i + 1));
	return (trim);
}

/* int	main(void)
{
	const char	*s1 = "- -* Hello-world !\t ---";
	const char	*set = "\t*- ";
	char		*trim = ft_strtrim(s1, set);
	printf ("%s\n", trim);
	free(trim);
	return (0);
} */
