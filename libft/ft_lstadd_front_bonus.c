/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:27:46 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/25 10:53:49 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* int	main(void)
{
	t_list	*lst;
	t_list	*new_elt;
	
	lst = ft_lstnew("Old element");
	printf("First element before : %s\n", (char *)lst->content);
	free(lst);
	
	new_elt = ft_lstnew("New element");
	ft_lstadd_front(&lst, new_elt);
	printf("First element after  : %s\n", (char *)lst->content);
	free(new_elt);
	
	return (0);
} */
