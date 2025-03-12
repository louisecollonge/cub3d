/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:42:18 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/25 11:27:16 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
	t_list	*new;
	t_list	*newest;
	char	*content = " !";
	
	lst = ft_lstnew(content);
	
	content = " World";
	new = ft_lstnew(content);
	ft_lstadd_front(&lst, new);
	
	content = "Hello";
	newest = ft_lstnew(content);
	ft_lstadd_front(&lst, newest);
	
	printf("Last elt : %s\n", (char *)ft_lstlast(lst)->content);
	ft_free_lst(lst);
	return (0);
} */
