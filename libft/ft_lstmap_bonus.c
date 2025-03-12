/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:24:43 by lcollong          #+#    #+#             */
/*   Updated: 2024/10/26 14:40:27 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elt;

	new_lst = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		new_elt = ft_lstnew(NULL);
		if (!new_elt)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_elt->content = f(lst->content);
		ft_lstadd_back(&new_lst, new_elt);
		lst = lst->next;
	}
	return (new_lst);
}

/* void	*f(void *content)
{
	char	*str = ft_strdup((char *)content);
	int	i = 0;

	if (!str)
		return (NULL);
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list;
	t_list	*list_next;
	t_list	*final_lst;
	t_list	*tmp;

	list = ft_lstnew(ft_strdup("abc-123"));
	list_next = ft_lstnew(ft_strdup("def-456"));
	ft_lstadd_back(&list, list_next);
	final_lst = ft_lstmap(list, f, del);
	tmp = final_lst;
	while (tmp)
	{
		printf ("%s ", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&list, free);
	ft_lstclear(&final_lst, free);
	return (0);
}
 */
