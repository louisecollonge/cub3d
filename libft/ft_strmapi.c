/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:14:50 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/24 19:06:41 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	i = 0;
	new_str = malloc(ft_strlen(s) + 1);
	if (new_str == NULL)
		return (NULL);
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/* char	ft_f(unsigned int i, char c)
{
	c++;
	i = 0;
	return (c);
}

int	main(void)
{
	const char	*str = "abc012";
	char		*result = ft_strmapi(str, ft_f);
	printf ("Before : %s\nAfter : %s\n", str, result);
	free(result);
	return (0);
} */
