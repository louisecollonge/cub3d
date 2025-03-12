/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:05:06 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/25 19:37:00 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

/* void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst = ft_lstnew(ft_strdup("Hello"));
	t_list	*lst2 = ft_lstnew(ft_strdup(" world"));
	t_list	*lst3 = ft_lstnew(ft_strdup(" !"));
	ft_lstadd_back(&lst, lst2);
	ft_lstadd_back(&lst, lst3);
	t_list	*tmp = lst;

	while (tmp)
	{
		printf("%s ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("\nBecomes :\n");

	ft_lstclear(&lst, del);
	lst = NULL;
	tmp = lst;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	return (0);
} */
