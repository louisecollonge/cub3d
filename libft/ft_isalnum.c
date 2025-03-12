/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:06:14 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/23 18:24:46 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
		return (1);
	return (0);
}

/* int main(void)
{
	int u;

	u = '@';
	printf ("The char is '%c' : it ", u);
	if (ft_isalnum(u))
		printf ("is alphanumeric.\n");
	else
		printf ("is not alphanumeric.\n");
	return (0);
} */
