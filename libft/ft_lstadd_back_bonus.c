/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:56:58 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/25 12:25:28 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
			ft_lstlast(*lst)->next = new;
	}
}

/* int	main(void)
{
	t_list	*lst = ft_lstnew("Hello ");
	t_list	*new = ft_lstnew("world !");

	ft_lstadd_back(&lst, new);
	printf("Last element  : %s\n", (char *)ft_lstlast(lst)->content);
	return(0);
} */
