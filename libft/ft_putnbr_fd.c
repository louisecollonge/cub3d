/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:09:33 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/24 10:46:16 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	nbre;

	nbre = nb;
	if (nbre < 0)
	{
		write (fd, "-", 1);
		nbre = -nbre;
	}
	if (nbre > 9)
	{
		ft_putnbr_fd(nbre / 10, fd);
		ft_putnbr_fd(nbre % 10, fd);
	}
	else
	{
		ft_putchar_fd(nbre + '0', fd);
	}
}

/* int	main(void)
{
	int	nb;
	int	fd;

	nb = -142;
	fd = 1;
	ft_putnbr_fd(nb, fd);
	return (0);
} */
