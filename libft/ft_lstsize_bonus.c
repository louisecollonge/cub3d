/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:11:31 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/25 11:15:39 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nb;

	nb = 0;
	while (lst)
	{
		lst = lst->next;
		nb++;
	}
	return (nb);
}

/* void	ft_free_lst(t_list *lst)
{
	t_list	*tmp;

	while(lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

int	main(void)
{
	t_list	*lst;
	t_list	*new_elt;
	t_list	*another_new_elt;

	lst = ft_lstnew("Old element");
	new_elt = ft_lstnew("New element");
	ft_lstadd_front(&lst, new_elt);
	another_new_elt = ft_lstnew("Another new element");
	ft_lstadd_front(&lst, another_new_elt);

	printf("Nb of elts : %d\n", ft_lstsize(lst));
	ft_free_lst(lst);
	return (0);
} */
