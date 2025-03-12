/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:16:23 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/24 18:34:07 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* void	ft_test(unsigned int i, char *ptr_s)
{
	i = 0;
	*ptr_s = 'a';
}

int	main(void)
{
	char	str[100] = "Hello";
	printf ("\"%s\" becomes ", str);
	ft_striteri(str, ft_test);
	printf ("\"%s\"\n", str);
	return (0);
} */
