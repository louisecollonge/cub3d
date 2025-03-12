/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:14:20 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/25 17:14:21 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!lst || !f)
		return ;
	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}

/* void	f(void *content)
{
	char	*str = (char *)content;
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

void	ft_lstfree(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

int	main(void)
{
	t_list	*lst = ft_lstnew(ft_strdup("Hello"));
	t_list	*lst2 = ft_lstnew(ft_strdup("world"));
	t_list	*lst3 = ft_lstnew(ft_strdup("!!!"));
	ft_lstadd_back(&lst, lst2);
	ft_lstadd_back(&lst, lst3);

	t_list	*tmp = lst;
	while (tmp)
	{
		printf("%s ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("\nBecomes :\n");
	
	ft_lstiter(lst, f);
	tmp = lst;
	while (tmp)
	{
		printf("%s ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");

	ft_lstfree(&lst);
	return (0);
} */
